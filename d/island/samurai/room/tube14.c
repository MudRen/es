#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "������" );
   set_long(@ANGEL
������һ�������ݣ����������֪����ʲ����ס�ڵ����ˣ�ԭ������ʿ�Ǳ�
����һ֮����������ס�����棬��Ϊ���ڵ��£���ǽ�����кü���ҹ���������
������������Ŀռ������ͨ�����˺ܶ࣬������о�Ҳ�����������ֵ�����
��ĵذ��кܶ���СС�ĿӶ�����������������ϰһЩ��ֵ���ʽ��
ANGEL
   
         );
         
	set( "light",1);
	set("objects",([
	"calford":MOB"calford",
	"poppy"  :MOB"poppy"
	             ]));
        set( "exits", ([
                "east":MR"tube15",
                "south" :MR"tube13"
                ]) );
         reset();                     
}

