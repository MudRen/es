#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(9);
        set_name("big snake", "������");
        set_short("������");
        set_long(
@C_LONG
����һ�����;޴�Ĵ����ߣ��������ֵ���������֪���¶��ٶ�����
C_LONG
        );
        set( "unit", "��" );
        set( "pursuing", 1 );
        set( "aggressive", 1 );
        set( "moving", 1 );
        set( "speed", 20 );
        set( "patrol", ({ "north","south"}) );
        set( "killer", 1 );
        set( "alignment", -400 );
        set( "natural_weapon_class1", 8 );
        set( "natural_min_damage1", 4 );
        set( "natural_max_damage1", 5 );
        set_c_limbs( ({ "ͷ��", "�ʷʵ�����", "�ִֵ�β��" }) );
        set_c_verbs( ({ "%s����Ť������%s��ȥ" }) );
}

