#include "../../story.h"

inherit ARMOR;
inherit SARM"OR";
void create()
{
     set_name( "God-Dragon helmet","������" );
     add( "id",({ "helmet", }) );
     set_short( "������" );
     set_long(@C_LONG
һ��̫�׽��Ƴɵ�ͷ��������������״���ɵġ�
C_LONG
     );
     set( "weight",40 );
     set( "unit", "��");
     set( "type", "head" );
     set( "material","element" );
     set( "armor_class",6 );
     set( "defense_bonus",2 );
     set( "the_one",1);
     set( "value",({ 2000,"silver" }) );
}
