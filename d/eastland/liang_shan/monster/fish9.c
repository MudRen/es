#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name("pond loach", "泥鳅");
	add("id",({"fish","loach"}) );
	set_short("泥鳅");
	set_long(
		"这是一条细长的鱼，有五对触须，细小的褐斑密布全身，鱼体呈\n"
		"现筒状且布满了黏液，这使得想要徒手抓到它变得相当困难。\n"
	);
	set( "likefish",1);
	set( "unit", "条" );
	set( "alignment", 100 );
	set( "natural_weapon_class1", 3 );
	set( "natural_min_damage1", 3 );
	set( "natural_max_damage1", 6 );
	set("wimpy",8);
	set_perm_stat("dex",16);
	set_skill("dodge",35);
	set_skill("swimming",100);
	set_c_limbs( ({ "头部", "身体", "尾鳍" }) );
	set_c_verbs( ({ "%s张嘴，往%s咬去","%s尾鳍用力一甩，甩向%s" }) );
}

