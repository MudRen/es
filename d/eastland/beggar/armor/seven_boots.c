#include "../dony.h"

inherit ARMOR;

void create()
{
     set_name("rainbow boots","�߲���ѥ");
     add( "id", ({ "boots" }) );
     set_short( "�߲���ѥ" );
     set_long(@C_TOPIC
�߲���ѥ���ø߼��ĳ�����ɵ�,���������вʺ��ͼ�ζ������ġ�
C_TOPIC
              );
     set( "unit", "˫" );
     set( "type", "feet" );
     set( "material", "cloth" );
     set( "armor_class", 7 );
     set( "defense_bonus", 5 );
     set( "weight", 40 );
     set( "value", ({ 300, "silver" }) );
}