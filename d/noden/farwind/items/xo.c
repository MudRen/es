#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "quaff_potion", "drink" );
	add_action( "quaff_potion", "quaff" );
}

void create(){

	set_name("xo","�أ�");
	add( "id" , ({ "wine","xo" }) );
	set_short( "�أ�" );
	set_long( "�أϣ���Ҫ�����𣿺��¾����ˡ�\n" );
   	set("unit","��");
   	set("weight", 10);
   	set("value",({30, "silver"}) );
}

int quaff_potion(string arg)
{

	if( ! id(arg) ) return 0;
	write (
		"�����һ���أϡ��е�ͷ�е����εģ�������һ���˷ܵĸо���\n����˵ó������...\n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"����һ���أϣ�Ȼ����޹޹�ĳ������.....��������!!\n",
		this_player() );

	remove();
	return 1;

}
	
