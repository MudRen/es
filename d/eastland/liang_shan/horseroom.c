#include "takeda.h"

#define HORSEDIR TMONSTER"horse_"

inherit ROOM;

#define PRICE ({ 0, 1500, 2000, 3000 })
#define HORSES ({ "none", "spot_horse", "red_horse", "whitefoot_horse" })
#define AMOUNT ({ 0, 4, 2, 2 })

void create()
{
	::create();
	set_short( "����" );
	set_long(
	"������һ��СС�Ŀյأ����ǵ�ߺ����������䣬����������ƥ\n"
	"�ĳ�Х�������������ɽ�����������У��ɻʸ��������ʿ��衣\n"
	"��ƥ���ȡ��������Ǻ�ˮ����ζ������һ��ȴ������һ�ֳ�������\n"
	"��������Ϣ���ڿյ����룬����һ�Ÿ�ʾ(note)��\n"
	);
	set( "light",1 );
        set_outside("eastland");
        set( "exits", ([
                "west"  : TROOM"path1",    
        ]) );
        set( "objects",([
             "boss" : TMONSTER"huanpo"
             ]));
        set("item_func",(["note": "note_msg", ]));
        set( "amount", AMOUNT );
        reset();
}

void init()
{
        add_action( "buy_horse", "buy");
        add_action( "sell_horse", "sell");
}

int note_msg()
{
	int *amount;
	amount = this_object()->query("amount");

write(
"���Ÿ�ʾ��д����\n\n"
"    �����ṩ������ƥ����Ǯ������ͯ�����ۣ�����Ϊ���е�����\n\n"
"     ����:                    �۸�:\n\n"
"   С����  (spot_horse)     "+PRICE[1]+" ����    ֻʣ "+amount[1]+" ֻ  \n"
"  ��������  (red_horse)     "+PRICE[2]+" ����    ֻʣ "+amount[2]+" ֻ  \n"
"  ̤ѩ����(whitefoot_horse) "+PRICE[3]+" ����    ֻʣ "+amount[3]+" ֻ  \n\n"
"         ����������ps ��������������ƥ���������⣬������԰�۹���\n"                                      
	);
	return 1;
}


int sell_horse(string arg)
{
 	object horse;
 	int i=0, *amount;
 	if( !arg || arg != "horse" ) {
 		return notify_fail("ָ���ʽ : sell horse (�������).\n");
 		                     }
 	horse = this_player()->query_temp("now_mount");
	if( !horse )                 
		return notify_fail("�ϰ�˵��:��������������?\n");
	if( !present(horse, this_object())	) {
		tell_object( this_player(),
            "�ϰ�˵��: û�������ҿ������!\n" );
        return 1;
	}

	switch( (string)horse->query("name") ) {
        case "spot_horse"  : i=1;  break;
        case "red_horse"  : i=2;  break;
        case "whitefoot_horse" : i=3;  break;
        default :
          tell_object( this_player(), 
            "�ϰ�˵��: �Բ��𣬱��겻�����ֶ�����\n" );
          return 1;
    }

	if( i<1 || i>3 ) return 0;
	
    this_player()->credit("silver", PRICE[i]/2);
    this_player()->set_temp("now_mount", 0);
    horse->remove();
    amount = this_object()->query("amount");
    amount[i]++;
    this_object()->set("amount", amount);
    tell_object(this_player(), 
        "������������õ� "+(PRICE[i]/2)+" �����ҡ�\n"
		);
    return 1;
}

int buy_horse(string arg)
{
	object horse;
	int i=0, *amount;

	if( !arg || arg == "" )
		return notify_fail("ָ���ʽ : buy + <�������>.\n");
	
	if( this_player()->query_temp("now_mount") )
    	return notify_fail("�ϰ�ҡͷ˵��: �Բ���, һ����ֻ����һƥ��\n");
          
	amount = this_object()->query("amount");
	if( !amount )
		return notify_fail("�ϰ�Ц��: �Բ���, �������е����������ˡ�\n");
          
	switch (arg) {
        case "spot_horse"  : i=1;  break;
        case "red_horse"  : i=2;  break;
        case "whitefoot_horse" : i=3;  break;
        default :
          tell_object( this_player(), 
            "�ϰ�˵��: �Բ��𣬱���û���� "+arg+" ������\n" );
          return 1;
          break;
    }
    if( i<1 || 1>3 ) return 0;
    if( amount[i] < 1 ) {
    	tell_object( this_player(), 
          "�ϰ�˵��: �Բ��𣬱��� "+arg+" �������Ѿ������ˡ�\n" );
        return 1;
    }
    
    if( !this_player()->debit("silver",PRICE[i] ) )
        return notify_fail("��û����������ҡ�\n");

	amount[i]--;
	this_object()->set("amount", amount);
    horse = new( HORSEDIR+HORSES[i] );
    horse->move( this_object() );
    
      this_player()->set_temp("now_mount", horse);
      horse->set_master( this_player() );

    tell_object(this_player(), 
        "�ϰ�ǣ��һƥ��а���Ц�������´μǵ������ !!����˵�߰ѡ���������\n");
    return 1;
}

void add_amount(string type)
{
	int i=0, *amount;
	
	if( !type || type == "" ) return;
	switch (type) {
        case "spot_horse"  : i=1;  break;
        case "red_horse"  : i=2;  break;
        case "whitefoot_horse" : i=3;  break;
        default : return;
    }
    if( i<1 || i>3 ) return;
    amount = this_object()->query("amount");
    amount[i]++;
    this_object()->set("amount", amount);
}

void reset()
{
	set("amount", AMOUNT );
	::reset();
}
int clean_up() { return 0; }
