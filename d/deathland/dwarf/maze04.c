
#include "../echobomber.h"

inherit ROOM;

void create()
{
  ::create();
  set_short("the dwarf village","�Թ�");
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
                "west": Deathland"/dwarf/maze03",
                "east": Deathland"/dwarf/darkroom",
                "north":Deathland"/dwarf/darkroom",                 
                "south":Deathland"/dwarf/darkroom", 
             ]));

set("pre_exit_func",([
                      "west": "leave_maze",
                      "east": "maze_4e",
                      "north":"maze_4n",
                      "south":"maze_4s",
                     ]) ); 
::reset();
}

int leave_maze()
{
    return 0;
}

int maze_4e()
{
    if ( (int)(this_player()->query_temp("dwarf_echomaze/check"))==1 )
      return 0; 
    else {
      this_player()->set_temp("dwarf_echomaze/m4",1);
      write("��ͨ��ħ���ϱڵ���һ���µĵط�\n");
      say( this_player()->query("chort")+"����ͨ��ħ���ϱ�\n");
      this_player()->move_player(Deathland"/dwarf/maze04","SNEAK","");
      say( this_player()->query("chort")+"���������˹���.\n");
      this_player()->set_temp("dwarf_echomaze/check",1);
      }
    return 1;
}

int maze_4n()
{
    if ( (int)(this_player()->query_temp("dwarf_echomaze/check"))==1 )
      return 0; 
    else {
      this_player()->set_temp("dwarf_echomaze/m4",2);
      write("��ͨ��ħ���ϱڵ���һ���µĵط�\n");
      say( this_player()->query("chort")+"����ͨ��ħ���ϱ�\n");
      this_player()->move_player(Deathland"/dwarf/maze04","SNEAK","");
      say( this_player()->query("chort")+"���ϱ����˹���.\n");
      this_player()->set_temp("dwarf_echomaze/check",1);
      }
    return 1;
}

int maze_4s()
{
    if ( (int)(this_player()->query_temp("dwarf_echomaze/check"))==1 )
      return 0; 
    else {
      this_player()->set_temp("dwarf_echomaze/m4",3);
      write("��ͨ��ħ���ϱڵ���һ���µĵط�\n");
      say( this_player()->query("chort")+"����ͨ��ħ���ϱ�\n");
      this_player()->move_player(Deathland"/dwarf/maze04","SNEAK","");
      say( this_player()->query("chort")+"�ӱ������˹���.\n");
      this_player()->set_temp("dwarf_echomaze/check",1);
      }
    return 1; 
}
