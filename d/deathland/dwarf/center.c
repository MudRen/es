
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("The new_trained_soldier center","�±�ѵ������");
  set_long(@Long
Long
,@CLong
������ר�Ž�����İ���ѵ�������͵�սʿ�ĵط�.ÿ�����˵�ս�����ļ����ԴӴ�
����ʼ.
CLong
);

set("exits",([
               "out":Deathland"/dwarf/village_04",
             ]));
set("objects",([
    "teacher":Monster"/soldier03",
    "newsoldier#1":Monster"/soldier04",
    "newsoldier#2":Monster"/soldier04",
    "newsoldier#3":Monster"/soldier04", 
    ]) );
::reset();
#include <../replace_room.h>
}

