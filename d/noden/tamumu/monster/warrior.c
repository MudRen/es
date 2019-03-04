#include <mudlib.h>

inherit MONSTER;

void create()
{
	object ob1, ob2;

	::create();
	set_level(11);
	set_name( "tamumu warrior", "��ķķսʿ" );
	add( "id", ({ "warrior", "tamumu" }) );
	set_short( "��ķķսʿ" );
	set_long(
	"��λ��ķķսʿ�ý����������Ӧ���ע�ӣ�������ķķ���й��ϵ���ʿ��\n"
	);
	set( "unit", "��" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -500 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 13 );
	set_perm_stat( "int", 8 );
	set_perm_stat( "pie", 9 );
	set_skill( "blunt", 70 );
	set_skill( "parry", 70 );
	set_skill( "block", 85 );

	set( "wealth/silver", 100 );
	set( "aggressive", 1 );

	ob1 = new( "/d/noden/tamumu/obj/club" );
	ob1->move( this_object() );
	wield_weapon( ob1 );

	ob2 = new( "/d/noden/tamumu/obj/shield" );
	ob2->move( this_object() );
	equip_armor( ob2 );
}
