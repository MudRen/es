#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(12);
        set_name("snake", "�ٲ���" );
        set_short("�ٲ���" );
        set_long(
@C_LONG
����һβ�������ߣ���ͣ�����Ų�������Ŀ������ܣ���֪������
��ӵ�о綾�����࣬���Ǳ������ã�
C_LONG
        );
        set( "unit", "��" );
        set( "alignment", -700 );
        set( "natural_weapon_class1", 8 );
        set( "natural_min_damage1", 4 );
        set( "natural_max_damage1", 5 );
        set( "tactic_func", "emit_poison" );
        set_c_limbs( ({ "ͷ��", "����", "β��" }) );
        set_c_verbs( ({ "%s��ͷ���죬��%sҧȥ" }) );
}

int emit_poison()
{
        object victim;

        if( random(15)>4 || !(victim= query_attacker()) ) return 0;
        tell_room( environment(this_object()),
                "�ٲ����ſ��������ҧ�£������ȫ����һ���ʹ������\n",
                this_object() );
        (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 
29, 3 );
        return 1;
}       
