#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Westgod's necklace","@@query_short" );
     add( "id",({ "necklace" }) );
     set_short( "@@query_short" );
     set_long(@C_LONG
һ��������죬����������״���������ֵ������
C_LONG
     );
     set( "weight",50 );
     set( "unit", "��");
     set( "type", "misc" );
     set( "material","heavy_metal" );
     set( "defense_bonus",5 );
     set( "value",({ 3000,"silver" }) );
}
string query_short()
{
    return set_color("�������","HIY");
}