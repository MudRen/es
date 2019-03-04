#include <mudlib.h>

#define NEW_AMULET "/obj/amulet2.c"

inherit ARMOR;

int do_fast_in();
int do_check();
int do_help();

void create()
{
	seteuid( getuid() );
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
	object player;
	int fast_login;
	object new_amulet;
	
	player = this_player();
	
	if ( ! player->query_temp("chat_user") ) { 
		write("����û�ڴ�����, ˣ����??\n");
		return 1;
	}
	if (! ( fast_login=player->query("fast_login") ) ) fast_login=5;
	
	// move user to adv guild
	tell_room ( environment(player), player->query("c_name")+
			"���ְ�����ͼ��������ϵ�һ��С��ť, �㷢��������Ӱ����ģ��, �����ʧ�ˡ�\n",
			player);
	write ("�����ְ�����ͼ��������ϵ�һ��С��ť, �����Ӱ����ģ��...��\n");
	player->move_player("/d/adventurer/hall/adv_guild");
	write ("�����Ӱ����һ������, ������ð���߹����С�\n");
	
	// delete temp attributes in lobby
     player->delete_temp("chat_user");
     player->delete_temp("be_sucked");
     player->delete_temp("be_clawed");
     player->delete_temp("be_hoofed");
     
     fast_login --;
     
     //still can use fast login....
     if (fast_login > 0) { 
     	player->set("fast_login",fast_login);
     }
     // can not use fast login anymore....
     else {
     	write ("�����ͼ���������Դ�Ѿ��ľ�, ��Ҳ���ܰ�����ٽ���ES��:~\n");
     	player->delete("fast_login");
     	new_amulet = new(NEW_AMULET);
     	new_amulet->move(player);
     	this_object()->remove();
     }               				
     return 1;	
}		

int do_check()
{	
	object player;
	int fast_login;
	
	player = this_player();
	if (! (fast_login= this_player()->query("fast_login") ) ) {
		fast_login = 5;
		this_player()->set("fast_login",5);
	}	
	write ("�����ͼ������»��ܰ�������ٽ���ES " + fast_login +" �Ρ�\n");
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