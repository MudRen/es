#include "takeda.h"
inherit ROOM;
inherit DOORS;
void create(){
      ::create();
       set_short("��դ");
       set_long( @Clong
�����Ӫ�ľ�ͷ��һƬδ�����������������Ĳ����ľ���������ƣ�Ũ�ܵ�����
֮�£�ɢ�����̸���ڵ�֦�ɣ��͸�ʽ�����ĵ���ֲ���ʹ������Ƭ��������
��Ϊ�ǳ�������һ���¡�ǰ��Ϊ�˴��Է��㣬�����п�����һ��խС�ı������
�������֪��������ʲ���£�ɽկ��������һƬ���ַ������������ڴ�������
һ����դ����פ�����ء�
Clong
          );
 set_outside( "eastland" );
 set("exits",([
               "south":TROOM"cannon",
               "north":TROOM"forest1"
              ]) );
 set("objects",([
               "yang":TMONSTER"yang2"
               ]));
 set( "pre_exit_func", ([
               "north" : "check_good"
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
int check_good()
{
      if ( wizardp(this_player()) || !present("yang")) return 0;
      if ( (int)this_player()->query("alignment")>-100 ) return 0;
      else {
      tell_object( this_player(),
         "��־˵��: ��������֮�������ش˴�������Ϊ������֮ͽ���룬����֮\n"
         "���࣬�������࣬�����뿪�˵أ�������㲻��........\n");
    return 1;
           }       
} 
int clean_up() { return 0; }