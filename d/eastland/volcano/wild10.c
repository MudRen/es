#include "oldcat.h"

inherit ROOM;
int be_search;
void create()
{
	::create();
	set_short("�ݵ�");
	set_long( 
@LONG_DESCRIPTION
����û�����Ե�·�����ߣ���վ��һ��Ƭ�ݵ��м䣬�ݵسʻ���ɫ��ÿ���з紵
�������еĲݾ��������ҡҷ����ͬ����һ�㣬��ϸ�۲�����ƺ��м���С�ض�����
����������֮��Ķ�������ｨ�����ǵķ��ӣ�����Σ�յĵط���������ণ���΢
�е�紵�ݶ�������ʹ�˾��ĵ���������ǰ���Ĳݵ��ϣ��ƺ���ʲ�ᶫ�����Ƕ���
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "north": ONEW"wild11",
     "west" : ONEW"wild9",
     "southeast" : ONEW"wild13", ]) );
set( "search_desc", ([
     "here":"@@to_search_here"
     ]) );
set_outside("eastland");
reset();
}

string to_search_here()
{
  object ob;

  if (be_search) 
    return "��û�з����κζ�����\n";
  ob=new(OMONSTER"cobra");
  ob->move(this_object()); 
  be_search=1;
  return "��������ǰ���Ĳݵأ�����һ����һֻ�۾��߱��㾪������������������Ŀ����㡣\n";
}

void reset()
{
  ::reset();
  be_search=0;
}
