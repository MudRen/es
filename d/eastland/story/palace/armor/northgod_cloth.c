#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Crystal plate","ˮ������" );
     add( "id",({ "plate" }) );
     set_short( "ˮ������" );
     set_long(@C_LONG
һ��ˮ���Ƴɵ����ף�����ȴ��ͬ����һ�㣬û���κ���·��
C_LONG
     );
     set( "weight",110 );
     set( "unit", "��");
     set( "type", "body" );
     set( "material","element" );
     set( "armor_class",35 );
     set( "defense_bonus",8 );
     set( "value",({ 4000,"silver" }) );
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