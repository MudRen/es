#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level( 3 );
	set_name( "doctor Wu", "吴医生" );
	set_short( "吴医生" );
	add("id", ({ "wu","healer", "doctor" }) );
	set_long( @LONG
你看到一位身材高瘦、眼睛细小的中年人，这个医生是一位混血儿，他的父
亲是一个来自东方的学者，他从父亲那里学到不少有关草药与治病的知识，
你可以问他有关医疗(heal)的事情，看他是否能给你帮助。你也可以付钱
(pay) 请他帮你看看身体状况。
LONG
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "inquiry", ([
		"heal" : "@@ask_heal"
	]) );
}

void init()
{
	::init();
	add_action("do_cure", "pay");
}

void ask_heal( object player )
{
	tell_object( player, 
		"吴医生微笑著说: 我会在这里开一家医院，请你下次再来。\n");
}

int do_cure(string arg)
{
	string who, type;
	int num, *data;

	if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
		return notify_fail( 
			"付谁？多少钱？\n");
	if( !id(who ) ) return 0;
	if( type != "silver" ) {
		tell_room( environment(), 
			"吴医生说道: 对不起，我只收银币。\n" ,
			this_object() );
		return 1;
	}
	if( !this_player()->debit(type, num) ) 
	        return notify_fail( "你没有那麽多银币。\n");
	if( !data = this_player()->query("conditions/sick") ) {
		write("吴医生上上下下地打量著你，说: 你身体很好, 并没有生病。\n");
			return 1;
	}
	if( num < 50 + 10*data[1]*data[2]/data[0] ) {
		write("吴医生上上下下地打量著你，摇一摇头，把钱退还给你。\n");
		this_player()->credit(type, num);
		return 1;
	} else {
		write("经过一番仔细的检查，吴医生笑著说: 你的病打个针就好了。\n");
		write("吴医生取出一个针筒, 在你臂上打了一针。\n");
		SICK->remove_effect(this_player());
	}
	return 1;
}
