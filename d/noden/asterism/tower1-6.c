// File: /d/noden/asterism/tower1-6.c

#include "asterism.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set_short("�����˸����ĵ�����");
	set_long(
		@C_LONG_DESCRIPTION
�����ǰ�˹���ɶ����а����˸�������߲������.Ҳ�ǰ������峤ϯ����˹ʮ��
(Thilenros X)��ס��,���ܰ����˺ܶ���滨���(flowers),��ƽ�����޷��Ƽ���.
C_LONG_DESCRIPTION
	);
       set("c_item_desc",([
           "flowers":"һЩ����ֵֹ��滨���,����ȴ���Ǻ������ɽֲ��.\n"
           ]) );    	
    	set( "exits", ([ 
		"down":ASTR"tower1-5",
		]) );
	create_door("down","up",([
             "name":"white door",
             "c_name":"��ɫ����",
             "keyword":({"white door","door",}),
             "c_desc":"��ɫ����",
             "status":"locked",
             "desc":"a white door",
             "lock":"ASTERISM_1",
                     ]) );
	reset();
}
