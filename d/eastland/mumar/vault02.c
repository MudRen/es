#include <mumar.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("The vault door","�ⷿ����");
  set_long(@Long
Long
,@CLong
�����������������Ĵ��ţ�ǽ������һ�ѡ���������������Ͻ��̻�֮���
�������ĵ����Ͼ���һЩ���ҵĽ�ӡ����������һȺʿ���ڽ���ս��ʱ������
��ȡװ���ľ��񡣴�����������Իص��̳��ϣ����߾��������⡣
CLong
);
set_outside("eastland");
set( "pre_exit_func", ([ "west" : "check_guard" ]) );
set("exits",([
               "west": MUMAR "vault01",
               "east": MUMAR "square04"
             ]));
set("objects",([
               "guard#1": MOB "guard",
               "guard#2": MOB "guard"]));
reset();
}
 
int check_guard()
{
        if( wizardp(this_player()) || !present("guard") ) return 0;
   { if(this_player()->query_temp("army_mark") )    {
        tell_object(this_player(), can_read_chinese() ?
                    "����˵��:���ٺ�....��ͬʱ������ǹ����Ķ�����\n":
                    "The guard said : Good morning, Sir!" );
	this_player()->set_explore("eastland#35");
        return 0;
          }
      else   {
        tell_object(this_player(), can_read_chinese() ?
                "�ⷿ����˵: �����Ǳ����صأ��㲻�ܽ�ȥ��\n" :
                "The guard says: Sorry, you can't go there.\n" );
        return 1;
             }
}
}
