#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("beholder globe","��ħ����Բ��");
        add("id",({"globe"}) );
         set_short( "a beholder globe","��ħ����Բ��");
	set_long(
"һ����״�ķ�����,����һ�ֻ��ܲ�����\n"
	);
	set( "echo_chain_need",1);
	set( "unit", "��" );
	set( "weight", 110 );
	set( "type", "globe" );
	set( "material", "element" );
	set( "armor_class", 15 );
	set( "defense_bonus", 5 );
	set( "special_defense", 
	     ([ "fire":5, "cold":5, "electric":5, "energy":5, "divine":-20 ]) ); 
	set( "value", ({ 48, "gold" }) );
 //        set( "no_sale", 1 );
}
