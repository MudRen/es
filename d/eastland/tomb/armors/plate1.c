#include "../almuhara.h"

inherit ARMOR;

void create()
{
        set_name("Holy plate","����ʥ��");
        add("id",({"plate","platemail"}) );
        set_short( "����ʥ��");
	set_long(
"����һ����ĳ������������������,���Ա�����ֿ����˵Ĺ������������а���
����ʱ���������ṩ���õķ�������\n"
	);
	set( "unit", "��" );
	set( "weight", 300 );
	set( "type", "body" );
	set( "material", "light_metal" );
	set( "armor_class", 35 );
	set( "defense_bonus", 0 );
	set( "special_defense", ([ "evil" : 20 ]) );
	set( "value", ({ 320, "gold" }) );
}
