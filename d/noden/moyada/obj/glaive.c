#include "../moyada.h"

inherit WEAPON;

void create()
{
	set_name("Glaive", "��");
	add ("id",({ "blade","glaive","sword",}) );
	set_short("ն����ٵ�");
	set_long(@C_LONG
����һ������ʹ�õĴ󵶣����Ͽ���һ����������������
��������ʮ�㡣
C_LONG
	);
	
	set( "unit", "��" );
	set_c_verbs( ({ "%s����%s",  }) );
 	set( "weapon_class", 29 );
 	set( "nosecond", 1);
	set( "type", "longblade" );
	set( "no_sale", 1);
	set( "min_damage", 17 );
	set( "max_damage", 39 );
	set( "weight", 290 );
	set( "value", ({ 21100, "silver" }) );
}
