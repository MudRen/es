
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("Obsidian longsword", "����ʯ����");
        add ("id",({ "longsword" }) );
        set_short( "����ʯ����" );
        set_long(
            "����һ�Ѿ޴�ĳ���,�����Ŀ�ʯ,����ʯ���Ƴɵġ�\n"
        );
        set( "unit", "��");
        set( "weapon_class", 38 );
        set( "type", "longblade" );
        set( "min_damage", 28 );
        set( "max_damage", 39 );
        set( "weight", 240 );
        set( "value", ({ 4444, "silver" }) );
}

