#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Lay Chou-Tan", "雷九天" );
	add ("id", ({ "master", "lay", }) );
	set_short( "屠龙剑派二代掌门 雷九天");
	set_long( @LONG
雷九天是屠龙剑派祖师屠龙道人的关门弟子，跟他的五位师兄一样，
他是一名孤儿，屠龙道人收养了他。不过他跟随屠龙道人学艺的时间很短
，大部分的武功心法都是他的大师兄风自在所传，所以他的武功和五位师
兄略有不同而能自成一格。在他的五位师兄奉师命出门行道之後，他奉命
执掌屠龙派，而成为屠龙剑派的二代掌门。
LONG
	);
	set_perm_stat("str", 30 );
	set_perm_stat("con", 25 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "dodge", 100 );
	set( "alignment", 1500 );

	set( "race", "human" );
	set( "gender", "male" );

	set( "hit_points", 2000 );
	set( "max_hp", 2000 );
	set( "aim_difficulty",
	    ([ "critical":70,"vascular":80,"weakest":70,"ganglion":60 ]) );
	set_natural_weapon( 50, 15, 30 );
	set_natural_armor( 90, 60 );
	set ("special_defense", ([
		"all": 40 , "none" : 50]) );

	wield_weapon( "/d/swordman/guild/weapons/anti-god" );
	equip_armor( "/d/swordman/guild/armors/lay_plate" );
	equip_armor( "/d/swordman/guild/armorsblue/lay_pants" );
	equip_armor( "/d/swordman/guild/armors/lay_gloves" );
	equip_armor( "/d/swordman/guild/armors/lay_boots" );
	equip_armor( "/d/swordman/guild/armors/lay_amulet" );
}
