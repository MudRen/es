//#pragma save_binary

/*
// Author (??)
// Help added by Brian (1/28/92)
// Converted to mudlib 0.9.0 by Mobydick on 9/19/92
// Kill monster option added by Watcher on 2/19/93
// Watcher added vision check, 4/13/93

// The MudOS mudlib permits player killing by default. It is not hard to
// modify the mudlib to prevent player killing, or permit it only in special
// rooms such as arenas. Instructions for doing this are found in the file
// /doc/mudlib/player_killing.
// If you prevent player_killing you should probably prevent players from
// stealing from one another also, since fights start when the victim detetcts
// a theft.
*/

#include <mudlib.h>

inherit DAEMON;

// More fun. - Annihilator 12-08-93

string *start_fight = ({
	"%s�ȵ�: �ɶ��%s�����У�\n",
	"%s�ȵ�: ������%s���µ���ȥ�ɣ�\n",
	"%s�ȵ�: ��������%s��\n",
	"%s�ȵ�: ȥ���� !! %s !!\n"
});

int help();
string get_monster();

int cmd_kill(string str)
{
	object victim, venv, me;
	int i;

	if( str == "monster" ) str = get_monster();
	if( !str || str == "" ) return help();

	me = this_player();
	if( (int)me->query("hit_points")<=0 )
		return notify_fail("�ܱ�Ǹ�����Ѿ����ˡ�\n");

	str = lower_case(str);
	venv = environment(me);
	if( !venv )
		return notify_fail("�㲻����һƬ���޵��й������ˡ�\n");
 
	if( !me->query("vision") )
		return notify_fail("����˭����ʲ��Ҳ��������\n");
 
	victim = present(str, venv);
	if( !victim || !visible(victim, me) )
		return notify_fail("����û�����빥���Ķ���\n");

	if( !living(victim) )
		return notify_fail("��������ǲ���ֵ�ù����Ķ���\n");

	if ( victim->query("no_attack") ) {
		if( !member_group((string)me->query("name"), "admin") )
		return notify_fail("�������������һ��㲻��ɱ���ǲ���ɱ��\n");
	}
	if( (int)victim->query("ghost")==1 )
		return notify_fail("����������Ѿ����ˣ��㻹��������\n");

	if( victim == me )
		return notify_fail("ɱ���Լ����㲻��ƴ suicide ��\n");
 
	if( victim->query("linkdead") )
		return notify_fail("�㲻�ܳ��˼Ҷ��ߵ�ʱ��������£�\n");
 
 	if ( victim->query("user") ) {
	 	if( !member_group((string)me->query("name"), "admin") &&
 			(victim->query_level()<5 || me->query_level()<5) )
 		return notify_fail("�ڶ����������弶���µ���Ҳ�׼ PK �� PK ���ˡ�\n");
	}
	i = me->kill_ob(victim);
	if( i==0 )
		write( "�ԣ����ͣ����ͣ����ͣ�\n");
	else {
		i = random( sizeof(start_fight) );
		write( 
			sprintf( start_fight[i],"��", victim->query("c_name") ));
		tell_room( environment(me), 
			sprintf( start_fight[i],
				me->query("c_name"), victim->query("c_name") ) ,
			me );
	}

	victim->set_heart_beat(1) ;
	return 1 ;
}

string get_monster()
{
	mixed *env;
 
	env = all_inventory( environment(this_player()) );
	if( !env || !sizeof(env) )  return 0;
 
	env = filter_array(env, "filter_npc", this_object());
	if( !env || !sizeof(env) )  return 0;

	return (string)env[0]->query("name");
}
 
int filter_npc(object obj)
{
	return (int)obj->query("npc");
}
 
int help()
{
		write(@HELP
ָ���ʽ: kill <��������>

ɱnpc����ҡ�����ʼ���޷�ȡ��ָ�������һ��������
����npc��ǳ���Щ������׷ɱ�㡣��
HELP
		);
	return 1;
}
/* EOF */
