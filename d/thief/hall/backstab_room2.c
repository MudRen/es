#include <mudlib.h>
#include "../thief.h"
inherit ROOM;
#define TEST_ROOM "/d/thief/hall/backstab_room"
init()
{
	add_action("do_auc","auction");
	add_action("do_quit","quit");
}

do_auc()
{
	tell_object(this_player(),"�㲻����������н���!!\n");
	return 1;
}

do_quit()
{
	TEST_ROOM->delete("begin_test");
	TEST_ROOM->delete("tester");
	TEST_ROOM->set("using",0);
        tell_object(this_player(),
                "һ������˵�� : ������? �ð�, �´������Կ����ܱȽϺá�\n");
//	TAYLERS->chat("����ѶϢ\n");
	return 1;
}

void create()
{
	::create();
	
	set("light", 1);
	set_short( "���̲�����" );
	set_long( @LONG
����һ����ķ��䣬����\��\���˴��СС�����ӣ����ʺϲ���
��ר�����������Ϊѵ�����ġ�
LONG
	);

	set("exits", ([
		"north" : "/d/thief/hall/pathway",
		"south" : TEST_ROOM,
	]) );
	set("pre_exit_func",([
		"north" : "pass_test" ]) );
	reset();

/*
create_door("north","south",([
             "keyword" : ({"door" }),
             "status" : "locked",
             "c_desc" : "һ�Ƚ�ʵ���ص�����",
             "c_name" : "����",
             "name":"iron door",
             "desc":"an iron door",
             "lock" : "backstab_room2",
              ]) );

*/	
}

int pass_test()
{
	object *inv;
	int i;
	if ( present("maskman",this_object()) ) {
		tell_object(this_player(),
		"���������ְ�����ס��������ͨ����\n");
		return 1;
	}
	if ( !this_player()->query_temp("pass_test") )	return 0;
	this_player()->delete_temp("pass_test");
	this_player()->delete_temp("skip_dead");
	this_player()->add("thief_level/backstab",1);

	TEST_ROOM->delete("begin_test");
	TEST_ROOM->delete("tester");
	TEST_ROOM->set("using",0);

	tell_object(this_player(),
		"���˷ܵش������š�\n"
		"������ε�ս��ѵ������ı��������������˵� "+this_player()->query("thief_level/backstab")+" �� !!\n");
	TAYLERS->chat("��ϲ" + this_player()->query("c_name") + "ͨ�����̲��� !!");
	return 0;
}

