// /u/e/echobomber/deathland/tent3.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("�ž�������");
 set_long(@Long
һ���ǳ�����������,�������ȫ������,����һ̤������ط�ʱ,�;���
�ƺ��и�ħ�����������������ط�.
Long
	);
       set("exits",(["out":Deathland"/main/d11",
                    ]));
       set("objects",(["retal":Monster"/retal",
                      ]));
       reset();
#include <../replace_room.h>
}

