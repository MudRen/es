#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu shield", "�����");
        add( "id", ({ "shield" }) );
        set_short("tanyu shield", "�����");
        set_long(@AAA
���������ɵ�����֮����
AAA
        );
        set( "unit", "��"); 
        set( "type", "shield" );
        set( "armor_class", 6 );
        set( "defense_bonus", 4 );
        set("material","light_metal");
        set( "weight", 100 );
        set( "value", ({ 860, "silver" }) );
}
