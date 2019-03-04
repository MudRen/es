#include <mudlib.h>

inherit MONSTER;

void create()
{
	object ob1, ob2, ob3;

	::create();
	set_level(5);
	set_name( "squire", "���" );
	set_short( "���" );
	set_long(@CLONG
����������ڵȺ�������������������Կ�������ʱ�����������
�̽��ó������á�
CLONG
	);
	set_perm_stat( "pie", 7 );
	set_perm_stat( "kar", 7 );
	set( "race", "human" );
	set( "gender", "male" );
	set( "wealth/silver", 20 );
	set( "unit", "��" );
	set( "alignment", 400 );

	set_skill( "shortblade", 40 );
	ob1 = new("/d/knight/fortress/weapons/shortsword");
	ob1->move(this_object());
	wield_weapon(ob1);
	ob2 = new("/d/noden/nodania/obj/feather_hat");
	ob2->move(this_object());
	equip_armor(ob2);
	ob3 = new("/d/noden/nodania/obj/ring_mail");
	ob3->move(this_object());
	equip_armor(ob3);
}
