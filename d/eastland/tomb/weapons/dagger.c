#include "mudlib.h"

inherit WEAPON;

void create()
{
        set_name("paradise dagger", "�ɺ�����");
        add ("id",({ "dagger",}) );
        set_short("�ɺ�����");
        set_long(
"��˵�������������õ���������״����ذ�ס�����Կ�������Χ��Լ��ҫ��
���⣬�൱ҫ�ۡ�\n"
        );
        set( "unit", "��" );
        set( "weapon_class", 40 );
        set( "type", "dagger" );
        set( "min_damage", 25 );
        set( "max_damage", 35 );
        set( "weight", 50 );
        set( "no_sale", 1);
        set( "value", ({ 2600, "silver" }) );
        set( "bleeding", 8 );
}
