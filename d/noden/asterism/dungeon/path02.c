// File: /d/noden/asterism/dungeon/path02.c

#include "../asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("halfling tower", "��ˮ�������");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		,@C_LONG_DESCRIPTION
    ����ǰ�˹���ɶ�������Ϊ������ˮ��ϵͳ, վ�ڿ��������, ����֮̾��
�㲻�����ɵ����������������̵ġ���ʵ�Ļ�����ʯǽ, ������ߵ�ˮ��, 
������������ʩ�Ĺ��ܾ��Բ�ֻ����ˮ���ѡ�
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"up" : DUNGEON"path01",
                "down":DUNGEON"sewer11",
		]) );
        set( "exit_msg",([
             "down":"����$N������ˮ����ʱ��,һ˿������������������ͷ��\n",
             ]) ) ;
	reset();
}


