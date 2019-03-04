#include <mudlib.h>

inherit ARMOR;

string C_NAME="[37;1mÒøÊÖÌ×[37;0m";

void create()
{
	set_name( "silver gauntlets", C_NAME );
	add( "id", ({ "gauntlets" }) );
	set_short( C_NAME );
	set_long(
		"Ò»Ë«ÉÁÁÁµÄÒøÉ«ÊÖÌ×£¬ÕâË«ÊÖÌ×ÊÇÅµ´ïÄáÑÇÍõÊÒµÄÌØÔ¼¹¤½³Âó¶û\n"
		"µÏÀ¶µÄ¾«ĞÄ½Ü×÷£¬ËûÔø¾­ºÜ×ÔºÀµØÏòÈËÃÇËµ¹ı£¬ÕâË«ÊÖÌ×µÄ·ÀÓù\n"
		"Á¦³ıÁË¸½ÉÏÄ§·¨ÒÔÍâ£¬ÒÑ¾­ÎŞ·¨ÔÙ¸üÇ¿ÁË¡£\n"
	);
	set( "unit", "Ë«" );
	set( "type", "hands" );
	set( "material", "knight" );
	set( "armor_class", 5 );
	set( "extra_skills", ([ "parry" :10 ]) );
	set( "weight", 80 );
	set( "value", ({ 210, "gold" }) );
	set( "no_sale", 1);
}
