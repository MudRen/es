#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name("six sun boots","����Ԫѥ");
     add( "id", ({ "boots" }) );
     set_short( "����Ԫѥ" );
     set_long(@C_TOPIC
һ˫�������յ�ѥ�ӡ�ѥ��������ֹ��ܾ���,��һʱ������ɡ�
C_TOPIC
              );
     set( "unit", "˫" );
     set( "type", "feet" );
     set( "material", "cloth" );
     set( "armor_class", 2 );
     set( "defense_bonus", 1 );
     set( "weight", 60 );
     set("special_defense",(["magic":15,"evil":-20]) );
     set( "value", ({ 200, "silver" }) );
}