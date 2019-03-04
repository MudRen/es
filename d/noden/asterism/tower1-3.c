// File: /d/noden/asterism/tower1-3.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("�����˸����ĵ�����");
	set_long(
		@C_LONG_DESCRIPTION
�����ǰ�˹���ɶ����а����˸����ĵ�����,һ�ֿ��ֵ����ո�Ⱦ�������ͷ,��
�������޿ɾ�ҩ�������ɵ�Ӱ����,������Ϊһ��ķ�����ʩ�Ѿ��㹻,�����������
���ڿ����,��������Ц������.
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"up" : ASTR"tower1-4",
		"down":ASTR"tower1-2",
		]) );
	set("objects",([
	     "explorer":MOB"halfling_explorer",
	     ]) );
	reset();
#include "replace_room.h"
}
