
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name("golden battleaxe", "�ƽ�ս��");
        add ("id",({ "axe", "battleaxe" }) );
        set_short( "�ƽ�ս��" );
        set_long(
            "����һ�������Ļƽ�ս�������޴�����ʾ�����ǰѺ�����ǿ��������\n"
        );
        set("nosecond", 1);
        set("unit", "��");
        set( "weapon_class", 33 );
        set( "type", "axe" );
        set( "min_damage", 20 );
        set( "max_damage", 45 );
        set( "weight", 300);
        set( "value", ({ 300, "gold" }) );
}

