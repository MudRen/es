#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
        set_name( "apple", "ƻ��" );
        add( "id", ({ "apple" }) );
        set_short( "ƻ��" );
        set_long(@C_LONG
����һ����ƻ����������ʮ��������ζ����(eat)�����������
������һЩ����� !!
C_LONG
		);
   		set("unit","��");
   		set("weight", 10);
   		set("value",({40, "silver"}) );
}

int eat_food(string arg)
{
	if( !arg || arg != "apple") return 0;
	write( "�����̻����ؿе���һ��ƻ�������óݼ�����...:)\n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"�����¾Ϳе���һ��ƻ�����㶼������...\n"
		, this_player()
	);
	this_player()->receive_healing(5);
	remove();
	return 1;
}
