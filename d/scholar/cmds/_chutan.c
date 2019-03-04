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
		"\n��е��ؿ�һ����Ѫ��ӿ����ǰ������ð���������߻���ħ������ ....\n"+
		( some_stat > 1 ? "\n���" + to_chinese(stat) + "�����ˣ�\n":"")+
		"\n����������һ��������ǿѹ��ס�����Ĵ��Ҵܵ�������վ������ ....\n\n", "HIY", player) );
	tell_room( environment(player), 
		player->query("c_name") + "�ܵ��˾��ţ�������һ�����������ʹ���Ť���� ....\n\n"
		+ player->query("c_name") + "���������һ������ҡҡ�λε�վ������ ....\n\n" ,
		player );

	// skip all NPCs, for stop system hole, added by Kyoko.
	if( victim && living(victim) && !victim->query("npc") && !flag ) {
		fp = (int)player->query("force_points") - (int)victim->query("force_points");
		if( fp > 0 ) {
			if( !victim->query("force_points") ) fp += 200;
			victim->set("last_attacker", player);
			victim->receive_damage(fp/3);
			tell_object( victim, 
				"\n��е�" + player->query("c_name") + "���ϴ���һ�ɾ�����������ؿ�һ����Ѫ��ӿ��\n\n");
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
	if( !skill ) return notify_fail("��û��ѧ����ϰ���۵���\���ķ� ....��\n");

    if( me->query("conditions/exercising") )
        return notify_fail("����˹�\���ã����ڳ������������ʺϲ�֮��������������\n");

    if( me->query_attackers() )
         return notify_fail("�㲻����ս���۵���С���߻���ħ !!\n");

   if( me->query_temp("meditating")) return notify_fail("�����ڴ������޷��۵�...��\n");
	if( me->query("stop_heal") )
         return notify_fail("�����ڲ����˹�\��\n");

	max = skill / 3;
    max = max/2 + random(max/2) + (int)me->query("force_effect");
	if( max < 1 ) max = 1;
	if( max > 35 ) max = 35;
	write("����ۻ��������ȶ������۹۱ǣ��ǹ��ģ�һ����Ϣ��ʼ������������� ...��\n");
	tell_room( environment(me), 
		me->query("c_name")+ "����������������Ŀ���񣬿�ʼ������\n", me );
	me->set_temp("exercising", base_name(this_object()));
	EXERCISING->apply_effect(me, max, 5*max-random(skill/5));
	return 1;
}

int help()
{
    write(@HELP
ָ���ʽ�� chutan

��������������������壬���о��������������Ϊ���������������ڹ��ڳ���
�۵����൱Σ�յġ��������ھ۵�ʱ����������Ļ������Խ����ԭ����ֵ�½���
Ҳ���ܲ�������һЩ������Ӱ�졣
HELP
	);
    return 1;
}
