#include <mercury.h>

inherit ROOM;

void create()
{
	::create();
	set_short("ǧ��¥ǰͥ");
	set_long(@AAA
������ǧ��¥��ǰͥ���ڵ�·��������ֲ��һ���ŵĹ�ľ������һ����һ
������һ�Եľ������񣬶���·����߻���һ������Ȫ����ֵ��������Ȫ��
��Ȼ��û�г���̦���ɼ���ɨ�˵����ͣ�	
AAA
	);

	set_outside( "eastland" );
	set( "search_desc",([
	     "here":@AAA
����������ϸ����֮�ᣬ���������Ȫ(fountain)�ֵֹģ�����
AAA
]));
	set( "c_item_desc", ([ 
		"fountain" : @LONG_TEXT
�����Ȫ����ϸ�۲�֮�ᣬ������Ȫˮ������ƺ���һ����ɫ��
����ǰ壬���������Ǳˮ(dive)��ȥ������
LONG_TEXT
 ]) );
	set( "exits", ([ 
		"north" : MR"inn02", 
		"south" : MR"cac08" ]));
	set( "water_source",1 );
	reset();
}

void init()
{
	add_action( "do_dive", "dive" );
}

int do_dive(string arg)
{
	if( !arg || arg == "" || arg!="fountain" ){
		tell_object( this_player(), "��ҪǱȥ����ѽ��\n" );
	        return 1;
	} 
        if( random( (int)this_player()->query_skill("swimming") ) < 5 ) {
		write( "����Ǳ����Ȫ��ȴ����Ȫ��ˮ�������˻���\n" );
		return 1;
	}
	write( "�����Ǳ����Ȫ�ײ�����Ȼ�������ϣ���Ȫ�»���һ��ͨ��\n"
		 );
	this_player()->move_player( MR"tube01", "SNEAK" );
        this_player()->set_explore("island#11");
	return 1;
}

