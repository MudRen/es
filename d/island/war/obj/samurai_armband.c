#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai_armband", "��ʿ���� ");
        add( "id", ({ "armband" }) );
        set_short("samurai_armband", "��ʿ����");
        set_long(@AAA
һ����ʿ����ʽ���Ļ���
AAA
        );
        set( "unit", "��"); 
        set( "type", "arms" );
        set( "armor_class", 3 );
        set( "defense_bonus", 3 );
        set("material","leather");
        set( "weight", 100 );
        set( "value", ({ 650, "silver" }) );
        
}
