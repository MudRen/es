#include <almuhara.h>

inherit ROOM;

void create()
{
        ::create();
        set_short( "ͭ������" );
        set_long(
@C_LONG
�������һ������ʯ�ң�ӭ����������������������ͭ�ˣ���
�������ϵ���������Ϯ������������ο���Ҫ���汣����.....
C_LONG
        );


        set( "light",1 );
        set( "exits", ([
                "north" : BRASS"/zeng6"
        ]) );
        set( "pre_exit_func", ([
        	"north" : "pre_north" ]) );
        set( "post_exit_func", ([
        	"north" : "post_north" ]) );
        set( "objects", ([
        	"monk1" : AOBJ"/brassman1",
        	"monk2" : AOBJ"/brassman1",
        	"monk3" : AOBJ"/brassman1" ]) );
        reset();
}

void init()
{
	add_action("do_knock","knock");
	add_action("do_quit","quit");
	add_action("do_auction","auction");
}

int do_knock(string str)
{
	object obj,ob1;
	obj = this_player();
	
	if( !str || str == "" ) return 0;
	if( str == "wall" ) {
		tell_object(obj,
			"ͻȻ���������޺���ǽ�а����߳�������̧�˳�ȥ��\n" );
		ob1=find_object_or_load(SAULIN"/entrance");
		tell_room(ob1,
			sprintf("�㿴�����������޺���%s��̧��һ��̧�˳�����\n",
				obj->query("c_name") ) );
		obj->add("monk_score",-100);
		obj->move_player(SAULIN"/entrance","SNEAK");
		ob1->set("enter",0);
		return 1; }
	else return 0;
}
		
int do_quit()
{
	object obj,ob1;
	obj = this_player();
	
	tell_object(obj,
			"ͻȻ���������޺���ǽ�а����߳�������̧�˳�ȥ��\n" );
	ob1=find_object_or_load(SAULIN"/entrance");
	tell_room(ob1,
		sprintf("�㿴�����������޺���%s��̧��һ��̧�˳�����\n",
			obj->query("c_name") ) );
		obj->add("monk_score",-100);
		obj->move_player(SAULIN"/entrance","SNEAK");
		ob1->set("enter",0);
		return 1;
}

int pre_north()
{
	if ( present("brassman",this_object()) ) {
		write("ͭ�˵������ȥ·��\n");
		return 1; }
	else return 0;
}

int post_north()
{
	reset();
}

int do_auction()
{
	return 1;
}