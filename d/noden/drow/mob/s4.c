#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(12);
        set_name("snake","��ǻ�" );
        set_short("snake","��ǻ�" );
        set_long(
@C_LONG
����һ�������Ĺ�ǻ�����֪��������ĳ����������࣬����
���о綾�����ǻ��Ǳ������ĺã�
C_LONG
        );
        set( "unit", "��" );
        set( "alignment", -500 );
        set( "natural_weapon_class1", 12 );
        set( "natural_min_damage1", 10 );
        set( "natural_max_damage1", 15 );
        set( "tactic_func", "emit_poison" );
        set_c_limbs( ({ "ͷ��", "����", "β��" }) );
        set_c_verbs( ({ "%s��ͷ���죬��%sҧȥ" }) );
}

int emit_poison()
{
        object victim;

        if( random(15)>4 || !(victim= query_attacker()) ) return 0;
        tell_room( environment(this_object()),
                "��ǻ������ļ����ݺݵ�����ҧ�£������һ���ʹ ....\n",
                this_object() );
        (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 
25, 9 );
        return 1;
}       
