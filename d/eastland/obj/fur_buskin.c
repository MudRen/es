#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "fur buskin", "ÊŞÆ¤¶ÌÑ¥" );
	add( "id", ({ "buskin", "buskins" }) );
   set_short( "ÊŞÆ¤¶ÌÑ¥" );
	set_long(
		"ÕâÊÇÒ»Ë«°¹ÔàµÄÊŞÆ¤¶ÌÑ¥£¬ÉÏÃæÓÃÆ¤Éş²øÁËºÃ¼¸È¦¡£\n"
	);
	set( "unit", "Ë«" );
	set( "type", "feet" );
	set( "material", "leather" );
	set( "weight", 40 );
	set( "armor_class", 2 );
	set( "defense_bonus", 1 );
	set( "special_defense", ([ "fire":-3, "cold":1 ]) );
	set( "value", ({ 260, "silver" }) );
}
