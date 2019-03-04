#include <mudlib.h>

inherit WEAPON;

void create()
{
   set_name( "crimson mace", "Ñªºì¶¤Í·é³" );
   add("id",({"mace",}));
   set_short("Ñªºì¶¤Í·é³");
   set_long(
        "Ò»°ÑÆÕÍ¨µÄÑªºì¶¤Í·é³¡£\n"
               );
	set( "unit", "°Ñ" );
   set( "weapon_class", 17 );
   set( "type", "blunt" );
   set( "min_damage", 9 );
   set( "max_damage", 20 );
   set( "weight", 150 );
   set( "value", ({ 50, "gold" }) );
   set("extra_skills",(["anatomlogy": 5]));
}
