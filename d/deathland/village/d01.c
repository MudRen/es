
#include "../echobomber.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
    set_short("The serect room","���ܵ�С����");
    set_long(@Long
Long
,@CLong
��Ŀǰλ�һ�����ܵ�С������,����������������,�ƺ���������һ�����������.
���ߵ�ǽ������һ����ť(button),û����֪������ȥ����������?
CLong
    );
    set("c_item_desc",([
        "button":"һ���ʺ�ɫ�İ�ť,�ƺ��������ǲ�Ҫȥ����.\n",
                ]) ); 
    set("exits",([
                "up":Deathland"/village/v24",
             ]));
    set("objects",([
        "guardian":Monster"/guard06.c",
                   ]) );
    create_door("up","down",([
               "keyword":({"woodendoor","door"}),
               "status":"closed",
               "c_desc":"һ��СС��ľ��",
               "c_name":"Сľ��",
               "name":"small wooden door",
               "desc":"a small wooden door",
               ]) );
    ::reset();
}

void init()
{
   add_action("do_push","push");
}

int do_push(string str)
{
   if (!str||str!="button") return 0;
   if (!present("guardian"))
      {
       write("һ��ǿ���ֱ�ش����������.\n\n\n\n"
             "�������뿪���������\n");
       this_player()->set_temp("block_command",1);
       
       call_out("recover",15,this_player());        
       say("��"+this_player()->query("short")+"�����˰�ť��,һ��ǿ��̴�����������.\n"
           "Ȼ��"+this_player()->query("short")+"�͵��ز�����.\n");       
       return 1;
      }
   else 
      {
      write("����˵:��Ҫ���Ǹ���ť.\n");
      say(this_player()->query("short")+"�������°�ť����������ֹ\.n");
      return 1;   
      }
}

int recover(object who)
{
   who->set_temp("block_command",0);
   tell_object(who,"������,�������Ѿ��ص��������֮��.\n"
                   "�����ƺ�һ���ر������ע�������������.\n"
                   );
   who->set_explore( "deathland#25" );
   who->set_temp("deathland_magicwall",1);                
   return 1;
}
