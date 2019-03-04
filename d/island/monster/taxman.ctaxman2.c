#include <mudlib.h>
#include <body.h>

//inherit "/std/coinvalue";
inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	add( "id", ({ "elf","taxman", "shilufu"}) );
 set_name( "elf taxman shilufu" , "����˰�� ϣ¶ܽ");
		set_short("����˰�� ϣ¶ܽ");
	        set_long(@LONG
���ǵ��������ľ��飬��Ϊ��ʮ�����ɣ����Դ���ί�����������
�������ֺõĹ����������ؼ�����������˰�������Ͷ�����Ӵ��
�Թ����Ŀ�ͷ��
LONG
	);
	set( "race", "elf" );
	set( "gender", "female" );
	set_perm_stat( "str", 30 );
	set_perm_stat( "dex", 30 );
	set( "time_to_heal", 5 );
	set( "unarmed",100 );
	set( "wimpy" , 400 );
	set( "max_hp" , 420 );
	set( "hit_points" , 420 );
	set_skill( "dodge", 100 );
	set_natural_armor( 100, 40 );
	set_natural_weapon( 70, 20, 65 );
	set( "alignmnet", 500 );
	set( "wealth/gold", 150 );
//	set( "forgetful" , 1 );
	set( "player_invisible" ,1 );
}


do_kill(string arg)
{   
  if(arg=="elf"||arg=="taxman"||arg=="shilufu")
  {
    call_out("do_inv",5);
    return 0;
  }
  
  return 0;    
  }
  
string c_call(object who)
{
	if ((string)who->query("gender") == "female")
	return (!who->query("spouse")) ? "С��" : "̫̫" ;
	else
	return (!who->query("spouse")) ? "˧��" : "����" ;
}

void check_wealth(object ob)
{
	string *types,name;
	mapping money, bank;
	object env;
	int i, total;
	
        name = (string)ob->query("c_name");
	env = environment();
	if( !env || !present(ob, env) ) return;
	if(wizardp(ob) )
	 {
		tell_room( env, 
		"\nϣ¶ܽ���˸���: ��������, "+name+"���\n\n" ,
		this_object() );
		return;
	}
	money = (mapping)ob->query("wealth");
	if( !money ) money = ([]);
	bank = (mapping)ob->query("bank_balance");
	if( !bank ) bank = ([]);

	types = keys(money);
	for( i=0; i<sizeof(types); i++ ) 
		total += money[types[i]] * coinvalue( types[i] );
	types = keys(bank);
	for( i=0; i<sizeof(types); i++ )
		total += bank[types[i]] * coinvalue( types[i] );

	if( total > (int)ob->query_level() * MAX_MONEY_EACH_LEVEL ) {
	        
                	
		tell_room( env,@LONG
��ǰ��һ�󲨶�������˰�� ϣ¶ܽ����ӰͻȻ���ֳ�����		
LONG
    );
    
                set("player_invisible",0);
		tell_room(env,"ϣ¶ܽ΢Ц˵������"+c_call(ob)+"����ץ����ࡣ���㽨�辭�Ѱɣ���\n\n",
		this_object() );
		
		types = keys(money);
		for( i=0; i<sizeof(types); i++ ) 
		{	money[types[i]] /= 3;
		        money[types[i]] *= 2;
		}        	
		ob->set( "wealth", money );
		types = keys(bank);
		for( i=0; i<sizeof(types); i++ )
		{
			bank[types[i]] /= 3;
			bank[types[i]] *= 2;
		}
        	ob->set( "bank_balance", bank );

		tell_object( ob, 
	"�����������Ǯ�����Լ������ò�����˼���Զ��Է��ľ��������֮һ��Ǯ\n");
	      call_out( "do_inv" , 10 );
	} 
	else {
	tell_room( env, 
		"ϣ¶ܽЦ��˵: " + ((string)ob->query("c_name"))[0..1]+c_call(ob)+"���������۹����\n",
		this_object() );
		
		}
	return;
}
void do_inv()
{
   tell_room(environment(),"����˰�� ϣ¶ܽ����Ӱ�����ĵ�ȥ���������ǰ��ʧ\n");
   set("player_invisible",1);
   return;
}
    
 void init()
{
	object ob;
	npc::init();
	
	add_action("do_kill","kill");
	if( !(ob= this_player()) || !userp(ob) ) return;
	call_out( "check_wealth", 0, ob );
}   
