#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "quaff_potion", "drink" );
	add_action( "quaff_potion", "quaff" );
}

void create()
{
	set_name("wheet wine","�����");
	add( "id" , ({ "wine" }) );
	set_short("�����");
	set_long("��ƿ�ӣ��㿴����͸����ɫ�ľƣ�������Ϊ�㴼....!!\n");
   	set("unit","ƿ");
   	set("weight", 10);
   	set("value",({ 10, "gold" }) );
}

int quaff_potion(string arg)
{
	if(!arg||( arg != "wheet wine" && arg!= "wine") ) return 0;
	write( "��һ�ڹ�����ƿ�ƣ�ֻ������������ƮƮ�ġ�\n");
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"һ�ڹ���һ��ƿ����ƣ�Ȼ��"
		"�㲻�ϵ������������˵Щʲ������!!\n",this_player()
	);
	remove();
	return 1;
}
