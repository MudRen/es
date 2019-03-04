#include "../megatower.h"

inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("The Entrance of Mega Tower","Ħ���������");
  set_long(@Long
Long
,@CLong
���Ѿ�����Ħ�������ڲ���һ����, �����ƺ������ʧ��, �����ɼ��������Ƭ
��ʯ��, ��ط��Ǹ��������, ��һ����ʾ��(plaque)���������, ������ּ���Щ
ģ��, ���Ƕ��������˽���������ȴûʲ������.
    ��������ʲ���˽����, ��������Ŀ������Ϊ��ʲ����? ���ֵ����ܴ���ȥ̽��.
CLong
);
  set("exits",([
               "west" :Megatower"/floor1/20",
               "east" :Megatower"/floor1/40",
               "south":Megatower"/outside",
               "north":Megatower"/floor1/31",
             ]));

  set("item_func",([
      "plaque":"look_plaque",
      ]) );
::reset();
}

int look_plaque()
{
    write(
          "**********************************\n"
          "*�����������������,             *\n"
          "*  ����������Ƶı����͸���.     *\n"
          "*    ------������˹��(Keist)-----*\n"
          "**********************************\n"
          );
    return 1;
}
