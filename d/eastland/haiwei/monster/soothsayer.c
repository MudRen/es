#include <mudlib.h>
#include <stats.h>
#include <races.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "soothsayer", "算命先生" );
	add( "id", ({ "sayer" }) );
	set_short( "算命先生" );
	set_long(@C_LONG
这位算命先生大约四、五十岁，留著两撇八字胡子，你可以问他有关未来
(future)的事，请他指点迷津。
C_LONG
	);
	set( "race", "human" );
	set( "gender", "male" );
	set_natural_weapon( 3, 1, 5 );
	set_natural_armor( 6, 10 );
	set_perm_stat( "dex", 5 );
	set_perm_stat( "kar", 5 );
	set_skill( "dodge", 20 );
	set( "wealth/gold", 5 );
	set( "inquiry", ([
		"future" : 
			"想算命？只要付(pay)我五块金币，我就替你算算。"
	]) );
}

void init()
{
	add_action( "do_fortell", "pay" );
}

int do_fortell(string arg)
{
	string who, type, race;
	int num, age;

	if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
           return notify_fail( 
                   "付谁？多少钱？\n" );
	if( !id(who ) ) return 0;
	if( type != "gold" ) {
           tell_room( environment(), 
               "算命先生说道: 对不起，我只收金币。\n",
			this_object() );
		return 1;
	}
   if( !this_player()->debit(type, num) ) return notify_fail(
           "你没有那麽多金币。\n" );
	if( num < 5 ) {
           write( 
              "算命先生上上下下地打量著你，摇一摇头，把钱退还给你。\n" );
		this_player()->credit(type, num);
		return 1;
	}
	if( this_player()->query_temp("payed_soothsayer") && num >= 1000 ) {
           tell_room( environment(), 
			"算命先生说道: 阁下真是有缘人，小弟有幸认识阁下，真是上辈子修来的福气。\n\n"
                   "算命先生说道: 小弟愿为阁下作法，补回两年阳寿。\n" );
		this_player()->add("dead_count", -1);
		return 1;
	}
	race = this_player()->query("race");
	age = RACE_MASTER(race)->query_natural_life();
	age -= (int)this_player()->query("dead_count") * 2;
	age -= (int)this_player()->query("natural_age");
	age -= (int)this_player()->query_age() / 86400;
	if( age > 0 )
           tell_room( environment(), 
			"算命先生说道: 谢谢，请把你的手掌给我。\n\n"
+ age + " 年阳寿，好自为之吧。\n" );
   else tell_room( environment(), 
		"算命先生说道: 谢谢，请把你的手掌给我。\n\n"
		"算命先生仔细地端详了一会儿，然後捻著胡子说道: 阁下阳寿已尽，请千万\n"
           "    珍重，以免坠入轮回受苦。\n" );
	if( num >=500 ) call_out( "my_special", 6, this_player() );
	return 1;
}

void my_special(object player)
{
	if( !present(player, environment()) ) return;
   tell_object(player, 
		"算命先生压低声音说道: 看来阁下与小弟颇有缘份 .... 如果阁下能再\n"
             "        出 1000 块金币，也许\ ....\n" );
	this_player()->set_temp("payed_soothsayer", 1 );
}
