#include "../oldcat.h"

inherit ROOM;

int be_get2,be_get3;
void create()
{
	::create();
    set_short( "���������");
	set_long( 
@LONG_DESCRIPTION
����һ����������ң���ߵļ���(shell)�Ͼ���һЩ����ʱ��Ҫ�����Ķ�����
�ұߵĹ���(closet)�����һЩ��������֮��ģ�����һЩ���̵��ӵ����󣬵�����
�⻹����һ��������Ӱ˵���Ʒ��
LONG_DESCRIPTION
	);
set( "exits", ([
     "east": OTEMP"temple13",
     ]) );
set("item_desc",([
    "closet":"һ����ľ���ӣ���������Ѿ��������ˣ�����ŵ���һЩ����֮��Ķ�����\n",
    "shell":"һ�����ܣ���ÿһ��ļ����϶��б�ʾ����ǰ�\��һ��Ķ�������ͷ���ŵļ����װ\n���������\n",
    ]) );
set("search_desc", ([
    "closet":"@@to_search_right",
    "shell":"@@to_search_left",
    ]) );
reset();
}

string to_search_right()
{
  string str;
  object ob;

  if (be_get2)
    return "��û���ҵ��κ����õĶ�����\n";
  str="\n��ѹ��Ӵ򿪣�����һ�£��ҵ�һֻС��ӡ�\n";
  ob=new(OOBJ"club");
  ob->move(this_player());
  be_get2=1;
  return str;
}

string to_search_left()
{
  string str;
  object ob;

  if (be_get3)
    return "��û���ҵ��κ����õĶ�����\n";
  str="\n���ڼ����������ң�����ҵ�һ�鲼��\n";
  ob=new(OOBJ"cloth");
  ob->move(this_player());
  be_get3=1;
  return str;
}

void reset()
{
  ::reset();
  be_get2=0;
  be_get3=0;
}
