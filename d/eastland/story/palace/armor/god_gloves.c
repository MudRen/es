#include "../../story.h"

inherit ARMOR;
inherit SARM"OR";
void create()
{
     set_name( "God-Dragon bracers","������" );
     add( "id",({ "bracers","gloves" }) );
     set_short( "������" );
     set_long(@C_LONG
һ˫������צ�İ�ɫ���ף��񹤾�����
C_LONG
     );
     set( "weight",40 );
     set( "unit", "˫");
     set( "type", "hands" );
     set( "material","element" );
     set( "armor_class",3 );
     set( "defense_bonus",3 );
     set( "the_one",1);
     set( "value",({ 2000,"silver" }) );
}
