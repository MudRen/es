#include <mudlib.h>

inherit ARMOR;

int do_fast_in();
int do_check();
int do_help();

void create()
{
	set_name( "workshop amulet","������ֻ��������" );
	add("id",({"amulet"}));
	set_short( "������ֻ��������" );
	set_long(@Long
����1996 M.U.D. workshop ���͵��������Ʒ, �����и�Ư����
���߶�����Mark�����湲������С��ť, �ֱ��ʾ��(help), (login),
�Լ� (check), ����㲻������ǵĹ���, �������Ȱ�(press) help 
����������
Long
	);
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "weight", 7 );
	set( "armor_class", 0 );
	set( "defense_bonus", 4 );
	set( "prevent_drop",1);
	set( "prevent_get",1);
	set( "prevent_insert",1);
}

int query_auto_load()
{
	return 1;
}

void init()
{
	add_action("do_press","press");
}

int do_press(string arg)
{
	if (!arg) return notify_fail("��Ҫ��ʲ��?\n");
	if (arg == "login") do_fast_in();
	else if (arg == "check") do_check();
	else if (arg == "help") do_help();
	else return notify_fail("��Ҫ��ʲ��?\n");
	return 1;
}
int do_fast_in()
{
	tell_room ( environment(this_player()), this_player()->query("c_name")+
			"���ְ�����ͼ��������ϵ�һ��С��ť, ��ʲ����Ҳû������\n",
			this_player());
	write ("�����ְ�����ͼ��������ϵ�һ��С��ť, ��ʲ����Ҳû������\n");
	
     return 1;	
}		

int do_check()
{	
	write ("�����ͼ��������Ѿ�û����Դ������ٽ���ES�ˡ�\n");
	return 1;
}

int do_help()
{
	write(@Help
���������ֻ�������³��˿��Ե���һ��ķ���ʹ����, �����԰�����
���ٽ��뿪������, ʹ�÷�������:
press check: �����������е��������ܰ�����login���Ρ�
press login: �������� ES ��������
�����������е�����������, �����Կɵ���һ��ķ���ʹ��, ������quit
�᲻����ʧ��
Help
	);
}	