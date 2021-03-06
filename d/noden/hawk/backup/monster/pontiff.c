#include <mudlib.h>

inherit MONSTER;

void create()
{
	object ob1, ob2, ob3, ob4;

	::create();
	set_level(16);
	set_name("Juraken", "裘拉根");
	add( "id", ({"pontiff"}) );
	set_short("锡卡拉教大祭司 裘拉根");
	set_long(@CLONG
这个叫做裘拉根的人长得很高，一脸精悍神色，他的脸上从鼻子到耳朵有一
道很可怕的伤痕。当你和他的目光相遇的时候，一股莫名的寒意使你清楚的
了解到: 这家伙是个不简单的人物。
CLONG
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", -1500 );
	set( "natural_armor_class", 30 );
	set( "natural_defense_bonus", 20 );
	set( "natural_weapon_class1", 10 );
	set( "natural_min_damage1", 10 );
	set( "natural_max_damage1", 10 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 30 );
	set_skill( "blunt", 100 );
	set_skill( "dodge", 90 );

	ob1 = new( "/d/noden/hawk/obj/crimson_scepter" );
	ob1->move( this_object() );
	wield_weapon( ob1 );

	ob2 = new( "/d/noden/hawk/obj/crimson_robe" );
	ob2->move( this_object() );
	equip_armor( ob2 );

	ob3 = new( "/d/noden/hawk/obj/crimson_amulet" );
	ob3->move( this_object() );
	equip_armor( ob3 );

	ob4 = new( "/d/noden/hawk/obj/crimson_ring" );
	ob4->move( this_object() );
	equip_armor( ob4 );
}
