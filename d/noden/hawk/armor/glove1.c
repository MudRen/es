#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "Purple gloves","��������" );
        add( "id", ({ "gloves" }) );
        set_short( "��������" );
        set_long(
		"����һ˫������ľ�����ף�������Ⱦ����������ɫ���ơ�\n"
        );
        set( "unit", "˫" );
	set("material","wood");
        set( "type", "hands" );
        set( "armor_class", 4 );
        set( "defense_bonus", 2 );
        set( "weight", 50 );
        set( "value", ({ 510, "silver" }) );
}
