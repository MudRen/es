#include <mudlib.h>

inherit ARMOR;

void create()
{
set_name( "White Boots","���Ʊ���ѥ" );
        add( "id", ({ "boots","white boots" }) );
	set_short( "���Ʊ���ѥ" );
        set_long(
                "һ˫��ɫ��ѥ�ӣ�������а�ɫ�Ļ�����һ���İ��ơ�\n"
        );
        set( "unit", "˫" );
        set("material","wood");
        set( "type", "feet" );
        set( "armor_class", 7 );
        set( "defense_bonus", 3 );
        set( "weight", 35 );
        set( "value", ({ 1410, "silver" }) );
}
