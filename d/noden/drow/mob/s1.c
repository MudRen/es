#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(5);
        set_name("snake", "С����" );
        set_short("snake", "С����" );
        set_long(
@C_LONG
������С���ߣ�����ĳ�ʶ���б���֪�������޶���
C_LONG
        );
        set( "unit", "��" );
        set( "alignment", -200 );
        set( "natural_weapon_class1", 8 );
        set( "natural_min_damage1", 4 );
        set( "natural_max_damage1", 5 );
        set("chat_chance",5);
        set( "chat_output", ({
                "С��������Ľű����ߡ�\n" }) );
        set_c_limbs( ({ "ͷ��", "����", "β��" }) );
        set_c_verbs( ({ "%s��ͷ���죬��%sҧȥ" }) );
}

