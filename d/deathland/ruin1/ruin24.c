
// Deathland/ruin1/ruin24.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	 ::create();
     set_short("the ruin","�ż�");
     set_long(@Long
Long
,@CLong
һ���ƾɵ��ż� ,�����ƺ��Ѿ��ķϺܾ��� .���ϵ����ǲ�ש���� ,�����˾���
��ط��Ѿ�\��\��δ���������� .һ����ɫ��޺ֲ̦�︽�����Ե�ǽ���� ,ʹ����ط�
�����ո��Ե�ʮ�ֵĹ��� .
CLong
);
     set("exits",([
         "southeast":Deathland"/ruin1/ruin33",
         "northwest":Deathland"/ruin1/ruin15",
         ]) );
     ::reset();
#include <../replace_room.h>
}

