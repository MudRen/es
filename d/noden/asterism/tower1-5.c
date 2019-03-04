// File: /d/noden/asterism/tower1-5.c

#include "asterism.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set_short("�����˸����ĵ����");
	set_long( 
		@C_LONG_DESCRIPTION
�����ǰ�˹���ɶ����а����˸����ĵ����,�տյ��������ⷿ�����ɫ.��ʵ��
����ħ��ʦ��ڤ����.�������ǳ��ļž�.������һ����ǰ������峤�ķ�����.
C_LONG_DESCRIPTION
	);

    	set("objects",([
    	    "redmage":MOB"halfling_mage01",
    	    "blackmage":MOB"halfling_mage02",
    	    ]) );
    	set( "exits", ([ 
		"up" : ASTR"tower1-6",
		"down":ASTR"tower1-4",
		]) );

	create_door("up","down",([
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
