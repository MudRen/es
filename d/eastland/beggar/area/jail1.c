#include "../dony.h"
inherit DOORS;
inherit ROOM;

void create()
{
	::create();
        set_short( "jail1", "��н���塻����" );
	set_long(@C_LONG
�����ڽ�����һ���������ļ��Σ������ж����Ҳ˵����������Ϊ�������
���Ծ����������ӡ������м��߻�û�и�����ġ��������ɭɭ�Ĺ�ͷ, ���ε�
��������һ�Ŷ���ǽ���ϵ�ľ�崲��
C_LONG
	);
	set( "light" , 1 );
	set( "exits", ([
                      "east":DBEGGAR"east10.c"
	]) );
        set( "c_item_desc", ([
                 "bed" :"һ�ż�򵥵���ľ����\n",
                 "bone":"�������˵Ĺ�ͷ��\n"
        ]) );
                                    
        set( "objects",([  
                     "chan":DMONSTER"chan"
                     ]) );
      
        create_door( "east", "west", ([
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
   add_action("do_search","search");
}
int do_search(string arg)
{
   if( !arg || arg!= "bone" )
      return notify_fail("��Ҫ��ʲ����?\n");
         
   tell_object(this_player(),"��������,ԭ�����а��š�\n");
   this_player()->move_player(DBEGGAR"jail2.c");
   return 1;
}      
