#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu leggings", "����ϥ");
        add( "id", ({ "leggings" }) );
        set_short("tanyu leggings", "����ϥ");
        set_long(@AAA
�������������еĻ�ϥ
AAA
        );
        set( "unit", "��"); 
        set( "type", "legs" );
        set( "armor_class", 7 );
        set( "defense_bonus", 3 );
        set("material","light_metal");
        set( "weight", 50 );
        set( "value", ({ 560, "silver" }) );
}
