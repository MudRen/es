#include "../dony.h"

inherit ARMOR;

void create()
{
     set_name("rainbow boots","七彩云靴");
     add( "id", ({ "boots" }) );
     set_short( "七彩云靴" );
     set_long(@C_TOPIC
七彩云靴是用高级的绸缎做成的,上面因绣有彩虹的图形而命名的。
C_TOPIC
              );
     set( "unit", "双" );
     set( "type", "feet" );
     set( "material", "cloth" );
     set( "armor_class", 7 );
     set( "defense_bonus", 5 );
     set( "weight", 40 );
     set( "value", ({ 300, "silver" }) );
}