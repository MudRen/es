#include <mudlib.h>

#define PETDIR "/d/noden/farwind/pet/pet_"

inherit ROOM;

#define PRICE ({ 0, 1500, 2000, 1400, 1400, 1800, 3500 })
#define PETS ({ "none", "cat", "dog", "bird", "rat", "pig", "dino" })
#define AMOUNT ({ 0, 4, 4, 5, 5, 3, 2, })
void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "��ȳ���ר����" );
        set_long(@LONG
������һ�ҳ���꣬һ���ž����������ӵĳ����������������⿴�����
һЩ�ȽϹԵĳ����棬�����ĺ�ϲ��������Բο�ǽ�ϵļ�Ŀ��(menu)�پ���
Ҫ��Ҫ�����ؼң�������������������ͬʱ����Ҳ������һ�(looking)ʧ��
�ĳ��
LONG
        );

        set("item_func",(["menu": "msg_menu", ]));
        set("exits", ([
            "south" : "/d/noden/farwind/bazz3",
        ]) );
        set( "amount", AMOUNT );
        reset();
}

void init()
{
		add_action( "call_pet", "looking");
        add_action( "buy_pet", "buy");
        add_action( "sell_pet", "sell");
}

int msg_menu()
{
	int *amount;
	amount = this_object()->query("amount");

write(
"ǽ�Ϲ���һ�ſɰ��ĳ�������������ע����ÿ�ֳ�������Ժͼ�Ǯ ��\n\n"
"                      ��ȳ���ר����\n"
"    ����������������������������������������������������\n"
"    ��  ����è  (pet cat)     "+PRICE[1]+" ����    ���� "+amount[1]+" ֻ  ��\n"
"    ��  �󱿹�  (pet dog)     "+PRICE[2]+" ����    ���� "+amount[2]+" ֻ  ��\n"
"    ��  ������  (pet bird)    "+PRICE[3]+" ����    ���� "+amount[3]+" ֻ  ��\n"
"    ��  ������  (pet rat)     "+PRICE[4]+" ����    ���� "+amount[4]+" ֻ  ��\n"
"    ��  ������  (mini pig)    "+PRICE[5]+" ����    ���� "+amount[5]+" ֻ  ��\n"
"    ��  С����  (mini dino)   "+PRICE[6]+" ����    ���� "+amount[6]+" ֻ  ��\n"
"    ����������������������������������������������������\n\n"+
"�Уӣ��������м۵�һ���չ�����Ҫ�ĳ���벻Ҫ����ĳ�����ʧ��\n"
	);
	return 1;
}
int call_pet()
{
 	object ob;
 		
 	ob = this_player()->query_temp("now_pet");
	if( !ob )
		return notify_fail("��Աҡҡͷ˵������û�г���.\n");
	if( present(ob, this_object())	) {
		tell_object( this_player(),
            "��Ա˵��: ��ĳ����Ѿ�������, ����ȥ����!\n" );
        return 1;
	}
	tell_object(this_player(),
		"��Ա�ó�һ�����ӣ�����һ�����١�����һ���������û����Ķ������� .\n"
		"ͻȻ��ĳ��ﲻ֪�����������˳�������������ܸ��˵�������ȥ��\n"
		);
	ob->move_player(this_object(),"SNEAK");	
	return 1;
}

int sell_pet(string arg)
{
 	object ob;
 	int i=0, *amount;
 	if( !arg || arg != "pet" )
 		return notify_fail("ָ���ʽ : sell pet (�������).\n");
 		
 	ob = this_player()->query_temp("now_pet");
	if( !ob )
		return notify_fail("��û�г���.\n");
	if( !present(ob, this_object())	) {
		tell_object( this_player(),
            "��Ա˵��: �Բ�����ĳ��ﲻ������, ��ȥ�����һ�����!\n" );
        return 1;
	}

	switch( (string)ob->query("pet_type") ) {
        case "cat"  : i=1;  break;
        case "dog"  : i=2;  break;
        case "bird" : i=3;  break;
        case "rat"  : i=4;  break;
        case "pig"  : i=5;  break;
        case "dino" : i=6;  break;
        default :
          tell_object( this_player(), 
            "��Ա˵��: �Բ��𣬱��겻�չ����ֳ��\n" );
          return 1;
    }

	if( i<1 || i>6 ) return 0;
	
    this_player()->credit("silver", PRICE[i]/2);
    this_player()->set_temp("now_pet", 0);
    ob->remove();
    amount = this_object()->query("amount");
    amount[i]++;
    this_object()->set("amount", amount);
    tell_object(this_player(), 
        "��������ĳ���õ� "+(PRICE[i]/2)+" �����ҡ�\n"
		);
    return 1;
}

int buy_pet(string arg)
{
	object ob;
	int i=0, *amount;

	if( !arg || arg == "" )
		return notify_fail("ָ���ʽ : buy <��������>.\n");
	
	if( this_player()->query_temp("now_pet") )
    	return notify_fail("�Բ���, һ����ֻ����һֻ���\n");
          
	amount = this_object()->query("amount");
	if( !amount )
		return notify_fail("�Բ���, �������еĳ��ﶼ�������ˡ�\n");
          
	switch (arg) {
        case "cat"  : i=1;  break;
        case "dog"  : i=2;  break;
        case "bird" : i=3;  break;
        case "rat"  : i=4;  break;
        case "pig"  : i=5;  break;
        case "dino" : i=6;  break;
        default :
          tell_object( this_player(), 
            "��Ա˵��: �Բ��𣬱���û���� "+arg+" ���ֳ��\n" );
          return 1;
          break;
    }
    if( i<1 || 1>6 ) return 0;
    if( amount[i] < 1 ) {
    	tell_object( this_player(), 
          "��Ա˵��: �Բ��𣬱��� "+arg+" ���ֳ����Ѿ������ˡ�\n" );
        return 1;
    }
    
    if( !this_player()->debit("silver",PRICE[i] ) )
        return notify_fail("��û����������ҡ�\n");

	amount[i]--;
	this_object()->set("amount", amount);
    ob = new( PETDIR+PETS[i] );
    ob->move( this_object() );
    
    this_player()->set_temp("now_pet", ob);
    ob->set_master( this_player() );

    tell_object(this_player(), 
        "��Ա����ĳ��ｻ���㣬Ц��������Ҫ�ú��չ���� !!��\n");
    return 1;
}

void add_amount(string type)
{
	int i=0, *amount;
	
	if( !type || type == "" ) return;
	switch (type) {
        case "cat"  : i=1;  break;
        case "dog"  : i=2;  break;
        case "bird" : i=3;  break;
        case "rat"  : i=4;  break;
        case "pig"  : i=5;  break;
        case "dino" : i=6;  break;
        default : return;
    }
    if( i<1 || i>6 ) return;
    amount = this_object()->query("amount");
    amount[i]++;
    this_object()->set("amount", amount);
}

void reset()
{
	set("amount", AMOUNT );
	::reset();
}
