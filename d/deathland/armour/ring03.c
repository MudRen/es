#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("dwarven royal ring","���˻��ҽ�ָ");
        add("id",({"ring"}) );
         set_short( "a dwarven royal ring","���˻��ҽ�ָ");
	set_long(
"This is a dwarven royal ring. \n"
"����һ�����˻��������ഫ�Ľ�ָ,��������Ī���¶���һ��ʧ����\n"
	);
	set( "unit", "��" );
	set( "weight", 10 );
	set( "type", "finger" );
	set( "material", "element" );
	set( "armor_class", 0 );
	set( "defense_bonus", 7);
	set( "special_defense", ([ "divine":5, "cold":-8 ]) );
	set( "value", ({ 388, "gold" }) );
    set( "no_sale",1);
}
