#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create(){

        set_name( "banana", "�㽶" );
        add( "id", ({ "banana" }) );
        set_short( "�㽶" );
        set_long(@C_LONG
����һ���㽶��������ʮ��������ζ����(eat)�����������
������һЩ����� !!
C_LONG
		);
   		set("unit","��");
   		set("weight", 5);
   		set("value",({40, "silver"}) );
}

int eat_food(string arg)
{
	if( !arg || arg != "banana") return 0;
	write( 
		"�����̻����سԵ�һ���㽶�����óݼ�����...:)\n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"�����¾ͳԵ�һ���㽶���㶼������...\n"
		, this_player()
	);
	this_player()->receive_healing(5);
	remove();
	return 1;
}
