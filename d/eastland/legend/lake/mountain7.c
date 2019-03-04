#include <mudlib.h>
#include "../legend.h"
inherit ROOM;

int be_knock=0;
void create()
{
    ::create();
    set_short( "ɽ��" );
    set_long(@C_LONG
������������һ��ɽ·�ϡ�·�Գ�����һЩ��֪���İ�ɫ���䣬�������е㵭
�����������ڻ������м�ֻ��������ط��������������˱�����ۣ������ﻹ����
��������ȥ��һ�������˵����ӣ�·�����ϵ��������������ظ߸裬�ƺ��ܿ���
�����ӡ�������÷����ֱߵĹ�����Ͷ�����Ȼ�Ļ��������ν����Ϣ��Ϊ��
�߸�����·�������Ա���һ������������һ�����ĺۼ��ƺ��Ƕ����צ����������
��
C_LONG
    );
    set( "light",1);
    set( "exit_suppress", ({
      "nwu","sd" }) );
    set( "exits", ([
     "southdown":LAKE"mountain8",
            "sd":LAKE"mountain8", 
     "northwestup":LAKE"mountain6",
            "nwu":LAKE"mountain6" 
    ]) );
    set( "c_item_desc", ([
      "tree" : @C_LONG
һ�ð߰׵���ľ�����û���ïʢ��������Χ��һ�����ĺۼ��������и���С��
�������ƺ��Ƕ���ĳ�Ѩ����������һ��(knock) ��˵��������ʲ��������
����Ҳ˵������
C_LONG
    ]) );
    set("objects",([
     "cat#1":LMONSTER"cat",
     "cat#2":LMONSTER"cat",
    ]) );
    reset();
}
void init()
{
    add_action("do_knock","knock");
}
int do_knock(string arg)
{
   object ball;
   if ( present("wild cat",this_object()) ) return 0;
   if (!arg || arg!="tree") return 0;
   if ( be_knock ) return 0;
   tell_object(this_player(),"����������������ɣ�������Ķ������һ�����ӡ�\n");
   ball=new(LITEM"sea_ball");
   ball->move(this_object());      
   be_knock=1;
   call_out("back",300);
   return 1;
}
void back()
{
  be_knock=0;
} 
void reset()
{
   be_knock=0;
   ::reset();
}