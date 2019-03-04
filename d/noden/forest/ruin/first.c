#include "ruin.h"
inherit ROOM;
inherit DOORS;

void create()
{
	::create();
  set("light",0);
  set_short("��ɽС��");
  set_long(@CLong
С���ɶ����������Ѷ���, �İ�������һ·��ʼ���ڸ���ͷ�ϵ�����, 
ʹ�������������ء����������ƺ��п�ƽ̨ (plate), ���������Թ�ȥ
����һ�¸����ĵ���, ˳������һ�¾�Υ�����⡣
CLong
);
set("exits",([
              "west"		: RUIN"first",
              "southeast"	: RUIN"first",
             ]));

set("item_desc",([
			"plate"	:@C_DESC_1
����߿���ȥ�ǿ�ƽ̨�ƺ�����, ������ȥ���￴��Ӧ�������Ū��
�Լ����ڵ����ڵء�
C_DESC_1
			]) );			
                          
  ::reset();
}

void init()
{
	add_action("enter_plate", "enter");
}

int enter_plate(string s)
{
	if (!s || strcmp(s,"plate")) {
		return notify_fail ( "����ȥ����?\n" );
	}	
	this_player()->move_player( RUIN"plate", 
	({  "%s���˹�����\n","%s���ǿ�ƽ̨��ȥ��\n"}) );
	return 1;
}
