#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "vice_master_room", "������֮��" );
	set_long(@C_LONG
������ȫ������ס�ĵط�������ûʲ����صİ���,�����м����һ�Ŵ����
��,�����ﻹ�м�������, �����ﲻ֪���ŵ���ʲ�ᶫ�������������ǽ���Ϲ���
������֪��������,��������д���������˳��֮��Ķ���, ���������������
ббһ����֪�����ǳ���������ֱʡ�
C_LONG
	);
	set("light",1);
	set( "exits", ([
                      "out":DBEGGAR"west9.c"
	]) );
        set( "c_item_desc", ([
                 "closet" :"һ����̴ľ���ĳ��롣\n"
        ]) );
        set( "objects", ([
                      "unary":DMONSTER"unary.c",
                        "dog":DMONSTER"dog.c"
        ]) );              
     reset();
}
void init()
{
   add_action("do_search","search");
}
int do_search(string arg)
{
    object ob1;
    
      if ( !arg || arg != "closet" ) {
         tell_object(this_player(),"������ʲ�ᶫ����\n");
         return 1;
      }      
      if ( this_object()->query_temp("be_searched") ) {
         tell_object(this_player(),"���뼺���������ҹ��ˡ�\n");
         return 1;
      }
      if ( !this_player()->query_temp("gonfu_asked") ) {
         tell_object(this_player(),"������ʲ�ᶫ��?\n");     
         return 1;
      }    
      else {
         tell_object( this_player(),
            "���ҵ���һ���ɫ���ż���\n");
         ob1=new(DITEM"letter");          
         ob1->set("master",this_player()->query("name"));
         ob1->move(this_player());
         this_object()->set_temp("be_searched",1);
         call_out("recover",1800,this_object());
         return 1;
      }
}
void recover(object obj)
{  
     obj->delete_temp("be_searched");
}
void reset()
{
     this_object()->delete_temp("be_searched");
     ::reset();
}
            