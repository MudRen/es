#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Westgod's helmet","@@query_short" );
     add( "id",({ "helmet", }) );
     set_short( "@@query_short" );
     set_long(@C_LONG
һ����γε�ͷ�ڣ��������и�ɫ�鱦��ҫ�����ԡ�
C_LONG
     );
     set( "weight",100 );
     set( "unit", "��");
     set( "type", "head" );
     set( "material","heavy_metal" );
     set( "armor_class",8 );
     set( "defense_bonus",3 );
     set( "value",({ 3000,"silver" }) );
     set( "special_defense",(["divine":10]));
}
string query_short()
{
       return set_color("�����","HIY") ;
}