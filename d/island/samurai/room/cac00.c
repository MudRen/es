#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "��ʿ�Ǳ�����" );
   set_long(@ANGEL
��������ʿ�Ǳ�����ڣ�����Կ����Ա߸��ʵĳ�ǽ��ȫ����װ��������Ϊ�˷���
���˵���������ʱʱ�̶̿�������ǿ���˱������򱱿��Խ�����ʿ�Ǳ����ϱ�����һ��
��վ    
ANGEL
   
         );
	set( "light",1);
	set_outside("eastland");		
	set("objects",([
	    "yark":MOB"yark",
	    "guard#1":MOB"guard2",
	    "guard#2":MOB"guard2"
	      ]) );
        set( "exits", ([
                "north"  :MR"cac01",
                "south" :MR"station",
                ]) );
         reset();                     
}

