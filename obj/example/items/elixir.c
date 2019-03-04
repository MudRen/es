// An elixir of healing.
// Drink this and you get some hits back, you lucky dog.
// It doesn't leave a bottle behind because otherwise empty bottles tend
// to clutter up memory. If you've got RAM to spare, then you might want
// to make an empty bottle object to leave behind. Or maybe not. Who really
// wants two dozen empty bottles?
// Written by Mobydick, 11-20-92.
// Remove this header and the fleas of a thousand camels will infest
// your armpits.

#include <mudlib.h>

#define HEALING 15

inherit OBJECT ;

void create()
{
	set_name( "elixir", "ҩˮ" );
	add ("id", ({ "potion" }) );
	set_short( "an elixir of healing", "�ָ�ҩˮ" );
	set_long(
		"An elixir of healing, which can heal some wounds if you drink it.\n",
		"�ָ�ҩˮ���ú�(drink)�ġ�\n"
	);
	set ("weight", 50);
	set ("value", ({ 30, "gold" }) );
}

void init()
{
	add_action ("drink", "drink") ;
}

int drink (string str)
{
	int old_hp, chinese_mode;

	chinese_mode = can_read_chinese();
	if (!str || !id(str))
		return notify_fail(chinese_mode?"��ʲ�᣿\n":"What would you like to drink?\n") ;

	if( chinese_mode)
		write( "����»ָ�ҩˮ֮�ᣬƿ��ͻȻ����һ��������ʧ�ˡ�\n");
	else
		write( "You drink the elixir of healing.\n"
		"As you drink the last drop, the bottle vanishes in a puff of smoke!\n");
	old_hp = this_player()->query("hit_points");
	this_player()->receive_healing( HEALING );
	if( old_hp < this_player()->query("hit_points") )
		write(chinese_mode?"����úö��ˡ�\n":"You feel better!\n");
	remove();
	return 1;
}
