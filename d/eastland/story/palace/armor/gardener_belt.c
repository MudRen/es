#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "White skirt","����սȹ" );
     add( "id",({ "skirt" }) );
     set_short( "����սȹ" );
     set_long(@C_LONG
һ����ɫ��Χȹ��������Ů�Կ��Դ�����
C_LONG
     );
     set( "weight",50 );
     set( "unit", "��");
     set( "type", "legs" );
     set( "material","cloth" );
     set( "armor_class",1 );
     set( "defense_bonus",2 );
     set( "value",({ 1000,"silver" }) );
}
