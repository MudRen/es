
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "Dwarf baby", "����Ӥ��" );
	add ("id", ({ "baby", "dwarf", }) );
	set_short( "Dwarf baby", "����Ӥ��" );
	set_long(
	" a crying baby.\n",
    "һ�����ɴ�޵�СӤ��.\n"
    );
    set( "alignment",10);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "��" );
	set_perm_stat( "kar", 3 );
	set ("natural_weapon_class1", 3);
	set ("natural_armor_class", 7);
	set ("natural_min_damage1", 1);
	set ("natural_max_damage1", 4);
    set ("weight", 100);
   // set ("chat_chance", 25);
	equip_armor(Armour"/amulet03");
}
