
#include "../echobomber.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
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
                "west": Deathland"/dwarf/maze02",
                "east": Deathland"/dwarf/darkroom",
                "north":Deathland"/dwarf/darkroom",                 
                "south":Deathland"/dwarf/darkroom", 
             ]));

set("pre_exit_func",([
                      "west": "leave_maze",
                      "east": "maze_3e",
                      "north":"maze_3n",
                      "south":"maze_3s",
                     ]) ); 
::reset();
}

int leave_maze()
{
    return 0;
}

int maze_3e()
{
    if ( (int)(this_player()->query_temp("dwarf_echomaze/check"))==1 )
      return 0; 
    else {
      this_player()->set_temp("dwarf_echomaze/m3",1);
      write("��ͨ��ħ���ϱڵ���һ���µĵط�\n");
      say( this_player()->query("short")+"����ͨ��ħ���ϱ�\n");
      this_player()->move_player(Deathland"/dwarf/maze04","SNEAK","");
      say( this_player()->query("short")+"���������˹���.\n");
      }
    return 1;
}

int maze_3n()
{
    mapping x;
    x=this_player()->query_temp("dwarf_echomaze");
    
    if ( (int)(this_player()->query_temp("dwarf_echomaze/check"))==1 )
      {
       if ( x["m1"]==1 && x["m2"]==3 && x["m3"]==3 && x["m4"]==2 )
         {
         this_player()->move_player(Deathland"/village/v01",({
           "??\n","%s����ͨ��ħ���ϱ�\n",
           "??\n","%s���ϱ����˹���.\n" 
           }),"");
         return 1;
         } 
       else
           return 0; 
      }
    else {
      this_player()->set_temp("dwarf_echomaze/m3",2);
      write("��ͨ��ħ���ϱڵ���һ���µĵط�\n");
      say( this_player()->query("short")+"����ͨ��ħ���ϱ�\n");
      this_player()->move_player(Deathland"/dwarf/maze04","SNEAK","");
      say( this_player()->query("short")+"���ϱ����˹���.\n");
      }
    return 1;
}

int maze_3s()
{
    if ( (int)(this_player()->query_temp("dwarf_echomaze/check"))==1 )
      return 0; 
    else {
      this_player()->set_temp("dwarf_echomaze/m3",3);
      write("��ͨ��ħ���ϱڵ���һ���µĵط�\n");
      say( this_player()->query("short")+"����ͨ��ħ���ϱ�\n");
      this_player()->move_player(Deathland"/dwarf/maze04","SNEAK","");
      say( this_player()->query("short")+"�ӱ������˹���.\n");
      }
    return 1; 
}
