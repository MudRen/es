
#include "../layuter.h"

inherit ROOM;
int knife_control;
  
void create()
{
	::create();
	set_short("���³�");
	set_long( @C_LONG_DESCRIPTION
�˴���һ�����ϵĵ��³Ƿ��䣬�˴���ǽ�ڼ��ذ嶼���Դ���ʯ����ɵ�ͬʱǽ����
�м�ֻ���ȼ����������������浽����������\�������飬�Լ�һ�������\����ֵ���
�����ӣ�����������һ����̳�����ӵĶ�����һ�����ӣ������\��һЩ�����ͷ���Լ���
װ����ȥ��������С�������Ĺ��ӣ���������һ�����ξ�����������ǰ�ж�ḻ����
�о��飬������μ����ⷿ��ʱ���������о����ĸо���
C_LONG_DESCRIPTION
	);
	set("item_desc",([
	    "table":"����һ����\����ʽ�������ض���������,������Ʒ����һ���������صĹ�â\n"])); 
	set( "light", 1 );
	set( "exits", ([
		"south" : Lcave"cave15"
	]) );
	set("objects",([
	    "flamen" : Ldmonster"flamen"])); 
	reset();
}

void init()
{
 add_action("do_search","search");
 }
void reset()
{
	::reset();
	knife_control=1;
}

int do_search(string arg)
{
	object obj;

	if( !arg || arg!="table" )
		return notify_fail( 
		"����������������ȥ������û���ҵ��κ����صĶ�����\n"
		);
	if( knife_control ) {
		write( 
			"����ϸ�������ӣ�����ҵ�һ�����صĲ��ӡ�\n"
		);
		obj = new(Lditem"shovel");
		obj->move(this_object());
                this_player()->set_explore("eastland#2");
		knife_control = 0;
		return 1;
	} else {
		write( 
			"����������Ӷ������ˣ���û�з����κ����صĶ�����\n"
		);
		return 1;
	}
}
