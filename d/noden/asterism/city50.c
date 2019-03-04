// File: /d/noden/asterism/city50.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("�۲�վ");
	set_long(
		@C_LONG_DESCRIPTION
�����ǰ�˹���ɶ�(asterism)�ǵĹ۲�վ,��������ϱ߻ص���������,������
���߶�������׵�����,���Դ�����������Ŀ������д�ɽ����������,�������
������һ��ǰ��վ,Ϊ��˹���ɶ��Ƿ������ĵ�һ�ߡ�
C_LONG_DESCRIPTION
	);

	set_outside( "asterism" );
	set( "light", 1 );
        set("objects",(["sentry#1":MOB"dwarf_sentry",
                        "sentry#2":MOB"dwarf_sentry",
                ]) );
                        
	set( "exits", ([ 
		"south" : ASTR"city51",
		]) );
	reset();
#include "replace_room.h"
}
