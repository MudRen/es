#include "../echobomber.h"

inherit ROOM;

void create()
{
         ::create();
     set_short("the ruin","��ħ��ͨ��");
     set_long(@Long
Long
,@CLong
�����ƺ������Ǳ������ģ�������ȥ��ħ���ǵ�ͨ����
CLong
);
     set("objects",([
         "wight":"d/mage/tower/god",
         ]) );
     set("exits",([
    "west" : "/d/mage/tower/mage_guild.c" ,
    "north" : "/d/mage/tower/time.c",
         ]) );
     set("pre_exit_func",([
         "north":"to_north",
         ]) );
     reset();
}

int to_north()
{
    if (present("wight")) {
      write(can_read_chinese() ?
            "�㱻����ħ��ס��ȥ· .\n" :
            "you are blocked by the wight.\n"
           );
      return 1;     
      }

    return 0;
}
