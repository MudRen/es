#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu cloak", "��������");
        add( "id", ({ "cloak" }) );
        set_short("tanyu cloak", "��������");
        set_long(@AAA
�������������е����磬�в���ķ�����
AAA
        );
        set( "unit", "��"); 
        set( "type", "cloak" );
        set( "armor_class", 6 );
        set( "defense_bonus", 4 );
        set("material","light_metal");
        set( "weight", 50 );
        set( "value", ({ 660, "silver" }) );
}
