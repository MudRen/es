#include <mercury.h>

inherit DOORS;
inherit ROOM;

void create()
{
   ::create();
   set_short( "��ɪ˹·" );
   set_long(@ANGEL
��������ɪ˹·�ϣ�����һ�����Ĵ�·����·�����ü�Ӳ�Ļ���ʯ���ģ���
·�ı����ǿ��Ĺ㳡��    
ANGEL
   
         );
	set( "light",1);
	set_outside("eastland");		
        set( "exits", ([
                "south"  :MR"cac03",
                "north" :MR"cac05",
                ]) );
         create_door("south","north",([
                     "keyword" : ({"door","iron door"}),
                     "status"  : "closed",
                     "name"    : "Iron Door",
                     "c_name"  : "��դ��",
                     "c_disc"  : "һ��������դ��\n"
                     ]) );       
         reset();                     
}

