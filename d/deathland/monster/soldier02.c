#include "../echobomber.h"

inherit MONSTER;

void create ()
{
        object ob1,ob2;

	::create();
	//seteuid( getuid() );
 set_level(12);
 set_name("dwarf scout","���˳��"); 
 add ("id", ({ "scout","dwarf"}) );
 set_short( "���˳��");
	set_long(@LONG
�Ⱛ�˳�����ڽ����ϸ����ѵ��.
LONG
	);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "��" );
    set_perm_stat( "dex",13);
    set_perm_stat( "str",15);
    set_perm_stat( "int",8);
    set_perm_stat( "con",20);
    set_perm_stat( "piety",8);
    set_perm_stat( "karma", 10);
	
    set ("max_hp",340);
    set ("max_sp",0);
    set ("hit_points",340);
    set ("spell_points",0);
    set ("wealth", ([ "gold":3]) );
    set_natural_weapon(11,7,10);
	set_natural_armor(45,11);
    set ("weight", 350);
    equip_armor(Armour"/chainmail02");
    wield_weapon(Weapon"/spear03");;
}


