#include "../../story.h"

inherit ARMOR;
inherit SARM"OR";
void create()
{
     set_name( "God-Dragon amulet","Ǳ����" );
     add( "id",({ "amulet" }) );
     set_short( "Ǳ����" );
     set_long(@C_LONG
һ�������������壬�Ͽ�һֻ�������ʵķ�������״�������͡�
C_LONG
     );
     set( "weight",5 );
     set( "unit", "��");
     set( "type", "misc" );
     set( "material","element" );
     set( "the_one",1);
     set( "defense_bonus",5 );
     set( "value",({ 1000,"silver" }) );
}
