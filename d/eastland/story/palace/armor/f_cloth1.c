#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Yellow cloth","浅黄色宫装" );
     add( "id",({ "cloth" }) );
     set_short( "浅黄色宫装" );
     set_long(@C_LONG
一色浅黄色的宫装，薄如蝉翼。
C_LONG
     );
     set( "weight",100 );
     set( "unit", "件");
     set( "type", "body" );
     set( "material","cloth" );
     set( "defense_bonus",5 );
     set( "value",({ 500,"silver" }) );
}
