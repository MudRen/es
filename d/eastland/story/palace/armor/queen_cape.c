#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Silver cape","��˿ҷβ�Ƽ�" );
     add( "id",({ "cape" }) );
     set_short( "��˿ҷβ�Ƽ�" );
     set_long(@C_LONG
һ���ֹ�ϸ�µ�˿���Ƽ磬�������������档
C_LONG
     );
     set( "weight",70 );
     set( "unit", "��");
     set( "type", "cloak" );
     set( "material","cloth" );
     set( "defense_bonus",10 );
     set( "value",({ 2500,"silver" }) );
}
