#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "rainbow mirror","[0;34m��[1;34m��[0;34m[1;34m��[0;34m_[1;34m��[0;34m[[1;34m��[0;34m��[1;34m��[0;34m��[0;37m" );
     add( "id",({ "shield","mirror" }) );
     set_short( "[0;34m��[1;34m��[0;34m��[1;34m_[0;34m��[1;34m[[0;34m��[1;34m��[0;34m��[1;34m��[0;37m" );
     set_long(@C_LONG
һ��ĥ���������ľ��ӣ������ϵ����Ʋ�ʱ���������Ĺ��ߡ�
C_LONG
     );
     set( "weight",80 );
     set( "unit", "��");
     set( "type", "shield" );
     set( "material","element" );
     set( "armor_class",6 );
     set( "defense_bonus",8 );
     set( "value",({ 5000,"silver" }) );
     set( "equip_func","equip_cloth");
     set( "unequip_func","unequip_cloth" );
     set( "special_defense",(["cold":-20]));
} 
int equip_cloth()
{
     set("light",1);
     return 1;
}
int unequip_cloth()
{
     set("light",0);
     return 1;
}
