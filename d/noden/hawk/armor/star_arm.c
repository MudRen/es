#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "Star Armband","���Ǳۻ�" );
        add( "id", ({ "armband" }) );
        set_short( "���Ǳۻ�" );
        set_long(
                "һ���������Ƴɵıۻ���������������������ꡣ\n"
        );
        set( "unit", "��" );
	set("material","element");
        set( "type", "arms" );
        set( "armor_class", 4 );
        set( "defense_bonus", 2 );
	set( "extra_skills", (["tactic" : 5, "riding" : 5]) );
        set( "weight", 30 );
        set( "value", ({ 1300, "silver" }) );
}
