#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("fish skin","��Ƥˮ��");
    add("id",({"fish","skin"}) );
    set_short( "fish skin","��Ƥˮ��");
	set_long(
		"This is a cloth made of skin of fish\n",
		"����һ�����Ƥ���ɵ��·������������������Ϊ\n"
		"���ģ�����ˮ�д���ȴ�ɿ��Ի���磮\n"
	);
	set( "unit", "��" );
	set( "weight", 90 );
	set( "type", "body" );
	set( "armor_class", 19 );
        set("material","leather");
	set( "defense_bonus", 2 );
	set( "value", ({ 45, "gold" }) );
        set( "special_defense",(["none":4,"acid":-5]));
        set( "extra_skills",(["swimming":20]));
}
