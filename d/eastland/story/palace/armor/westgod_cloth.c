#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Westgod's cloth","@@query_short" );
     add( "id",({ "cloth" }) );
     set_short( "@@query_short");
     set_long(@C_LONG
����һ�����������Ѫϴ����·����Ǽ�����ף���ķ��ߡ�
C_LONG
     );
     set( "weight",100 );
     set( "unit", "��");
     set( "type", "body" );
     set( "material","heavy_metal" );
     set( "armor_class",33 );
     set( "defense_bonus",5 );
     set( "value",({ 3000,"silver" }) );
     set( "special_defense",(["magic":-20,"mental":25]));
     set( "equip_func","equip_cloth");
     set( "unequip_func","unequip_cloth" );
}
int equip_cloth()
{
     this_player()->add_temp("can_pass_spell",1 );
     return 1;
}
int unequip_cloth()
{
     this_player()->add_temp("can_pass_spell",-1);
     return 1;
}
string query_short()
{
     return set_color("������","HIY");
}