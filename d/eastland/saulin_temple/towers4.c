#include "saulin_temple.h"

inherit ROOM;

void create()
{
	::create();
	set_short("����");
	set_long( @C_LONG_DESCRIPTION
һ����С�������С��װ�����һ�����֣�����������������������֣�
�ഫÿһλ��ɮ�����������õ������Ӷ��Ὠһ��С������ţ�����������
���������������ֵ���ʷ�ƾ����˲ű���Ϊʲ�������������
C_LONG_DESCRIPTION
	);
        set_outside("eastland");
	set( "exits", ([
		 "north" : SAULIN"towers3",
      	 "east"  : SAULIN"towers4",
		 "west"  : SAULIN"towers2",
		 "south" : SAULIN"towers4",
	]) );
	reset();	
}

void init()
{
    add_action( "summon_seed", "call" );
}

int summon_seed(string arg)
{
	if( !arg || arg=="" || arg !="relic")
 		tell_object(this_player(), 
    		"һ��������翵�������: ���й�и�ʲ�ᾢ��\n" 
   		);
    else
        tell_object(this_player(), 
                "����˺ð��죬������Ӱ��Ҳû�С�\n" 
        );
   	return 1;
}
