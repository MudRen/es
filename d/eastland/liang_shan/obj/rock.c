#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "kick_rock", "kick" );
	add_action( "move_rock", "move" );
	add_action( "move_rock", "push" );
}

void create()
{
	seteuid(getuid());
	set_name("rock","��ʯͷ");
	set_short("��ʯͷ");
	set_long(
		"һ�ŷǳ����ʯͷ�������൱���ء�\n"
	);
   	set("unit","��");
   	set("prevent_get",1);
   	set("weight", 10000);
}
int move_rock()
{
        write("�ⶫ��ʵ��̫���ˣ�����������Ŭ�����޷��ƶ��ֺ�\n");
        return 1;	
}

int kick_rock(string arg)
{
        object st1,st2,st3,st4,st5;
        if( !arg || arg != "rock" ) return 0;
        write("��ǳ���ˬ������������ʯͷ��û�뵽��Ȼһ�Ű���������?\n");
        tell_room( environment(this_player()), 
	this_player()->query("c_name")+
         "�ǳ���ˬ���������ǿ��ʯͷ��û�뵽��Ȼһ�Ű���������?\n"
			, this_player());
	st1 = new("/d/adventurer/natural_history/stone");
	st1->move(environment(this_object()));
	st2 = new("/d/adventurer/natural_history/stone");
	st2->move(environment(this_object()));
	st3 = new("/d/adventurer/natural_history/stone");
	st3->move(environment(this_object()));
	st4 = new("/d/adventurer/natural_history/stone");
	st4->move(environment(this_object()));
	st5 = new("/d/adventurer/natural_history/stone");
	st5->move(environment(this_object())); 
	                                       
	remove();
	return 1;
}

