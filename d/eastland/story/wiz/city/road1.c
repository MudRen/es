#include "../../story.h"

inherit ROOM;
inherit DOORS;
void create()
{
        ::create();
	set_short("�ڵ���");
	set_long( @LONG
�������ڻʹ����ڵ�һ������ʮ�ߵ����ϡ������������������״������
�ⱦ����ҫ�����ԡ����԰�յ����Ө�ƣ��廨���ң�ȫ��ͨ����������磻����һ
��ƫ�������ȹ����ľ�����ͨ��������ɣ����Ŵ䶫���������ʣ����ɹ��ң�����
��˹��
LONG
	);
        set("light",1);
	set( "exits", ([ 
           "east" : SCITY"palace4",
          "north" : SCITY"house4"
        ]) );
        create_door( "north", "south", ([
          "keyword" : ({ "golden door", "door" }),
          "name" : "golden door",
          "c_name" : "����",
          "c_desc" : "һ����γεĴ��ţ������������ȸ����\n",
          "status" : "closed"
        ]) );
	reset();
}
