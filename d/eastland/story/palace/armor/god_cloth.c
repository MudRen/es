#include "../../story.h"

inherit ARMOR;
inherit SARM"OR";
void create()
{
     set_name( "God-Dragon plate","��������" );
     add( "id",({ "plate" }) );
     set_short( "��������" );
     set_long(@C_LONG
һ��ǰ��̻������������ף�ȫ�������������˰������֡�
C_LONG
     );
     set( "weight",100 );
     set( "unit", "��");
     set( "type", "body" );
     set( "material","element" );
     set( "armor_class",26 );
     set( "defense_bonus",5 );
     set( "the_one",1);
     set( "value",({ 3000,"silver" }) );
}
