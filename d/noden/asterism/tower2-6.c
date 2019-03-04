// File: /d/noden/asterism/tower2-6.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("���˸����Ķ���");
	set_long(
		@C_LONG_DESCRIPTION
�����ǰ�˹���ɶ����а��˸����Ķ�¥��Ҳ���ǰ�����������˹���������ң�
��������һ���󴲣�����������޾�ȴ�ʹ����ɱ�����
C_LONG_DESCRIPTION
	);

  	set( "light", 1 );
	set( "exits", ([ 
		"down" : ASTR"tower2-5",
		]) );
		
	set("objects",([
//          "king":MOB"dwarf_king",
	    "guard#1":MOB"dwarf_guard02",
	    "guard#2":MOB"dwarf_guard02",
	    ]) );
	reset();
}

void init()
{
   if( this_player() ) this_player()->set_explore("noden#35");
}
