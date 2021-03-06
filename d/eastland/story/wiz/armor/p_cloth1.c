#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "red silk du-do","红缎地彩绣肚兜" );
        add( "id", ({ "cloth", "du-do" }) );
        set_short( "红缎地彩绣肚兜");
        set_long(@LONG
一件设计可爱，小巧玲珑的肚兜。用米色和朱红两色做地，并逢而制，主要用扇形
几何图案并加彩绣之花鸟纹搭衬而成。
LONG);
        set( "unit", "件" );
        set( "weight", 80 );
        set( "type", "body" );
        set( "material", "cloth");
        set( "armor_class", 20);
        set( "defense_bonus", 5);
        set( "value", ({ 2000, "silver" }) );
}
