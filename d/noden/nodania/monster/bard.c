#include <mudlib.h>

inherit MONSTER;

void create()
{
	object ob1, ob2, ob3;

	::create();
	set_level(14);
	set_name( "Minaceus", "������˹" );
	add( "id", ({ "minaceus", "bard" }) );
	set_short(  "����ʫ��������˹" );
	set_long(@CLONG
������˹��ŵ����������������ʫ�ˣ������ŵĸ��������������Ӳ�֪��
�����˶����������壬��������Ըһ�����������ڵĵ������У���Ϊ����
Ϊ������û�б��Ĵ����к����ָ�����������¡�
CLONG
	);
	set_perm_stat( "int", 18 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "kar", 22 );

	set( "race", "elf" );
	set( "gender", "female" );
	set( "wealth/silver", 220 );
	set( "alignment", 400 );

	set_skill( "dagger", 90 );
	set_skill( "dodge", 70 );
	set_skill( "parry", 40 );
	set( "natural_armor_class", 55 );
	set( "natural_defense_bonus", 24 );
	set( "natural_weapon_class1", 5 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 8 );

	ob1 = new("/d/noden/nodania/obj/ivory_dagger");
	ob1->move(this_object());
	wield_weapon(ob1);

	ob2 = new("/d/noden/nodania/obj/white_suit");
	ob2->move(this_object());
	equip_armor(ob2);

	ob3 = new("/d/noden/nodania/obj/white_cape");
	ob3->move(this_object());
	equip_armor(ob3);
}
