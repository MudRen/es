// File: /d/noden/asterism/lib01.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("ͼ��ݴ���");
	set_long( 
		@C_LONG_DESCRIPTION
�����ǰ�˹���ɶ�(asterism)�ǵ�ͼ��ݴ�����������ħ��һս�������
ͼ��ݼ����ݻٴ��������ڰ����˵�����֮�£��µĽ������˸о������ո���
ʱ�ڵİ����ʽ�����������ƴ���ǽ�Ϲ���һ�����Ļ����տ������еĲι���
���ȿ���������ÿ���˶��������������µ����ն���������ϸ�������е�
���������������ռ��еĽŲ�����
C_LONG_DESCRIPTION
	);

//	set_outside( "asterism" );
	set( "light", 1 );
        set("c_item_desc",(["paintings":
             "һ�������˸е���Ŀ�Ļ�����ϸһ��ȫ�������ø�ɫ��ʯ��ɵ�.\n"]));       
	set( "exits", ([ 
		"out"  :ASTR"city_library",
		"north":ASTR"lib_n",
		"south":ASTR"lib_s",
		"west" :ASTR"lib_w",
		]) );
	reset();
#include "replace_room.h"	
}                         

