// File: /d/noden/asterism/path31.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("С��");
	set_long(
		@C_LONG_DESCRIPTION
��������������һƬ�����С����ܵĲ�������ʹ�㼸����Ҫ��Զס�����˼��ɾ�,
���ٻص��Ƿ��ŵ����硣
C_LONG_DESCRIPTION
	);

	set_outside( "asterism" );
//	set( "light", 1 );
	set( "exits", ([
	        "east" : ASTR"path3",
		]) );
        set("objects",([
                "monkey#1" : MOB"monkey" ,     
                "monkey#2" : MOB"monkey" ,     
                ]) ) ;
	reset();
#include "replace_room.h"
}
