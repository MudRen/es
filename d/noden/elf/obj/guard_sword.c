
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name("longsword", "����");
        add ("id",({ "sword", "longsword"}) );
        set_short( "����" );
        set_long(
            "���Ľ��п�����ʮ�ַ�����Ӧ��һ�Ѻ�������\n"
        );
        set( "unit", "��");
        set( "weapon_class", 14 );
        set( "type", "longblade" );
        set( "min_damage", 7 );
        set( "max_damage", 16 );
        set( "weight", 75 );
        set( "value", ({ 200, "silver" }) );
}

