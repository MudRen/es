#include "../../story.h"

inherit ARMOR;
inherit SARM"OR";
void create()
{
     set_name( "God-Dragon helmet","亢龙盔" );
     add( "id",({ "helmet", }) );
     set_short( "亢龙盔" );
     set_long(@C_LONG
一顶太白金精制成的头盔，彷造龙的形状做成的。
C_LONG
     );
     set( "weight",40 );
     set( "unit", "顶");
     set( "type", "head" );
     set( "material","element" );
     set( "armor_class",6 );
     set( "defense_bonus",2 );
     set( "the_one",1);
     set( "value",({ 2000,"silver" }) );
}
