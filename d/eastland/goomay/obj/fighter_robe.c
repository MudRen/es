#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "fighter's robe", "�䶷��" );
	add( "id", ({ "robe" }) );
	set_short( "an fighter's robe", "�䶷��" );
	set_long(
		"You see a fighter's robe.\n",
		"����һ�����������߰������·��������������ṩ�ܺõı��������ǿ���ʹ�˸����ݡ�\n"
	);
	set( "unit", "��" );
        set("material","cloth");
	set( "type", "body" );
	set( "weight", 80 );
	set( "armor_class", 15 );
        set( "defense_bonus", 7 );
        set("special_defense",(["none":30, ]));
        set("extra_stats",(["dex": 1,"con":-1 ,]));
	set( "value", ({ 650, "silver" }) );
}
