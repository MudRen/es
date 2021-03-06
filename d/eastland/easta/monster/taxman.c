#include <mudlib.h>
#include <body.h>

inherit COINVALUE;
inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name("taxman neo", "牛万金");
	add( "id", ({"man", "neo"}) );
	set_short("税吏牛万金");
	set_long(@C_LONG
牛万金是若岚城专门负责收税的税吏，他为人不但精明，更有一身
精湛的武功\，没有人知道他到底师承何人，只知道牛万金手底下从来没
有人欠过税。
C_LONG
	);
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 30 );
	set_perm_stat( "dex", 30 );
	set( "time_to_heal", 7 );
	set( "aiming_loc", "vascular" );
	set_skill( "dodge", 100 );
	set_natural_armor( 110, 40 );
	set_natural_weapon( 65, 26, 57 );
	set( "alignmnet", -1000 );
	set( "wealth/gold", 100 );
	set( "moving", 1 );
	set( "speed", 30 );
	set( "patrol", ({ "north", "north", "south", "west", "south", "south",
		"west", "east", "north", "north", "east", "south" }) );
}

void init()
{
	object ob;

	::init();
	if( !(ob= this_player()) || !userp(ob) ) return;
	call_out( "check_wealth", 0, ob );
}
string c_call(object who)
{
	if ((string)who->query("gender") == "female")
	return (!who->query("spouse")) ? "小姐" : "夫人" ;
	else
	return (!who->query("spouse")) ? "大爷" : "老爷" ;
}

void check_wealth(object ob)
{
	string *types;
	mapping money, bank;
	object env;
	int i, total;

	env = environment();
        if (!ob) return;
	if( !env || !present(ob, env) ) return;
	if( member_group(geteuid(ob), "admin") ) {
		tell_room( env, 
			"牛万金恭谨地说道: 辛苦您了, 大神 "+ob->query("c_name")+"。\n\n" ,
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
		tell_room( env, 
			"牛万金说道: 看来这位"+c_call(ob)+"挺阔绰的，替穷苦的百姓纳一些税吧。\n\n" ,
		this_object() );
		
		types = keys(money);
		for( i=0; i<sizeof(types); i++ ) 
			money[types[i]] /= 2;
		ob->set( "wealth", money );
		types = keys(bank);
		for( i=0; i<sizeof(types); i++ )
			bank[types[i]] /= 2;
		ob->set( "bank_balance", bank );

		tell_object( ob, 
			"牛万金不等你回答，直接从你身上和钱庄的户头拿走一半的钱。\n");
	} else tell_room( env, 
		"牛万金说道: " + ((string)ob->query("c_name"))[0..1]+
		c_call(ob)+"，近来可好？\n",
		this_object() );
	return;
}
