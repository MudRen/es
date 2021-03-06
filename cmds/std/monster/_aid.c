#include <mudlib.h>

inherit DAEMON;

int cmd_aid(string arg)
{
	object dest;
	int hp, max_hp, skill, chinese_mode;

	chinese_mode = can_read_chinese();
	if( !arg || arg=="" || !(dest = present(arg, environment(this_player()))) )
		return notify_fail( "你要对谁施行急救？\n");

	if( !living(dest) ) return notify_fail("那个「东西」不需要急救。\n");

//	if( dest==this_player() ) return notify_fail( chinese_mode?
//		"你不能对自己施行急救。\n": "You can't aid yourself.\n" );

	if( dest->query("ghost") ) return notify_fail(
		"太迟了 .... "+dest->query("c_name")+"已经死了。\n");

	if( dest->query_temp("aided") ) return notify_fail(
		dest->query("c_name") + "已经被急救过了。\n");

	hp = (int)dest->query( "hit_points" );
	max_hp = (int)dest->query( "max_hp" );
	if( hp==max_hp ) return notify_fail(
		dest->query("c_name") + "并没有受伤。\n" );

	if( hp > max_hp/6 ) return notify_fail(
		dest->query("c_name") + "的伤势还没有严重到需要急救的地步。\n" );

	skill = (int)this_player()->query_skill( "first-aid");
	if( !skill ) return notify_fail("你并没有学过急救的技能。\n");

	write("你对" + dest->query("c_name") + "进行急救 ....\n");
	tell_object( dest, this_player()->query("c_name") + "对你进行急救 .... 你觉得好多了！\n");
	tell_room( environment(this_player()), this_player()->query("c_name") + "对" + dest->query("c_name") + "进行急救 ....\n",
		({ this_player(), dest }) );
	if( dest!=this_player() ) this_player()->add( "alignment", 25 );
	dest->receive_healing( skill/2 + random(skill/2) );
	dest->set_temp( "aided", 1 );
	this_player()->receive_experience( skill );
	call_out( "remove_aided", 300, dest );
    return 1;
}

void remove_aided(object player)
{
	if( player ) player->set_temp("aided", 0);
}

int help()
{
    write(can_read_chinese()?
    @C_HELP
指令格式: aid <某人>

这个指令让你对某个人物( 或 NPC )施行急救，有关急救的细节与限制请参
考 help first-aid。
C_HELP
    :@HELP
Usage: aid <someone>

This command enables you to perform first aid to another player or
NPC. For more information about first aid, see help first_aid.
HELP
	);
    return 1;
}
