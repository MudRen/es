#include "../../story.h"

inherit SARM"OR";
inherit ARMOR;

void create()
{
     set_name( "Crystal cape","ˮ���Ƽ�" );
     add( "id",({ "cape" }) );
     set_short( "ˮ���Ƽ�" );
     set_long(@C_LONG
һ��ˮ���Ƴɵ����磬��ʱɢ����Щ΢������
C_LONG
     );
     set( "weight",100 );
     set( "unit", "��");
     set( "type", "cloak" );
     set( "material","element" );
     set( "the_one",1);
     set( "armor_class",6 );
     set( "defense_bonus",3 );
     set( "value",({ 4000,"silver" }) );
     set( "special_defense",(["fire":-20,"cold":40]));
}
