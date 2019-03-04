#include <mudlib.h>

inherit ARMOR;

string C_NAME="[37;1mÒø¿ø¼×[37;0m";

void create()
{
	set_name( "silver platemail", C_NAME );
	add( "id", ({ "plate", "platemail" }) );
	set_short( C_NAME );
	set_long(
		"Ò»Ì×ÉÁÁÁµÄÒøÉ«¿ø¼×£¬ÕâÌ×¿ø¼×ÊÇÅµ´ïÄáÑÇÍõÊÒµÄÌØÔ¼¹¤½³Âó¶û\n"
		"µÏÀ¶µÄ¾«ĞÄ½Ü×÷£¬ËûÔø¾­ºÜ×ÔºÀµØÏòÈËÃÇËµ¹ı£¬ÕâÌ×¿ø¼×µÄ·ÀÓù\n"
		"Á¦³ıÁË¸½ÉÏÄ§·¨ÒÔÍâ£¬ÒÑ¾­ÎŞ·¨ÔÙ¸üÇ¿ÁË¡£\n"
	);
	set( "unit", "Ì×" );
	set( "type", "body" );
	set( "material", "knight");
	set( "armor_class", 40 );
	set( "weight", 370 );
	set( "value", ({ 330, "gold" }) );
	set( "no_sale",1 );
}
