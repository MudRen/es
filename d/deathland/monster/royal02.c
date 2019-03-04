#include "../echobomber.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(16);
    set_name("dwarf royal guard","���˻�������");
    add ("id", ({ "guard","dwarf"}) );
    set_short( "a drawf royal guard",
           "���˻�������");
	set_long(@LONG
A drawf guard protects the dwarven palace.
LONG
    ,@C_LONG
һ�����˻������������������˻ʹ��Ĵ�����
C_LONG
	);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "��" );
    set_perm_stat( "dex",  21);
    set_perm_stat( "str",  23);
    set_perm_stat( "int",  11);
    set_perm_stat( "piety",11);
    set_perm_stat( "karma",21);
	set_skill("longblade",100);
	set_skill("parry",96);
	set_skill("dodge",88);
	set("special_defense",(["all":20,"none":10]) );
    set("aim_difficulty",([ "vascular":20,"weakest":20]) );
    set ("max_hp",500);
    set ("max_sp",0);
    set ("hit_points",500);
    set ("spell_points",0);
    set ("wealth", ([ "gold":13]) );
    set_natural_weapon(13,10,12);
	set_natural_armor( 77 , 22 );
    set ("weight", 350);
    equip_armor(Armour"/gloves01");
    wield_weapon(Weapon"/sword02");

}


