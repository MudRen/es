// This is a standard healing potion. 
// Created by Annihilator@Eastern.Stories 11-22-93
#include <mudlib.h>

inherit OBJECT;

void create()
{
        seteuid(getuid());
        set_name( "chinese beer", "����Ů����" );
        add( "id",({ "beer" }) );
        set_short( "����Ů����" );
        set_long(
            "������һ�����ϵĹ��������µ����ơ�\n"
        );
        set("layuter_beer",1);
        set( "unit", "ƿ");
        set( "weight", 10 );
        set( "value", ({ 20, "gold" }) );
}


void init()
{
	add_action( "drink_beer", "drink" );
}

int drink_beer(string arg)
{
	int kar, heal;
	string unit;

	if( !arg || (arg!="beer") ) return 0;
	if( environment() != this_player() )
		return notify_fail("������û������������\n");
	write("�����һ����һƿ����Ů���졣\n");
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"����һƿ����Ů���졣\n",
		this_player() );
	heal = 20;
	this_player()->receive_healing( heal );
	remove();
	return 1;
}
