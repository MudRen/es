#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai_cloak", "��ʿ����");
        add( "id", ({ "cloak" }) );
        set_short("samurai_cloak", "��ʿ����");
        set_long(@AAA
һ����ʿ����ʽ��������
AAA
        );
        set( "unit", "��"); 
        set( "type", "cloak" );
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set("material","leather");
        set( "weight", 70 );
        set( "value", ({ 800, "silver"
         }) );
}
