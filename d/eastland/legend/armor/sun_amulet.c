#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name("sun amulet", "�շ�");
     add( "id", ({ "amulet" }) );
     set_short( "�շ�");
     set_long(@C_LONG
һ�������ſ�̫���Ļ������ഫ�⻤���ϵľ����Ǳ��������µ�����Ļ��Ǹ�����
�ɵģ�������������л���о����������ů������
C_LONG
     );
     set("unit","��");
     set("material","cloth");
     set( "type", "misc" );
     set( "defense_bonus", 9 );
     set( "weight", 5 );
     set( "value", ({ 150, "gold" }) );
}