#include "../echobomber.h"

inherit MONSTER;

void create ()
{
	::create();
	//seteuid( getuid() );
 set_level(7);
 set_name("dwarf new_trained soldier","�����±�");
add ("id", ({ "soldier","dwarf"}) );
set_short( "a dwarf soldier",
           "�����±�");
	set_long(@LONG
a new trained soldier,looks very young.
LONG
    ,@C_LONG
�������ǳ�������±�սʿ.
C_LONG
	);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "��" );
    set_perm_stat( "dex",8);
    set_perm_stat( "str",9);
    set_perm_stat( "int",5);
    set_perm_stat( "con",12);
    set_perm_stat( "piety",8);
    set_perm_stat( "karma", 8);
	
    set ("max_hp",200);
    set ("max_sp",0);
    set ("hit_points",200);
    set ("spell_points",0);
    set ("wealth", ([ "gold":1]) );
    set_natural_weapon(7,1,4);
	set_natural_armor(22,0);
    set ("weight", 350);
    equip_armor(Armour"/chainmail03");
    wield_weapon(Weapon"/spear02");
}


