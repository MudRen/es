#include <mudlib.h>
#include <body.h>

inherit COINVALUE;
inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name("Bikabal", "˰���");
	add( "id", ({"taxman", "man"}) );
	set_short("˰��ٱϿ���");
	set_long(@C_LONG
�Ͽ����Ǹ����ˡ�������������һ�㣬������������˰��ٻ�������
����ȫ����Ǯ���Ͽ���ֻ������ʵ��̫��Ǯʱ�Ż�������˰��
C_LONG
	);
	set( "race", "halfling" );
	set( "gender", "male" );
	set( "no_attack", 1 );
}

void init()
{
	object ob;

   npc::init();
	if( !( ob= this_player()) || !userp(ob) ) return;
	call_out( "check_wealth", 0, ob );
}

void check_wealth(object ob)
{
	string *types;
	mapping money, bank;
	int i, total;

	if( !ob || !this_object() ) return;
	if( member_group(geteuid(ob), "admin") ) {
		command("bow "+(string)ob->query("name"));
		command("say �װ��Ĵ���, ��ӭ����!!\n");
		command("bow "+(string)ob->query("name"));
		return;
	} else command( "say ��! "+ob->query("c_name") + ".\n" );
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
		command( "say Ŷ����!!����ԭ���ǽ�ţ���Ĵ�����ѽ!!!!\n" );
		command( "say ��, ����һЩ������ƶ������!!!!!\n" );
		
		types = keys(money);
		for( i=0; i<sizeof(types); i++ ) 
			money[types[i]] /= 2;
		ob->set( "wealth", money );
		types = keys(bank);
		for( i=0; i<sizeof(types); i++ )
			bank[types[i]] /= 2;
		ob->set( "bank_balance", bank );

		tell_object( ob, "˰��ٴ������Ϻ������ʻ�������һ���Ǯ��\n");
	}
}
