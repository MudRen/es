#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu ring", "����ָ��");
        add( "id", ({ "ring" }) );
        set_short("tanyu ring", "����ָ��");
        set_long(@AAA
���������ɵ���������֮һ������ָ��
AAA
        );
        set( "unit", "��"); 
        set( "type", "finger" );
        set( "armor_class", 0 );
        set( "defense_bonus", 6 );
        set("material","light_metal");
        set( "weight", 20 );
        set( "value", ({ 660, "silver" }) );
}
