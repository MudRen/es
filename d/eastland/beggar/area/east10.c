#include "../dony.h"

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
        set_short( "east8", "�����ķ���" );
	set_long(@C_LONG
������һ�������ķ���,������һ�ɡ���ζ,�����ǰ�кܶ����������������
ûʲ�����,ֻ��һ���ֱ۳��������,��������һ�ѱ����Ĺ��ӡ�, ����һЩ��
��ƿ,������������ĵ�ʱ��������������������ǽ������һ����Ҫ�չ�Ļ��,��
֪��Ϊʲ��,�������ĸо�������ɭɭ�ġ�
C_LONG
	);
	set("light",0);
	set( "exits", ([
                      "west":DBEGGAR"jail1.c",
                      "south":DBEGGAR"east9.c"
	]) );
        set( "c_item_desc", ([
            "torch" :"һ���챻����Ļ�ѡ�\n"
        ]) );        
        create_door( "west", "east", ([
                     "keyword" : ({ "copper door", "door" }),
                     "name" : "copper door",
                     "c_name" : "Сͭ��",
                     "c_desc" : "һ�Ⱥ���ͨ��Сͭ��",
                     "status" : "locked",
                     "lock" : "DBEGGAR_JAIL1" 
                    ]) );
     reset();
}

void init()
{ 
   add_action("do_touch","touch"); 
}

int do_touch( string arg )
{
     
     if ( !arg || arg != "torch" )
        return notify_fail("��Ҫ��ʲ��?\n");
     
     tell_object( this_player(),
           "\n\n\n��Ȼ�������������ת�ص��ڵ���.....\n\n\n\n\n");
     call_out( "recover",20,this_player());
     this_player()->set_temp("block_command",1);
     return 1;
}

void recover(object toucher)
{
   toucher->set_temp("block_command",0);
   tell_object(toucher,"\n\n�������������һ����ֵĵط�..��\n\n\n");
   this_player()->move_player(DBEGGAR"temp_room1");
}

