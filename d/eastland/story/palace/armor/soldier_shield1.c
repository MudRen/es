#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "silver shield","��������" );
     add( "id",({ "shield" }) );
     set_short( "��������" );
     set_long(@C_LONG
һ�������ƳɵĶ��ƣ���ʱ�ڶ�����ҫ�����⣬���ۼ��ˡ�
C_LONG
     );
     set( "weight",100 );
     set( "unit", "��");
     set( "type", "shield" );
     set( "material","heavy_metal" );
     set( "armor_class",7 );
     set( "defense_bonus",4 );
     set( "value",({ 3500,"silver" }) );
}
