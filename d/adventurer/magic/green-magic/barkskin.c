//This is a green-magic spell for adventurer casting only
//made by Takeda 11.14.1995////#pragma save_binary

#include <mudlib.h>
#include "/d/adventurer/magic/adm/magic.c"

#define TYPE "green-magic"
#define find_rate 50

int query_sp_cost(object caster, int level, string target) { return 30 + level * 30; }

int query_need_skill(int level) { return 60+10*level; }

int cast(int level, string target)
{
	int delay_time;
	object me, dest;

    me = this_player();
	if( (int)me->query_skill("green-magic") < query_need_skill(level) ) {
		tell_object(me,set_color("�����ħ�����ܲ�����ʹ����ȼ���ħ��!\n","HIG"));
		return 0;
	}
	
	if( target == "NONE" ) dest = me;
	else if( !(dest= present( target, environment(me) )) ) {
		tell_object( me,
			"Ҫ��˭ʹ�ý��ʻ�������\n"
		);
	    return 0;
	}
	if( me->query("npc") && me->query("magic_delay") )
	    delay_time = (int)me->query("magic_delay");
	else
	    delay_time = 3;
	me->block_attack(delay_time);
	me->set_temp("cast_busy", 1);
	tell_object(me,set_color("�㿪ʼ������ħ����Ƥ��������������....��\n","HIG",me));
	tell_room( environment(me), 
		me->query("c_name") + "��ʼ��һ�ֵͳ��������������ġ�\n",
		me );
	call_out( "effect", delay_time, level, me, dest );
	return 1;
}

void effect(int level, object caster, object dest)
{
	int boost, duration;
	
	caster->set_temp("cast_busy", 0);
    if( !dest || !present(dest, environment(caster)) ) {
        tell_object( caster,  "���Ŀ���ߵ��ˡ�\n" );
        return;
    }
	if( dest->query_temp("effect/barkskin") ) {
		tell_object( dest,
			"һ������ɫ�Ĺ�â�������㣬��������ò�û��ʲ�᲻ͬ....��\n");
	} else {
		tell_object( dest, 
			"һ������ɫ�Ĺ�â�������㣬��������Ƥ����ʼ��������������\n"
		);
		boost = (level+1) * 3;
		if( caster == dest )
			duration = (level+1) * 30 + (int)caster->query_stat("pie") * 3;
		else
			duration = (level+1) * 20 + (int)caster->query_stat("pie") * 3;
		dest->set_temp("extra_db/barkskin", boost);
		dest->set_temp("effect/barksin", 1);
		dest->calc_armor_class();
		call_out( "expire", duration, dest);
	}
	tell_room( environment(dest),
		"һ������ɫ��â������"+dest->query("c_name")+"������âɢȥ������Ƥ����ʼ\n"
		"��������������\n"
		, dest 
    );
}

void expire( object player )
{
    if( !player ) return;
	tell_object( player,
		"һ˲�䣬��ļ�ӲƤ��ȫ������.....\n"
    );
	player->receive_damage(30);
	player->set_temp("extra_db/barkskin",0);
	player->set_temp("effect/barkskin",0);
	player->calc_armor_class();
}
