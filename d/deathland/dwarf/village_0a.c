
#include "../echobomber.h"

inherit ROOM;

void create()
{
  ::create();
  set_short("the secret hole","���ܶ�Ѩ");
  set_long(@Long
Long
,@CLong
һ������ֵĳ���.��������һЩ�������µķ���(sign),�ƺ�����������Ǹ�������
CLong
);
set( "c_item_desc",([
     "sign":"һ�ֺ���ֵķ���,�ƺ���һ������,�������޷��˽���.\n"
     ]) );
  
set( "exits",([
             "out":Deathland"/dwarf/village_09",
             "north":Deathland"/dwarf/village_0b",
             ]));

set ( "pre_exit_func",([
      "north":"to_north",
      ]) );
set( "objects",([
     "assassin":Monster"/assassin01",
    ]) );
reset();
}

int to_north()
{
    if (!present("assassin"))
      return 0;
    else 
     write("��Ӱɱ�ֵ�ס�����ȥ·.\n");
     return 1; 
}

