#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu armband", "����ۻ�");
        add( "id", ({ "armband" }) );
        set_short("tanyu armband", "����ۻ�");
        set_long(@AAA
�������������еıۻ����в���ķ�����
AAA
        );
        set( "unit", "��"); 
        set( "type", "arms" );
        set( "armor_class", 3 );
        set( "defense_bonus", 1 );
        set("material","light_metal");
        set( "weight", 30 );
        set( "value", ({ 760, "silver" }) );
}
