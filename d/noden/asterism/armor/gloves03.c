#include "../asterism.h"

inherit ARMOR;

void create()
{
        set_name("obsidian gloves", "����ʯ����");
        add( "id", ({ "gloves" }) );
        set_short( "����ʯ����");
        set_long(
                "����һ˫�����ĺ���ʯ�Ƴɵ����ס�\n"
        );
        set("unit","˫");
        set( "type", "hands" );
        set("material","element") ;
	set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "weight", 65 );
        set( "value", ({ 150, "gold" }) );
}






