#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "silver plate","��������" );
     add( "id",({ "plate" }) );
     set_short( "��������" );
     set_long(@C_LONG
һ�������Ƴɵ����ף����ͱ��£�������Ӣͦ���ˡ�
C_LONG
     );
     set( "weight",100 );
     set( "unit", "��");
     set( "type", "body" );
     set( "material","heavy_metal" );
     set( "armor_class",34 );
     set( "defense_bonus",5 );
     set( "value",({ 3000,"silver" }) );
}
