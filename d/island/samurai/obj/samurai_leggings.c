#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai_leggings", "��ʿ��ϥ ");
        add( "id", ({ "leggings" }) );
        set_short("samurai_leggings", "��ʿ��ϥ");
        set_long(@AAA
һ����ʿ����ʽ���Ļ�ϥ
AAA
        );
        set( "unit", "��"); 
        set( "type", "legs" );
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set("material","element");
        set( "weight", 100 );
        set( "value", ({ 600, "silver" }) );
}
