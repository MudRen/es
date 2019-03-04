

#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(2);
        set_name("bee", "Ұ��");
        set_short("Ұ��");
        set_long(
                "�㿴��һֻ���˽е�Ұ�䣬��������������ת������ò�Ҫ������\n"
        );
        set( "unit", "ֻ" );
        set( "alignment", -100 );
	set( "tactic_func", "sting" );
        set_natural_weapon( 5, 2, 5 );
        set_natural_armor( 10, 4 );
        set( "c_death_msg", "%s�������䵽���ϣ��������� ....\n" );
        set_c_limbs( ({ "ͷ��", "����", "���" }) );
        set_c_verbs( ({ "%s�������˵Ľ�������%s��ȥ" }) );
}

int sting()
{
        object victim;

        if( random(20)>4 || !(victim= query_attacker()) ) return 0;
        tell_object( victim, 
                "Ұ��ɵ�������ϣ���е�����һ���ʹ��\n");
        tell_room( environment(this_object()), 
                "Ұ��ɵ�" + victim->query("c_name") + "�����ϣ���β������һ󧣡\n",
                this_object() );
        (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 5, 3 );
        return 1;
}
