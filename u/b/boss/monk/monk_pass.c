#include "saulin_temple.h" 
#define  BOARD "/d/monk/guild/water_board"

inherit ROOM;
void create()
{
	::create();
	set_short("�޺��ô���");
	set_long( @LONG_DESCRIPTION
�������޺���ǰ�Ĵ��ã������߱���Ե����޺��á����Ǹ�ʮ����խ�Ĵ���
������Ψһ������ע�����ǽ�߹���һ���������ӣ�����д��һ�����ġ���  
���֡������Ա��м�����(words)�㲻���ȿ����� 
���Ͽ�ͨ����ɮѵ������
LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "c_item_desc", ([ 
          	"words" : @LONG_TEXT
����������������������������������������������������������������
��Ϊ���԰����������� 30 ʱ���Զ������������˰�Ϊ��ˮר�ð� 
��ӭʮ��������˹�ˮ��

���޺�����֮���԰���ר�������йع������bug ���漰����ʱʹ�� 
����������������������������������������������������������������
LONG_TEXT
 ]) );
	set( "exits", ([ 
 	    "east" : SAULIN"monk_guild",
 	    "south" : SAULIN"train_room",
		"west" : "/d/eastland/saulin_temple/hallway23",
    ]));
	set("no_monster", 1);
	BOARD->frog();

}
