
// Deathland/ruin1/down02.c

#include "../echobomber.h"

inherit DOORS;
inherit ROOM;

void create()
{
	 ::create();
     set_short("the ruin","�ż�������");
     set_long(@Long
Long
,@CLong
�������ż��ĵ����� ,�ƺ����������ѵĵط� .Ȼ�����ϵ�����һ�ѶѵĹǺ���Ǭ
����Ѫ�� .�����˾��������Ե�ʮ�ֵĹ��� .���޷�����ʱ���������� ,������\��\
\��\������⵽Ϊ������ط�һֱû���˷����� ,��Ϊ��ʱ��һ�����Ѱ��������е��˶�
�������� .����춶���������˶��������� .�ϱ���һ��ʯ�� ,�������ƺ��Ǵ���ʳ��
����ˮ�ĵط� ,�����㲻��ȷ��Ŀǰ�������ʲ�ᶫ�� .
CLong
);
     set("exits",([
         "south":Deathland"/ruin1/down03",
         "north":Deathland"/ruin1/down01",
         ]) );
     create_door("south","north",([
             "name":"stone door",
             "c_name":"ʯ��",
             "keyword":({"stone door","door",}),
             "c_desc":"ʯ��",
             "status":"closed",
             "desc":"a stone door",
                     ]) );    
     ::reset();
}

