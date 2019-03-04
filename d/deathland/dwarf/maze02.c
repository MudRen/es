
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
                "west": Deathland"/dwarf/maze01",
                "east": Deathland"/dwarf/darkroom",
                "north":Deathland"/dwarf/darkroom",                 
                "south":Deathland"/dwarf/darkroom", 
             ]));

set("pre_exit_func",([
                      "west": "leave_maze",
                      "east": "maze_2e",
                      "north":"maze_2n",
                      "south":"maze_2s",
                     ]) ); 
set("objects",([
    "thief":Monster"/thief01",
    ]) );
::reset();
}

int leave_maze()
{
    return 0;
}

int maze_2e()
{
    if ( (int)(this_player()->query_temp("dwarf_echomaze/check"))==1 )
      return 0; 
    else {
      this_player()->set_temp("dwarf_echomaze/m2",1);
      write("��ͨ��ħ���ϱڵ���һ���µĵط�\n");
      say( this_player()->query("short")+"����ͨ��ħ���ϱ�\n");
      this_player()->move_player(Deathland"/dwarf/maze03","SNEAK","");
      say( this_player()->query("short")+"���������˹���.\n");
      }
    return 1;
}

int maze_2n()
{
    if ( (int)(this_player()->query_temp("dwarf_echomaze/check"))==1 )
      return 0; 
    else {
      this_player()->set_temp("dwarf_echomaze/m2",2);
      write("��ͨ��ħ���ϱڵ���һ���µĵط�\n");
      say( this_player()->query("short")+"����ͨ��ħ���ϱ�\n");
      this_player()->move_player(Deathland"/dwarf/maze03","SNEAK","");
      say( this_player()->query("short")+"���ϱ����˹���.\n");
      }
    return 1;
}

int maze_2s()
{
    if ( (int)(this_player()->query_temp("dwarf_echomaze/check"))==1 )
      return 0; 
    else {
      this_player()->set_temp("dwarf_echomaze/m2",3);
      write("��ͨ��ħ���ϱڵ���һ���µĵط�\n");
      say( this_player()->query("short")+"����ͨ��ħ���ϱ�\n");
      this_player()->move_player(Deathland"/dwarf/maze03","SNEAK","");
      say( this_player()->query("short")+"�ӱ������˹���.\n");
      }
    return 1; 
}
