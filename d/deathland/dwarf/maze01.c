
#include "../echobomber.h"

inherit ROOM;

void create()
{
  ::create();
  set_short("the dwarf maze","�Թ�");
  set_long(@Long
Long
,@CLong
һ���ܴ���Թ�(maze)��Ѩ,�����ϱ�����ͨ·,����ÿ��ͨ�����ƺ�����ħ��
�ϱ�,����Ϊ���ܰ���ȫȫ��������,���Լ��Ĵ��佨�����������Թ��Ĵ�֮��
,���˰����Լ��ܹ������Ұ�ȫ���ߵ��Լ��Ĵ�����,�ƺ�Ҫ�����˴�����һ������
����.
CLong
);
set("exits",([
                "west": Deathland"/dwarf/village_08",
                "east": Deathland"/dwarf/darkroom",
                "north":Deathland"/dwarf/darkroom",                 
                "south":Deathland"/dwarf/darkroom", 
             ]));

set("pre_exit_func",([
                      "west": "leave_maze",
                      "east": "maze_1e",
                      "north":"maze_1n",
                      "south":"maze_1s",
                     ]) ); 
::reset();
}

int leave_maze()
{
    return 0;
}

int maze_1e()
{
    if ( (int)(this_player()->query_temp("dwarf_echomaze/check"))==1 )
      return 0; 
    else {
      this_player()->set_temp("dwarf_echomaze/m1",1);
      write("��ͨ��ħ���ϱڵ���һ���µĵط�\n");
      say( this_player()->query("short")+"����ͨ��ħ���ϱ�\n");
      this_player()->move_player(Deathland"/dwarf/maze02","SNEAK","");
      say( this_player()->query("short")+"���������˹���.\n");

      }
    return 1;
}

int maze_1n()
{
    if ( (int)(this_player()->query_temp("dwarf_echomaze/check"))==1 )
      return 0; 
    else {
      this_player()->set_temp("dwarf_echomaze/m1",2);
      write("��ͨ��ħ���ϱڵ���һ���µĵط�\n");
      say( this_player()->query("short")+"����ͨ��ħ���ϱ�\n");
      this_player()->move_player(Deathland"/dwarf/maze02","SNEAK","");
      say( this_player()->query("short")+"���ϱ����˹���.\n");
      }
    return 1;
}

int maze_1s()
{
    if ( (int)(this_player()->query_temp("dwarf_echomaze/check"))==1 )
      return 0; 
    else {
      this_player()->set_temp("dwarf_echomaze/m1",3);
      write("��ͨ��ħ���ϱڵ���һ���µĵط�\n");
      say( this_player()->query("short")+"����ͨ��ħ���ϱ�\n");
      this_player()->move_player(Deathland"/dwarf/maze02","SNEAK","");
      say( this_player()->query("short")+"�ӱ������˹���.\n");
      }
    return 1; 
}
