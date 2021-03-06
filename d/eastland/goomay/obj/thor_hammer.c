#include <../goomay.h>

inherit Weapon_special;

void create()
{
	set_name( "Thunder's hammer", "雷神之锤" );
	add( "id", ({ "hammer" }) );
	set_short( "雷神之锤" );
	set_long(
		"这是一把金色的巨锤，据说可以发出像雷神一样的威力。\n"
	);
	set( "unit", "把" );
	set( "weight", 250 );
	setup_weapon( "blunt", 45, 25, 45 );
	set( "value", ({ 220, "gold" }) );
        set("no_sale",1);
        set("nosecond",1);
	set("special_attack",(["damage_type" : "electric","main_damage" : 25,
                                "random_damage" : 20 , "hit_rate" : 20]));
//        set("hit_func","special_attack");

set("c_msg","你的雷神之□「轰隆」的一声巨响，发出一道金光，轰击敌人的身体。\n\n");
set("c_enemy_msg","的雷神之□「轰隆」的一声巨响，发出一道金光，闪电般的轰击你 !! \n\n");
set("c_fail_msg","你的雷神之□「轰隆」一声巨响发出一道金光，却轰到你自己 ! \n\n");
set("c_fail_room_msg","的雷神之□「轰隆」一声巨响发出一道金光，却轰到他自己 !\n\n");

}

int fail_to_use()
{
        object ob;
        if ( !(ob = present("thunder's gloves", environment(this_object()) )) ||
                            !(ob->query("equipped")) )
	return 1;
	if ( environment()->query_perm_skill("blunt")<95) return 1;
	return 0;
}

