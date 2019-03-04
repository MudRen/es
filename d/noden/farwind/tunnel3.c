//#pragma save_binary
 
#include <mudlib.h>
 
inherit ROOM;
 
void create()
{
	::create();
    set_short("��Ѩ");
	set_long( @C_LONG_DESCRIPTION
������һ���ȽϿ��ĵ�Ѩ����Ѩ�������ϵ���ˮ�ε��������ڵ��ϵγ�
һ��Сˮ��( pool )����ע�⵽ˮ���Ա��м���С���ѣ�����һ�������Ա���
Ȼ����һ�߰׹�( skeleton )��
C_LONG_DESCRIPTION
	);
 
	set( "exits", ([
		"northeast" : "/d/noden/farwind/tunnel2.c",
	]) );
   set( "item_desc", ([
	"pool" : "һ���൱ǳ��Сˮ��, �����ƺ���Щ������\n",
	"skeleton" : "һ���൱���ƵĿݹ�, �����ֹ��ƺ���ָ��ˮ�ء�\n",
	]) );

        set("search_desc",([
                     "pool" : "@@to_search_pool"
                  ]));

	set( "objects", ([
		"crazy rat" : "/d/noden/farwind/monster/crazy_rat"
	]) );
	reset();
}

void init()
{
	if( this_player() ) this_player()->set_explore( "noden#2" );
}

int to_search_pool()
{
   if( present("crazy rat",this_object()) )
   {
	write( "�Ȱѷ�������߰�!\n" );
	return 1;
   }
  write("�㿿��ˮ�ߣ���С��һ�Ų���ȥ��������\n");
  this_player()->move_player("/d/noden/drow/r41","SNEAK");
  return 1;
}
