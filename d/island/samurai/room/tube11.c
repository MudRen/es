#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "������" );
   set_long(@ANGEL
������һ�������ݣ����������֪����ʲ����ס�ڵ����ˣ�ԭ������ʿ�Ǳ�
����һ֮����������ס�����棬��Ϊ���ڵ��£���ǽ�����кü���ҹ���������
�����������Ա߷��˼���������ϰ�еļ��ˣ�����һ��΢�紵���������ȷ����
��һ���г��ڣ�    
ANGEL
   
         );
         
	set( "light",1);
	set("objects",([
	"nei1":MOB"nei"
	             ]));
        set( "exits", ([
                "north":MR"tube10",
                "south" :MR"ca1"
                ]) );
         reset();                     
}

