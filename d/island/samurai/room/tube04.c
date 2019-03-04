
#include <mercury.h>

inherit ROOM;

void create()
{
	::create();
	set_short("��������");
	set_long(@AAA
������һ��������ң��㿪ʼȷ�������ˮ����һ�����˾�ס����
�ⷿ�ӵļҾ߰����������������һ���Ǹ��ڼ���ˣ�����Ҳ�е����
��Ϊ�������Ҫ�㵽������ס�أ����������и���ֵİ���(lever) ��	
AAA
	);
        set("light",1);
	set( "c_item_desc", ([ 
		"lever" : @LONG_TEXT
�����������ϸ�۲�֮�ᣬ���ֺ������������(pull)
LONG_TEXT
 ]) );
	set( "exits", ([
		"south" : MR"tube03" ]));
	reset();
}

void init()
{
	add_action( "do_pull", "pull" );
}

int do_pull(string arg)
{
	if( !arg || arg!="lever" )
		return notify_fail( "��Ҫ��ɶѽ?\n" );
	write("��һ�����֣�ǽ�ھ��ѿ�һ�����ڣ����������ǽ������\n"
		 );
	this_player()->move_player( MR"tube05", "SNEAK" );
	return 1;
}

