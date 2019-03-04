#include <mudlib.h>

inherit ARMOR;

string C_NAME="[37;1mÒøÍ·¿ø[37;0m";

void create()
{
	set_name( "silver helmet", C_NAME );
	add( "id", ({ "helmet" }) );
	set_short( C_NAME );
	set_long(
		"Ò»¶¥ÉÁÁÁµÄÒøÉ«Í·¿ø£¬Õâ¶¥Í·¿øÊÇÅµ´ïÄáÑÇÍõÊÒµÄÌØÔ¼¹¤½³Âó¶û\n"
		"µÏÀ¶µÄ¾«ĞÄ½Ü×÷£¬ËûÔø¾­ºÜ×ÔºÀµØÏòÈËÃÇËµ¹ı£¬Õâ¶¥Í·¿øµÄ·ÀÓù\n"
		"Á¦³ıÁË¸½ÉÏÄ§·¨ÒÔÍâ£¬ÒÑ¾­ÎŞ·¨ÔÙ¸üÇ¿ÁË¡£\n"
	);
	set( "unit", "¶¥" );
	set( "type", "head" );
	set( "material", "knight" );
	set( "armor_class", 10 );
	set( "extra_skills", ([ "tactic":10 ]) );
	set( "weight", 70 );
	set( "value", ({ 250, "gold" }) );
	set( "no_sale", 1);
}
