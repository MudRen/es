#include "../takeda.h"

inherit ROOM;

void create()
{
	::create();
        set_short("��ֵĶ�Ѩ");
	set_long( @LONG_DESCRIPTION
��һ̤������ط���ȫ��Ī�����о���һ���泩�ĸо����������а����Ϣ
��ȫ��ͬ���������ǰ��һ��޴��ʯ�� (stele)�����������൱�����ˣ���Ȼ
�ұ��ϻ����ٵ���Щ��̦����ʯ������ȴ�ǹ���쳣?
LONG_DESCRIPTION
	);

	set( "c_item_desc", ([ 
		"stele" : @LONG_TEXT
���ߵ�ʯ��ǰ����ϸ�Ĺ۲����ı��棬������������ֵ����֣�����
�����ִ���κ�һ�֡���Լ����ĳߵĵط�����һ��[��]�͵İ�����ּǺ�
(mark)��
LONG_TEXT
, 
		"mark" : @LONG_TEXT
����ϸ�ļ������Ǻţ��������Ǻ�����Ĳ��ʸ�ʯ�������е㲻һ��?
���ǹ⿴�ǲ���֤������뷨...		
LONG_TEXT
 ]) );
	set( "drag_appear",0 );
	set( "exits", ([ 
		"south" : TROOM"lair/lair2" ]) );
}


void init()
{
	add_action( "do_touch", "touch" );
}

int do_touch(string arg)
{
	object dragon;
	if( !arg || arg!= "mark" ) return 0;
        if ( present("dragon") ) return 0;
        if ( query("drag_appear") ) {
        tell_object(this_player(),
        "������������Ǻţ�һ�����˵�������������ĳ���: �����ӣ�һ�ж�̫����....��\n"); 
        return 1;
        }
        tell_object(this_player(),
        "������������Ǻţ�һ��ׯ�ϵ�������������ĳ���: �����ӣ��ҵ���ܾ���....��\n"
        "�����������ҵ���??\n");
        tell_room( this_object(), 
        "ͻȻһ����ҵĲ�����һ���޴������ͻȻ����������ǰ....\n"
		 );
	set( "drag_appear",1 );
	dragon =new(TMONSTER"drag");
	dragon->move(TROOM"lair/lair3");
	return 1;
}
int clean_up() { return 0; }