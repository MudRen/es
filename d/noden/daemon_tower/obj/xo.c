#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "quaff_potion", "drink" );
}

void create()
{
#include <compress_obj.h>
	set_name("xo","�أ�");
   	add( "id" , ({ "wine" }) );
	set_short("�أ�");
	set_long("�أϣ���Ҫ�����𣿺��˾����ˡ�\n");
   	set("unit","��");
   	set("weight", 10);
   	set("value",({30, "silver"}) );
}

int quaff_potion(string arg)
{
	if( !arg || !id(arg) ) return 0;
	write(@ALONG
�����һ���أϡ��е�ͷ�е����εģ�������һ���˷ܵĸо���
����˵ó������...
ALONG
 	        );
	tell_room( environment(this_player()),
		this_player()->query("c_name")+"����һ���أϣ�Ȼ����޹"
		"޹�ĳ������.....��������!!\n" , this_player()
	);
	remove();
	return 1;
}
