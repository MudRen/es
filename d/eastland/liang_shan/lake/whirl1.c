#include "takeda.h"
#include <conditions.h>

inherit ROOM;

void create()
{
        object ob;

	::create();
	set_short( "����" );
	set_long(@C_LONG
�����Ǿ޴����еĵײ���̧ͷ��ȥ��Ť����ˮ����Ȼ���ƾ��ˣ�ʹ���ľ�������
��е���Ȼ�����й�����������������ȥ����е��ŵ��鸡���ĵ�������û���
�Ͽ��뿪�˴���
C_LONG
	);
	set( "exits", ([
             "north" : TROOM"underwater2",            
	     "east" : TROOM"underwater3",
	     "south" : TROOM"underwater4"
	]) );
        set("underwater",1);
          reset();
}
void init()
{
  UNDERWATER->apply_effect(this_player(),4,1);
}



