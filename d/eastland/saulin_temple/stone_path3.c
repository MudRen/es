#include "saulin_temple.h"

inherit ROOM;

void create()
{
	::create();
	set_short("ʯ��С��");
	set_long( @C_LONG_DESCRIPTION
��������������ǧ�Ȱ�Ժ���ͨ���ϣ�ĥ���Բ��⻪��ʯ�����ԵĶ���
��ҫ�����µ��ƾ���ʷ��ң�������������֣����ڻ�����ǽ����ɮ��ȥ���ο�
��ӣ��㲻���г���֮�롣���߾��Ƕ��������Ĵ�Ħ��ڴ���
C_LONG_DESCRIPTION
	);
        set_outside("eastland");
    set( "pre_exit_func", ([
    	"east" : "check_monk"
    ]) );
    set( "objects", ([
    	"monk1" : SAULIN_MONSTER"monk",
    	"monk2" : SAULIN_MONSTER"monk",
    ]) );
	set( "exits", ([
		 "east"  : SAULIN"damo_stone",
		 "west"  : SAULIN"entrance"
	]) );
	set("no_monster", 1);
	reset();
}

int check_monk()
{
	if( wizardp(this_player()) || !present("monk") ) return 0;
	tell_object(this_player(),
		"��Ħ�� ���º���˵: �����˱���ʥ��, �ο���ֹ����\n"
	);
	return 1;
}
