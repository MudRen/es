#include <mudlib.h>

inherit MONSTER;

void create()
{
        object ob1, ob2;

        ::create();
        set_level(19);
        set_name( "flesheater", "肉食兽" );
        set_short( "肉食兽" );
        set_long(@C_LONG
哇咧....这家伙到底是从哪里来的怪物？它看起来像是人类，可是你百分之百
肯定它不是人！看来遇到它算是你倒楣了....。
C_LONG
                );
        set( "unit", "只" );
        set( "max_hp", 600 );
        set( "hit_points", 600 );
        set_perm_stat( "str", 28 );
        set_perm_stat( "dex", 25 );
        set_skill( "shortblade", 100 );
        set_skill( "parry", 100 );
        set_skill( "dodge", 100 );
        set( "killer", 1 );
        set( "pursuing", 1 );
        set( "alignment", -1800 );
        set( "natural_armor_class", 90 );
        set( "natural_defense_bonus", 20 );
        set( "natural_weapon_class1", 40 );
        set( "natural_min_damage1", 10 );
        set( "natural_max_damage1", 35 );
        set( "natural_weapon_class2", 30 );
        set( "natural_min_damage2", 10 );
        set( "natural_max_damage2", 25 );

        ob1 = new( "/d/noden/tamumu/obj/claw" );
        ob1->move( this_object() );
        wield_weapon( ob1 );

        ob2 = new( "/d/noden/tamumu/obj/amulet" );
        ob2->move( this_object() );
        equip_armor( ob2 );
}

void init()
{
        add_action("to_control","control");
}

int to_control(string str)
{
	object master, pet_flesh;

	master = this_player();

        if ( !str || str != "flesheater")
                return 0;

        if (this_player()->query_temp("control_flesh") != 1)
                return 0;
        this_player()->set_temp("control_flesh",2);
        tell_object(this_player(),@LONG
你成功的驯服了肉食兽。现在它正像条温驯的小猫般跟在你的左右。
LONG
        );
	tell_room(environment(this_object()),this_player()->query("c_name")+
		"成功的驯服了肉食兽。\n",this_player() );
	if( this_player()->query_temp("now_pet") )
        	return notify_fail("对不起, 你已经带了宠物在身边了。\n");
	if( this_player()->query_temp("now_guard") )
        	return notify_fail("对不起, 你的侍卫似乎看肉食兽不顺眼。\n");
	master->set_temp( "now_guard", 1 );
	pet_flesh = new("/d/noden/tamumu/monster/flesh1" );
	pet_flesh->set_master( master, this_object() );
	pet_flesh->move( environment(master) );
	this_object()->remove();
        return 1;
}
