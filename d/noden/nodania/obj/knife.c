#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("knife", "С��");
	set_short("�������ͭС��");
	set_long(@CLONG
һ������ͭ�̵���ͭС�������С��Ҳ���Ǽ�ֵ���ǵĹŶ���������
��������δ��....��
CLONG
      	       );
	set( "weight", 50 );
	set( "type", "dagger" );
	set( "weapon_class", 6 );
	set( "min_damage", 5 );
	set( "max_damage", 14 );
	set( "second", 1 );
	set( "value", ({ 150, "gold" }) );
}
