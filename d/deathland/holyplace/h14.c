// Deathland/holyplace/h14.c
// Created by Echobomber @Eastern.Stories

#include "../echobomber.h"

inherit ROOM;

int search_slit;
void create()
{
	::create();
  set_short(" A strange place","����������Ʈ�촦");
  set_long(@Long
Long
,@CLong
һ�������ĵ�������,�Ĵ��ĺ�Ӱ������Ϣ��������Ϯ����.����ļž����˸е�����,
���㲻��������Ҫ����һЩ����.û�з���,û��ˮ��,�������޷������Լ��ĽŲ���,�㲻
�������Լ�����һ�����޵ĵط�.�����ҰԽ��ԽС,�ƺ�����۾���һЩ��ɫ��\"��\"��ס
������.�������ʱ����Ӻڰ����ܳ���Σ��,��Щ�ڰ������к����Բ���а��ĸ�Դ.
CLong
);

set("c_item_desc",([
    "fog":"@@to_look_fog",
    ]) );

set("exits",([
             "north":Deathland"/holyplace/h10",
             "northwest":Deathland"/holyplace/h15",
             "south":Deathland"/holyplace/h09",
             ]));
set("pre_exit_func",([
    "south":"to_south",
    ]) );   

set("exit_suppress",({"south",}));    
    
reset();
}

void init()
{
   call_out("notice_exit",1,this_object(),this_player(),0);
}

string to_look_fog()
{
     return can_read_chinese() ?
            "������?�㻳����,���ܺ�����ؿ���һЩ��������Ʈɢ�������Χ.\n"
            "\��\��\��һ��а�������,���ܸо�������а��ĳɷݲ�������.��\n"
            "�ط���\"��\"�ƺ��ر�Ĵ�,\��\��\��һЩ�����������Զ��׼���.\n"
            "�����������۾���Ӧ����ط��Ļ���.\n":
            "need work.\n"; 
}

void notice_exit(object ob1,object ob2,int depth)
{
  
     if (depth<10) {
       if (environment(ob2)==ob1) {
         if ( depth==0 )
           tell_object(ob2,
             "��ط��ƺ���Щ���. ����Ŀǰ��̫���˽�����ʲ��.\n"
             );
         if (depth==4)
           tell_object(ob2,
             "��ط�һ����Щ��Ѱ��, ����һ��Ҳ\��\��\�и���ķ���.\n"
             );
         call_out("notice_exit",1,ob1,ob2,depth+1);
         }
       else return ;
       } 
     else    
     if (environment(ob2)==ob1)
     tell_object(ob2,
                 "�����������ﹻ��,����۾��Ѿ��𽥵���Ӧ����ط�,\n"
                 "��ʱ�㷢�����Ϸ���һ���ұھ�Ȼ�Ǽٵ�.\n"
                 );
     ob2->set_temp("echo_holy",0x01);   
     return; 
}

int to_south()
{
    if ( (int)this_player()->query_temp("echo_holy") & 0x01  )    
      return 0;
    else {
      write("����ȥײ����?\n");
      return 1;
      }
            
}

