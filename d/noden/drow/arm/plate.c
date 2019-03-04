#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("copper plate", "青铜铠甲" );
        add( "id", ({ "plate" }) );
        set_short( "青铜铠甲");
        set_long(
@C_LONG
这是由青铜所打造的厚重铠甲，在铠甲的表面并且印上蜘蛛的记号
，这是黑暗精灵武士所喜爱的防具，能有效的保护身体免受敌人的
攻击。
C_LONG
        );
        set( "unit", "件");
        set( "type", "body" );
        set( "material", "heavy_metal" );
        set( "armor_class", 16 );
        set( "defense_bonus", 4 );
        set( "special_defense",
        ([ "fire" : 12, "cold" : -8 ]) );
        set( "weight", 200 );
        set( "value", ({ 970, "silver" }) );
}
