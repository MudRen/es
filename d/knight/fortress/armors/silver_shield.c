
#include <mudlib.h>

inherit ARMOR;

string C_NAME="[37;1mÒø¶Ü[37;0m";

void create()
{
	set_name( "silver shield", C_NAME );
	add( "id", ({ "shield" }) );
	set_short( C_NAME );
	set_long(
		"Ò»ÃæÉÁÁÁµÄÒøÉ«¶ÜÅÆ£¬ÕâÃæ¶ÜÅÆÊÇÅµ´ïÄáÑÇÍõÊÒµÄÌØÔ¼¹¤½³Âó¶û\n"
		"µÏÀ¶µÄ¾«ĞÄ½Ü×÷£¬ËûÔø¾­ºÜ×ÔºÀµØÏòÈËÃÇËµ¹ı£¬ÕâÃæ¶ÜÅÆµÄ·ÀÓù\n"
		"Á¦³ıÁË¸½ÉÏÄ§·¨ÒÔÍâ£¬ÒÑ¾­ÎŞ·¨ÔÙ¸üÇ¿ÁË¡£\n"
	);
	set( "unit", "Ãæ" );
	set( "type", "shield" );
	set( "material" ,"knight");
	set( "armor_class", 10 );
	set( "extra_skills", ([ "block":10 ]) );
	set( "weight", 100 );
	set( "value", ({ 270, "gold" }) );
	set( "no_sale", 1);
}
