#include <mudlib.h>

inherit WEAPON;

string C_NAME="[37;1mÁúÑªÇ¹[37;0m";

void create()
{
	seteuid(getuid());
	set_name( "lance of dragonblood", C_NAME );
	add( "id", ({ "lance", "dragonblood" }) );
	set_short( "³¤Ç¹¡¸ÒøÁúÖ®Ñª¡¹" );
	set_long(
		"Õâ¾ÍÊÇÐí¶àÅµ¶ÙÆïÊ¿Ò»ÉúµÄÃÎÏë£¬ÍêÃÀµÄ³¤Ç¹¡¸ÒøÁúÖ®Ñª¡¹¡£Õâ°Ñ³¤Ç¹\n"
		"¾ÝËµÊÇÊý°ÙÄêÇ°Ò»ÌõÒøÁúËùÊØ»¤µÄ±¦²Ø£¬Ðí¶àÈË¶¼ÏàÐÅÕâÊÇ¹¤½³Ö®Éñ°£\n"
		"ÀíÑÇ(Ariah)ÔùËÍ¸øÈË¼ä×îÎ°´óÆïÊ¿µÄÀñÎï £¬Õâ°Ñ³¤Ç¹ÍêÃÀµÄÔìÐÍÓëËü\n"
		"ÎÞ¼á²»´ÝµÄÁ¦Á¿ÄÜ´ø¸øÊ¹ÓÃËüµÄÆïÊ¿×î´óµÄÈÙÒ«¡£\n"
	);
	set( "unit", "°Ñ" );
	set( "type", "jousting" );
	set( "weapon_class", 48 );
	set( "min_damage", 25 );
	set( "max_damage", 52 );
	set( "weight", 120 );
	set( "hit_func", "weapon_hit" );
	set( "value", ({ 5600, "silver" }) );
	set( "no_sale", 1 );
}

int weapon_hit(object victim, int damage)
{
	if( (string)victim->query("race")!="dragon" ) return 0;
	victim->receive_special_damage( "magic", damage );

	return damage;
}



