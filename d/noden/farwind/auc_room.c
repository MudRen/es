#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "�����㲥��������" );
	set_long(@C_LONG
������������������㲥���Ĳ����ң����Ǻܴ��һ�����䱻һ�澧Ө
��͸��ħ��ˮ��ǽ�ָ�����룬ǽ���Ǳ��м�������ò����Ů�����۾�����
������ħ��ˮ���ķ��������������Ľ��У�ǽ�����ȴ�����˵ȴ������Ķ�
����һЩ���ι�״��ħ�����ߣ��Ե�ʮ�����ҡ�
C_LONG
	);
	set( "light",1 );
	set( "objects", ([
      	        "guardian" : "/d/noden/farwind/monster/auc_guard"
        ]) );
	set( "exits", ([
                "north" : "/d/noden/farwind/bazz2",
        ]) );
	
	reset();
}
void init()
{
	add_action("do_get","get");
}

int do_get(string arg)
{
	tell_object(this_player(),
	"��������������Ƿ���һ�еĶ����ƺ���ʮ�����أ��ݷ���ס��һ�㡣\n");
	return 1;
}
int clean_up() { return 0; }
