#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "Gnome baby", "�ؾ�Ӥ��" );
	add ("id", ({ "baby", "gnome" }) );
   set_short( "�ؾ�Ӥ��" );
	set_long(
                  "һ������ƨ������ѧ����СӤ��.\n"
                 );
        set( "alignment",10);
        set( "gender", "male" );
        set( "race", "gnome" );
        set( "unit", "��" );
	set_perm_stat( "kar", 3 );
	set ("natural_weapon_class1", 3);
	set ("natural_armor_class", 7);
	set ("natural_min_damage1", 1);
	set ("natural_max_damage1", 4);
        set ("weight", 100);
//      set ("chat_chance", 25);
	equip_armor(ARMORS"amulet_g01");
}
