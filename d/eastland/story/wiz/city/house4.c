#include "../../story.h"

inherit ROOM;
inherit DOORS;
void create()
{
        ::create();
	set_short("���ȹ�����ƫ��");
	set_long( @LONG
���������ȹ�����ס�����������񽨳ɣ������ؼѣ��������������ܲʱڻ���
���������Ҿ㣬�ư��񼸣���ƫһ����Բ�α����������˽����������������
���������Ա�һ���ɫ�������ƴ�ͭ����ȫ���ʮ�㣬���ɶ��
LONG
	);
        set("light",1);
	set( "exits", ([ 
           "south" : SCITY"road1"
        ]) );
        set( "objects", ([
           "servant1" : SWMOB"f_servant1",
           "servant2" : SWMOB"f_servant1",
           "servant3" : SWMOB"f_servant1",
           "princess" : SWMOB"princess1",
        ]) );
	create_door( "south","north" ,([
	  "keyword" : ({ "golden door", "door" }),
	     "name" : "golden door",
	   "c_name" : "����",
	   "c_desc" : "һ����γεĴ��ţ������������ȸ����\n",
	   "status" : "closed"
	]) );
	reset();
}
