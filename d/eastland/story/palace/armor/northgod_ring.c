#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Dragon ring","����" );
     add( "id",({ "ring" }) );
     set_short( "����" );
     set_long(@C_LONG
һֻˮ���Ƴɵ�С�ɽ�ָ����ָ�ϵ����һ����ͷ��
C_LONG
     );
     set( "weight",20 );
     set( "unit", "ֻ");
     set( "type", "finger" );
     set( "material","element" );
     set( "defense_bonus",5 );
     set( "value",({ 2000,"silver" }) );
}
