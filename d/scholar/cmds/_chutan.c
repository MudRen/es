//#pragma save_binary

#include <mudlib.h>
#include <daemons.h>
#include <conditions.h>

inherit DAEMON;

int help();

void create()
{
	seteuid(getuid());
}

varargs void disturbed(object player, object victim, int flag)
{
	string stat;
	int some_stat, n, fp;

	if (!player->query_attacker()) return;
	switch( n = random(3) ) {
		case 0: stat = "strength";		break;
		case 1: stat = "dexterity";		break;
		case 2: stat = "constitution";	break;
	}

	some_stat = (int)player->query_perm_stat(stat);
    some_stat = some_stat * 2 / 3;

	call_other(EXERCISING, "remove_effect", player, 0);
	tell_object( player, set_color( 
		"\n你感到胸口一阵气血翻涌，眼前金星乱冒，看来是走火入魔的徵兆 ....\n"+
		( some_stat > 1 ? "\n你的" + to_chinese(stat) + "降低了！\n":"")+
		"\n你深深吸进一口气，勉强压制住体内四处乱窜的真气，站了起来 ....\n\n", "HIY", player) );
	tell_room( environment(player), 
		player->query("c_name") + "受到了惊扰，整个人一阵颤抖，脸上痛苦地扭曲著 ....\n\n"
		+ player->query("c_name") + "深深地吸了一口气，摇摇晃晃地站了起来 ....\n\n" ,
		player );

	// skip all NPCs, for stop system hole, added by Kyoko.
	if( victim && living(victim) && !victim->query("npc") && !flag ) {
		fp = (int)player->query("force_points") - (int)victim->query("force_points");
		if( fp > 0 ) {
			if( !victim->query("force_points") ) fp += 200;
			victim->set("last_attacker", player);
			victim->receive_damage(fp/3);
			tell_object( victim, 
				"\n你感到" + player->query("c_name") + "身上传来一股巨力，震得你胸口一阵气血翻涌！\n\n");
		}
	}

	if( some_stat < 1 ) player->receive_damage((int)player->query("max_hp"), 0);
	else {
		STATS_D->change_perm_stat(player, stat, some_stat);
		CONFUSED->apply_effect(player, (int)player->query("force_points")/5, 3);
	}
}

int cmd_chutan(string arg)
{
	int skill, max;
	object me;

	if( arg ) return help();
	me = this_player();
	skill = (int)me->query_skill("chutan");
	if( !skill ) return notify_fail("你没有学过修习过聚丹功\的心法 ....。\n");

    if( me->query("conditions/exercising") )
        return notify_fail("你刚运功\不久，体内充满真气，不适合操之过急马上再练。\n");

    if( me->query_attackers() )
         return notify_fail("你不能在战斗聚丹，小心走火入魔 !!\n");

   if( me->query_temp("meditating")) return notify_fail("你正在打坐，无法聚丹...。\n");
	if( me->query("stop_heal") )
         return notify_fail("你现在不能运功\。\n");

	max = skill / 3;
    max = max/2 + random(max/2) + (int)me->query("force_effect");
	if( max < 1 ) max = 1;
	if( max > 35 ) max = 35;
	write("你宽袍缓带，盘腿而坐，眼观鼻，鼻观心，一股内息开始在你的体内流动 ...。\n");
	tell_room( environment(me), 
		me->query("c_name")+ "盘腿坐了下来，闭目凝神，开始聚气。\n", me );
	me->set_temp("exercising", base_name(this_object()));
	EXERCISING->apply_effect(me, max, 5*max-random(skill/5));
	return 1;
}

int help()
{
    write(@HELP
指令格式： chutan

这个命令让你放松你的身体，集中精神产生内力，因为内力很难在生故在公众场所
聚丹是相当危险的。假如你在聚丹时被打扰则你的基本属性将会从原来的值下降，
也可能产生其他一些不良的影响。
HELP
	);
    return 1;
}
