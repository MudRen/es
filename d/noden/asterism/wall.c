// File: /d/noden/asterism/wall.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("ɽ��");
	set_long(
		@C_LONG_DESCRIPTION
���߳�����Ƭ���֡�����������Ȼ��������Ķ��ߣ��þò�ɢ����������
����ǰ����һƬ�⻬�ҽ�����ֱ��ɽ�ڡ�
C_LONG_DESCRIPTION
	);

        set("c_item_desc" , ([
                 "wall" : "��Ƭɽ�ڷǳ�ƽ��,����Ψһ��ֵĵط���."
                          "���������ĸ���;�����Ķ���\n"
                          ]) ) ;
	set_outside( "asterism" );
//	set( "light", 1 );
	set( "exits",([ 
		"north" : ASTR"path4",
		]) );
        
	reset();
}
