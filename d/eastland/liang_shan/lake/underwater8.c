#include "takeda.h"
#include <conditions.h>

inherit ROOM;

void create()
{
        object ob;

	::create();
	set_short( "����" );
	set_long(@C_LONG
�����Ǵ���ĺ��ף���ˮ����͸�뵭������⣬ҡҷ�Ĺ�ӰͶӰ��ƽ̹��ɳ��
���γ���һ�����ص��龰����ˮ��������������Լ���Կ���ˮ���ϵķ羰��ƽɳ��
�������ڿ�\ľ\���������أ�����ȴû��ʱ��ú����͡���Ϊ��֪�������Ͽ��뿪��
���Ļ������Ҫ��Զ�����ں����ˡ�
C_LONG
	);
	set( "exits", ([
             "up" : TROOM"deep8",            
	     "south" : TROOM"whirl3"
	]) );
        set( "objects", ([
             "shell" : TMONSTER"shell"
             ]));
        set_outside("eastland");
        set("underwater",1);
        reset();
}
void init()
{
  UNDERWATER->apply_effect(this_player(),4,1);
  if (this_player()) this_player()->set_explore("eastland#22");
}
