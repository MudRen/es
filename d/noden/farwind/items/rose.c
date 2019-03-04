#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "quaff_potion", "drink" );
	add_action( "quaff_potion", "quaff" );
}

void create(){

	set_name("Rose wine","õ����");
	add( "id" , ({ "rose","wine" }) );
	set_short( "õ����" );
	set_long( "���Ǵ���ɳ�����˴�������õ����\n" );
   	set("unit","��");
   	set("weight", 10);
   	set("value",({20, "silver"}) );
}

int quaff_potion(string arg)
{

	if( arg != "rose" ) return 0;
	write( can_read_chinese()?
		"�����һ��õ���ƣ��е�ʮ�ֵ������\n":
		"You drink a cup of Rose Red wine....\n"
	);
	tell_room( environment(this_player()), ({
		this_player()->query("cap_name")+" drink an nice chinese wine....\n",
		this_player()->query("c_cap_name")+"����һ��õ���ƣ�����ر����۾����������������ӡ���\n"}),
		this_player() );

	remove();
	return 1;

}
	
