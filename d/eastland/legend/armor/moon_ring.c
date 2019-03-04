#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "moon ring","月戒");
        add( "id", ({"ring"}) );
        set_short("月戒");
        set_long(@C_LONG
一只因上面镶有月光宝石而命名的戒指。戒指上闪耀著皎洁无暇的光芒，令人不忍想
玩赏一番。
C_LONG
        );
        set( "unit", "只" );
        set( "type", "finger" );
        set( "material", "element" );
        set( "weight",1);
        set( "defense_bonus", 7 );
        set( "value", ({ 1000, "silver" }) );
}
