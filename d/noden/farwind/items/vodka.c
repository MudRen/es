#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "quaff_potion", "drink" );
	add_action( "quaff_potion", "quaff" );
}

void create(){

	set_name("vodka","���ؼ�");
	add( "id" , ({ "vodka","wine" }) );
	set_short( "���ؼ�" );
	set_long("�ô̱ǵľ�...һ������!!\n");
   	set("unit","ƿ");
   	set("weight", 10);
   	set("value",({30, "silver"}) );
}

int quaff_potion(string arg)
{

	if( ! id(arg) ) return 0;
	write( 
		"�����һƿ���ؼӣ��е�����������������\n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"һ�ں���һƿ���ؼӣ�Ȼ����������ͨ���ɵЦ����!!\n",
		this_player() );

	remove();
	return 1;

}
	
