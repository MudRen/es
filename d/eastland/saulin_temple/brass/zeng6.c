#include <almuhara.h>

inherit ROOM;

void create()
{
        ::create();
        set_short( "ͭ������" );
        set_long(
@C_LONG
�������һ����С��ʯ�ң��������ܿ���һ�ֻ����ǽ�Ϲ�����
����(scroll)���Լ��Ա��и����(teapot)����������������ô��ص�
��������Ϣ֮�ã��ھ����˸ղŵĴ�ս�ᣬ�㲻���м�����������Ƶ�
�ˡ�
C_LONG
        );


        set( "light",1 );
        set( "exits", ([
                "north" : BRASS"/zeng7"
        ]) );
        set( "post_exit_func", ([
        	"north" : "post_north" ]) );
        add( "item_desc", ([
        	"scroll" :
"�� !! ���Ѿ�ͨ��ǰ�����ˣ��൱���� !! 
��һ�����ڿ��������ʮ��������\��\��������׼��������ǰ�ߡ�\n",
		"teapot" :
"һ��СС�Ĳ����Ҳ\��\����ԺȺ�ˮ(drink water)����Ϣһ�¡�\n"
	]) );  
        reset();
}

void init()
{
	add_action("do_knock","knock");
	add_action("do_quit","quit");
	add_action("do_auction","auction");
	add_action("do_drink","drink");
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
		obj->delete_temp("drink_already");
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
		obj->delete_temp("drink_already");
		obj->move_player(SAULIN"/entrance","SNEAK");
		ob1->set("enter",0);
		return 1;
}

int do_drink(string str)
{
	object obj;
	obj = this_player();
	
	if(!str || str == "") return 0;
	if( str == "water" ) {
		if( !obj->query_temp("drink_already") ) {
			tell_object(obj,
				"����һ��ˮ�������ȫ��һ��������\n" );
			obj->add("medication_resistance",-300);
			obj->set_temp("drink_already",1);
			return 1; }
		tell_object(obj,
			"�ٺ�һ��ˮ������ú���ûʲ�����ˡ�\n" );
		return 1; }
	else return 0;
}

int post_north()
{
	this_player()->delete_temp("drink_already");
}

int do_auction()
{
	return 1;
}