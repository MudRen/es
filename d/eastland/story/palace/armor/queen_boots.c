#include "../../story.h"

inherit ARMOR;
inherit SARM"OR";

void create()
{
     set_name( "Queen's shoes","��˿��ѥ" );
     add( "id",({ "shoes","boots" }) );
     set_short( "��˿��ѥ" );
     set_long(@C_LONG
һ˫��˿�Ϸ��ƶ��ɵ�Ь�ӣ���Ⱦ���߲���ɫ���ǳ��ÿ���
C_LONG
     );
     set( "weight",50 );
     set( "unit", "˫");
     set( "type", "feet" );
     set( "material","cloth" );
     set( "the_one",1);
     set( "armor_class",6 );
     set( "defense_bonus",2 );
     set( "value",({ 1000,"silver" }) );
     set( "special_defense",(["evil":20]));
}
