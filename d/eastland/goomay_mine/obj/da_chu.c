#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "quaff_potion", "drink" );
	add_action( "quaff_potion", "quaff" );
}

void create()
{
	set_name("da chu","�������");
	add("id" ,({"wine","chu"}) );
	set_short( "�������");
	set_long(@LONG
�����������׳Ƶģ�����ͷ����ΪҪ�������η��ͣ�ߢȡ�����ľ������ƾ�
Ũ��Ҳ�ر�ߣ��ڰٷ�֮��ʮ���ϣ�һ������Ũ�Ҷ�������ڵ�
LONG
);
   	set("unit","��");
   	set("weight", 50);
   	set("value",({100, "silver"}) );
}

int quaff_potion(string arg)
{
	if( !arg || arg != "da chu" ) return 0;
	write( "�����һ������ͷ���е�ȫ��ʼ���̣�������һ�����µĸо���\n"
	       "�㿪ʼ����ץ���ӣ�\n");
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"����һ������ͷ��Ȼ��"
		"��ʼ�ڵ��ϵ�����������֪������ʲ�᣿\n" , this_player()
	);
	remove();
	return 1;
}
