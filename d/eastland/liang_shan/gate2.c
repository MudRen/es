#include "takeda.h"
inherit ROOM;
inherit DOORS;
void create(){
      ::create();
       set_short("��դ");
       set_long( @Clong
������һ���ּ�С����С���ľ�ͷ��һ�����صĴ���դ����դ������һ����
��ʾ(board)������д��һЩ�֡�һ����ڵĴ󺺱���һ�Ѹ�ͷ�������ڸ�ʾ
�º�����˯���������׵�����......Z....Z....Z.....
Clong
          );
set ("c_item_desc",([
"board":@Board
 ---------------------------------------------------------------------
  ע��    ��ɽ������
               
                   ��������һ�ٴ�                        �ν�
---------------------------------------------------------------------
Board
 ]));
 set_outside( "eastland" );
 set("exits",([
               "north":TROOM"path9",
               "south":TROOM"path8",
              ]) );
 set("objects",([
               "li":TMONSTER"li"
               ]));
 set( "pre_exit_func", ([
               "north" : "check_flag"
               ]));
create_door("north","south",([
             "keyword" : ({"iron prism","prism" }),
             "status" : "closed",
             "c_desc" : "һ�����ص���դ",
             "c_name" : "��դ",
             "name":"iron prism",
             "desc":"an iron prism"
              ]) );
reset();
}
int check_flag()
{
      if ( wizardp(this_player()) || !present("li")) return 0;
      if ( present("flag",this_player()) ) return 0;
      else {
      tell_object( this_player(),
         "���Ӻ�Ȼ�ſ��۾�˵��: û�����첻׼��ȥ��˵���۾�һ�գ���˯����...\n");
    return 1;
           }       
}
int clean_up() { return 0; } 