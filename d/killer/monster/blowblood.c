#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
        set_name( "blowblood", "西门吹血" );
	add ("id", ({ "captain", "knight", "royal knight" }) );
        set_short( "Laice the Captain of Royal Knights", "杀手帮帮主 西门吹血");
	set_long(
		"Laice is the greatest knight Noden Kingdom. His duty is\n"
		"to recurit more adventurers as fighters to defend Noden.\n",
                "西门吹血是杀手帮中最伟大的杀手，他目前是杀手帮的帮主，希望能够\n"
                "招募更多强壮的年青人参加杀手帮的行列，来完成一个重大的使命。\n"
	);
	set_perm_stat("str", 30 );
	set_perm_stat("con", 25 );
        set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "dodge", 100 );
	set_skill( "block", 100 );
	set( "alignment", 1500 );

	set( "race", "human" );
	set( "gender", "male" );

	set( "hit_points", 2000 );
	set( "max_hp", 2000 );
    set( "aim_difficulty",
    	([ "critical":60,"vascular":60,"weakest":60,"ganglion":60 ]) );
	set_natural_weapon( 50, 15, 30 );
	set_natural_armor( 90, 60 );
	set ("special_defense", ([
		"all": 40 , "none" : 50]) );

        wield_weapon( "/d/killer/weapons/bbsword" );
        equip_armor( "/d/killer/armors/silver_plate" );
        equip_armor( "/d/killer/armors/silver_leggings" );
        equip_armor( "/d/killer/armors/silver_gauntlets" );
        equip_armor( "/d/killer/armors/silver_shield" );
        equip_armor( "/d/killer/armors/silver_boots" );
        equip_armor( "/d/killer/armors/silver_helmet" );
}
