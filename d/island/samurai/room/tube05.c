
#include <mercury.h>

inherit ROOM;

void create()
{
	::create();
	set_short("ǽ������");
	set_long(@AAA
����һ��ǽ���ڵ����ң�ǽ�Ϲ�������ŵ�ͼ������ϸ�ۿ�һ�·�����
Щ��ͼ���⸽�������ս���ֲ�ͼ��������ס�ڴ˵���һ������ʿ�ŵ���Ҫ
�����Ȼ��������ӵ������Щ�������ϣ���������һ�ŵ�ͼ(map) ������
��������Ҫ���ľɣ���������࣮ܶ	
AAA
	);
        set("light",1);
        set("objects",([
        "kola":MOB"kola"
        ]));
	set( "c_item_desc", ([ 
		"map" : @LONG_TEXT
���ŵ�ͼ����ϸ�۲�֮�ᣬ���ֵ�ͼ���滹��һ����ť(button)���ƺ���
�԰�����(push)
LONG_TEXT
 ]) );
	set("exits",([
	   "out":MR"tube04"
	   ]));
	reset();
}

void init()
{
	add_action( "do_push", "push" );
}

int do_push(string arg)
{
	if( !arg || arg!="button" )
		return notify_fail( "����������ѹ����ָѹ����ָ�����Ұ���\n" );
	write("��һ����ť���컨��Ϳ���һ�����ڣ������һ�����������������\n"
		 );
	this_player()->move_player( MR"cac05", "SNEAK" );
	return 1;
}

