#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "drink_tea", "drink" );
}

void create()
{
	set_name("diet tea","���ʲ�");
	add( "id" , ({ "tea" }) );
	set_short("diet tea" , "���ʲ�");
	set_long(".." , 
		"����һ�����صĲ裬���̵Ĳ�ˮ��ɢ��һ����Ũ���ķҷ�������\n"
		"��֮ʹ�㾫�����\n"
	);
   	set("unit","��");
   	set("weight", 20);
   	set("value",({ 10000, "copper" }) );
}

int drink_tea(string arg)
{
	if( !arg || arg != "tea" ) return 0;
	else {write( "��������Ʒ���Ɑ���ʲ裬��Ȼһ����ֵ�����ӵ��￪ʼ������ȫ��...:)\n" 
		);
		tell_room( environment(this_player()), (
			this_player()->query("c_cap_name")+"����һ�����ʲ裬Ȼ��¶����ֵı���"
			"����ע�⵽����������������\n" ), this_player()
		);
		this_player()->receive_healing( -15+random(5) );
	}
	remove();
	return 1;
}

