
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name( "bard", "����ʫ��" );
	add("id",({"bard",}));
	set_short( "a bard", "����ʫ��" );
	set_long(
	"һ�����˵�����ʫ��,�Դ������������ƽ�����ĵط���,������Ҳû���뿪��.\n"
	);
	set("alignment",-200);
	set_perm_stat( "dex", 10 );
	set_perm_stat( "str", 5 );
	set_perm_stat( "int", 11 );
	set_perm_stat( "con", 5 );
	set_perm_stat( "piety", 4);
	set_perm_stat( "karma", 11);	
	set ("max_hp", 155);
	set ("hit_points", 155);
	set( "race", "elf" );
	set( "gender", "male" );
	set("natural_armor_class",22);
	set("natural_defense_bonus",5);
	set_skill("dagger",43);

	wield_weapon(Weapon"/dagger01");
	equip_armor(Armour"/cloth04");
}
