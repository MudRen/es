#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Yellow cloth","ǳ��ɫ��װ" );
     add( "id",({ "cloth" }) );
     set_short( "ǳ��ɫ��װ" );
     set_long(@C_LONG
һɫǳ��ɫ�Ĺ�װ���������
C_LONG
     );
     set( "weight",100 );
     set( "unit", "��");
     set( "type", "body" );
     set( "material","cloth" );
     set( "defense_bonus",5 );
     set( "value",({ 500,"silver" }) );
}
