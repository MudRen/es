#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("life amulet","������");
        add("id",({"amulet"}) );
         set_short( "a life amulet","������");
	set_long(
"ͨ������С��һ����,�ͻᱻ�������������,������С�����ܳ�������,��������\n"
	);
	set( "unit", "��" );
	set( "weight", 10 );
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "armor_class", 0 );
	set( "defense_bonus", 1 );
	set( "special_defense", ([ "evil":2 ]) );
	set( "value", ({ 5, "gold" }) );
}
