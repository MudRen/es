#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Gold-God's shield","����" );
     add( "id",({ "shield" }) );
     set_short( "����" );
     set_long(@C_LONG
һ��ƽ��ƳɵĶ��ƣ�ԲԲ�ģ�����һ�Ŵ���
C_LONG
     );
     set( "weight",100 );
     set( "unit", "��");
     set( "type", "shield" );
     set( "material","heavy_metal" );
     set( "armor_class",5 );
     set( "defense_bonus",1 );
     set( "value",({ 1500,"silver" }) );
}
