#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("dark ring","�ڰ���ָ");
        add("id",({"ring"}) );
         set_short( "a dark ring","�ڰ���ָ");
	set_long(
"This is a ring blessed by Evil God -- Yang. \n"
"����һ������а�� Yang ף�����Ľ�ָ,����ħ�����Ա����������˵��ػ�\n"
	);
	set( "unit", "��" );
	set( "weight", 10 );
	set( "type", "finger" );
	set( "material" ,"element" );
	set( "armor_class", 0 );
	set( "defense_bonus", 7 );
    set( "special_defense", ([ "evil":5, "divine":-8 ]) );   
	set( "value", ({ 288, "gold" }) );
}
