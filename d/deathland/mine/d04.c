
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" the big cave of Drawf mine ","���˿�ӵĴ�Ѩ");
  set_long(@Long
Long
,@CLong
һ���ܺںܰ��Ĵ�Ѩ,�����Ǹ������ḻ�Ŀ��.������ĵ��ϳ����˺�ɫ��
��ĭ,�ƺ�һЩ�����µ�������Ϣ������
CLong
);
set("exits",([
             "west":Mine"/d05",
             "east":Mine"/d03",
             ]));
set("objects",([
    "shadow#1":Monster"/evilshadow",
    "shadow#2":Monster"/evilshadow",
    "shadow#3":Monster"/evilshadow",
    "evilfighter":Monster"/evilfighter",
    ]) );
set("pre_exit_func",([
    "west":"to_west"
    ]) );
reset();
}

int to_west()
{
     if (!present("evilfighter")) {
       return 0;
       }
     else {
       write("а��Ļ�Ӱսʿ��ס���ȥ·���������ȥ.\n");
       return 1;
       }  
}

