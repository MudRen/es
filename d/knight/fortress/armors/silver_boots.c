#include  <mudlib.h>

inherit ARMOR;

string C_NAME="[37;1mÒøÕ½Ñ¥[37;0m";

void create()
{
        set_name("silver boots", C_NAME);
        add( "id", ({ "boots" }) );
	set_short( C_NAME );
        set_long(
                "Ò»Ë«ÉÁÁÁµÄÒøÉ«Ñ¥×Ó£¬ÕâË«Ñ¥×ÓÊÇÅµ´ïÄáÑÇÍõÊÒµÄÌØÔ¼¹¤½³Âó¶û\n"
                "µÏÀ¶µÄ¾«ĞÄ½Ü×÷£¬ËûÔø¾­ºÜ×ÔºÀµØÏòÈËÃÇËµ¹ı£¬ÕâË«Ñ¥×ÓµÄ·ÀÓù\n"
                "Á¦³ıÁË¸½ÉÏÄ§·¨ÒÔÍâ£¬ÒÑ¾­ÎŞ·¨ÔÙ¸üÇ¿ÁË¡£\n"
        );
        set( "unit", "Ë«" );
        set( "type", "feet" );
        set( "material", "knight");
        set( "extra_skills", ([ "defend":10 ]) ); 
        set( "armor_class", 10 );
        set( "weight", 50 );
        set( "value", ({ 100, "gold" }) );
        set( "no_sale", 1); 
}
