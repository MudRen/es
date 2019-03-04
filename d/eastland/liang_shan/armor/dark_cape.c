#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("black robe","��˿����");
    add("id",({"robe","cloth"}) );
    set_short( "black robe","��˿����");
	set_long(
		"This is a anti-magic black robe.\n",
		"����һ��������������ַ��£��ƺ��������ո����Ĺ��ߺ�������\n"
		"���ǿ������;��ò�̫���������������֪�����?\n"
	);
    set( "no_sale",1);
	set( "unit", "��" );
	set( "weight", 70 );
	set( "type", "body" );
	set( "armor_class", 22 );
        set("material","cloth");
	set( "defense_bonus", 5 );
	set( "value", ({ 290, "gold" }) );
        set( "special_defense",(["magic":10,"energy":10,"electric":10,"fire":15,"cold":15]));
        set( "extra_stats",(["con":-1,"str":-2,"kar":-1]));
}
