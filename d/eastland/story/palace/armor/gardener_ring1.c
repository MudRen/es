#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Lu-Wu's ring","½��֮��" );
     add( "id",({ "ring" }) );
     set_short( "½��֮��" );
     set_long(@C_LONG
һֻ�ƳγεĽ�ָ���������½���Ф��
C_LONG
     );
     set( "weight",5 );
     set( "unit", "ֻ");
     set( "type", "finger" );
     set( "material","element" );
     set( "defense_bonus",5 );
     set( "value",({ 800,"silver" }) );
     set( "special_defense",(["poison":30,"evil":30,"divine":-30,"fire":-50]));
}
