#include "../oldcat.h"

inherit ROOM;

int be_get1;
void create()
{
	::create();
        set_short("��Ժ");
	set_long( 
@LONG_DESCRIPTION
�����������Ժ��һС������������ֲ�ͬ���߲�(vegestable)���м�һ��С
����ͨ�����㻹������һ�ھ�(well)��
LONG_DESCRIPTION
	);

set( "exits", ([
     "west": OTEMP"temple13",
     "southeast":OTEMP"temple25"
     ]) );

set("item_desc",([
    "vegestable":"��һƬ�߲�԰�����������ֵģ�ʹ���ǿ����Ը����㡣\n",
    "well":@Well
һ���Ѿ�Ǭ\��\��\ˮ�����㿴��������һ��ˮ��û�У������Եģ���ھ��Ѿ�����
�ܾ��ˡ�
Well
   ]) );
set("search_desc",([
    "vegestable":"@@to_search_vegestable",
    ]) );
set_outside("eastland");
reset();
}

string to_search_vegestable()
{
  string str;
  object ob;

  if(be_get1==2)
    return "��û���ҵ��κ����õĶ�����\n";

  str="\n���ڲ�԰����ҵ�һ�������õĴ�Ͱ�ӡ�\n";
  ob=new(OOBJ"bucket");
  ob->move(this_player());
  be_get1++;
  return str;
}

void reset()
{
  ::reset();
  be_get1=0;
}
