#include <mudlib.h>

inherit ARMOR;

string C_NAME="[37;1mÒøëÖ¼×[37;0m";

void create()
{
	set_name( "silver leggings", C_NAME );
	add( "id", ({ "leggings" }) );
	set_short( C_NAME );
	set_long(
		"Ò»¸±ÉÁÁÁµÄÒøÉ«ëÖ¼×£¬Õâ¸±ëÖ¼×ÊÇÅµ´ïÄáÑÇÍõÊÒµÄÌØÔ¼¹¤½³Âó¶û\n"
		"µÏÀ¶µÄ¾«ĞÄ½Ü×÷£¬ËûÔø¾­ºÜ×ÔºÀµØÏòÈËÃÇËµ¹ı£¬ÕâÌ×ëÖ¼×µÄ·ÀÓù\n"
		"Á¦³ıÁË¸½ÉÏÄ§·¨ÒÔÍâ£¬ÒÑ¾­ÎŞ·¨ÔÙ¸üÇ¿ÁË¡£\n"
	);
	set( "unit", "¸±" );
	set( "type", "legs" );
	set( "material", "knight");
	set( "armor_class", 10);
	set( "weight", 150 );
	set( "value", ({ 270, "gold" }) );
	set( "no_sale", 1);
}
