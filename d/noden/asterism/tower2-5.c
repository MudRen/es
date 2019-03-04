// File: /d/noden/asterism/tower2-5.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("���˸����ĵ����");
	set_long(
		@C_LONG_DESCRIPTION
�����ǰ�˹���ɶ����а��˸����ĵ����,���˵Ļ�����,��������ش����
�����ڴ˵ز����ġ�������һ����Ļ�����, ����ʮ�ŵ�����,ǽ�Ϲ���һ�Ű�����
������˹һ���Ļ���(painting).����֮��,�Ӵ�������ȥ,���ܿ�����ΰ�ĸ�ɽ����
��,���滹��һ��������������
C_LONG_DESCRIPTION
	);

  	set( "light", 1 );
	set( "exits", ([ 
                "up"  :ASTR"tower2-6",
		"down":ASTR"tower2-4",
		]) );
	set("objects",([
	    "knight":MOB"dwarf_knight",
	    "mage"  :MOB"dwarf_mage",
	    ]) );
	reset();
}
