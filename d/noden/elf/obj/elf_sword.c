
#include <mudlib.h>
inherit WEAPON;

void create()
{
#include <compress_obj.h>
        set_name("longsword", "����");
        add ("id",({ "sword" }) );
        set_short( "����" );
        set_long(
            "����һ��ľ�����ʹ�õĳ�����\n"
        );
        set( "unit", "��");
        set( "weapon_class", 9 );
        set( "type", "longblade" );
        set( "min_damage", 5);
        set( "max_damage", 8 );
        set( "weight", 70 );
        set( "value", ({ 120, "silver" }) );
}

