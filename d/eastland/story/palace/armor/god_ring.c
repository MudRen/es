#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "God-Dragon ring","��[1;37mP[0;37m��[1;37ms[0;37m��[1;37m��[0;37m" );
     
     add( "id",({ "ring" }) );
     set_short( "��[1;37mP[0;37m��[1;37ms[0;37m��[1;37m��[0;37m" );
     set_long(@C_LONG
һֻ̫�׽��ƳɵĽ�ָ����ָ�ϵ����һ���������������������ѻ��֡�
C_LONG
     );
     set( "weight",5 );
     set( "unit", "ֻ");
     set( "type", "finger" );
     set( "material","element" );
     set( "defense_bonus",10 );
     set( "value",({ 3000,"silver" }) );
}
