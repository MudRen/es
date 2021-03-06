#include "../takeda.h"
inherit MONSTER;

void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(12);
	set_name("Pang", "阿香");
	add ("id", ({ "pang", "Pang" }) );
	set_short("阿香");
	set_long(
		"一个肥胖丑恶的老女人，因为嫁不出去，所以常把怨气出\n"
		"在洗衣房的长工们，虽然大家都很讨厌她，可是没人敢起\n"
		"来反抗她，你注意到她的右颊上长了一颗又大又黑的痣，\n"  
		"上面的一撮黑毛，令人觉得恶心，你想，这大概是她嫁不\n"
		"出去的原因吧．\n");
	set_perm_stat("dex", 15);
	set_perm_stat("kar", 15);
	set_perm_stat("str", 15);
	set_skill( "dodge", 60 );
	set( "max_hp", 350 );
	set( "hit_points", 350 );
	set( "gender", "female" );
	set( "race", "daemon" );
	set( "alignment", -800 );
	set_natural_armor( 30, 15 );
	set_natural_weapon( 30, 10, 25 );
}

