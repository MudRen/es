#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "spider ankh", "֩��ʥ��" );
	add( "id", ({ "ankh" }) );
   set_short( "֩��ʥ��" );
	set_long(
		"����һ��С�͵�ʥ�꣬��������һ���Ʋ���ʥ���м�һ��Բ�ε�\n"
		"ͻ���Ͽ���һ��֩��ļǺš�\n"
	);
	set( "type", "misc" );
   set( "material", "wood" );
   set( "weight", 50 );
	set( "armor_class", 0 );
   set( "defense_bonus", 5 );
   set( "special_defense", ([ "poison":20, "acid" : -25 ]) );
   set( "value", ({ 980, "silver" }) );
   set( "extra_skills", ([ "depoison" : 10 ]) );
}
