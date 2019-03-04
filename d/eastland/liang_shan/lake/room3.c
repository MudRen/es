#include <takeda.h>
#include <move.h>
#include <stats.h>
#include <conditions.h>

inherit ROOM;

int crumb_present = 1;

void create()
{
	::create();
	set_short( "���" );
	set_long(
	"�������һ�������ķ��ӣ���������ӵ����ҳ��迴������������Ǹ�\n"
	"���ޱ߷����ˣ����ӵ��������һ�Ŵ�����(table)���������һЩ���Ӻ���\n"
	  );
        set("c_item_desc",(["table":
"����һ����ͨ�����ӣ�ʵ�ü�ֵԶԶ���װ�μ�ֵ���ӷ��������ϵĹ���\n"
"����꿴������������Ӧ�����Ų�\��\������\����������ҵ�Щ�ԵĶ�����\n"
            ]));        
        set( "exits", ([
                "east" : TROOM"village2"
        ]) );
        reset();
}
void init()
{
     add_action("do_search","search");
}
int do_search(string arg)
{
 object crumb;
 if ( !arg || arg != "table")
    return notify_fail(
    "Ҫ��ʲ��?\n");
	if( !crumb_present )
		write(
		    "�㷭�����������ӣ�Ҳû�ҵ�ʲ��óԵ�....\n"
		);
	else {
		write(@ALONG
����������������ȥ��ʲ��ԵĶ�û�ҵ��������������ʱ���㿴�����ӵ�
��϶�У���һЩ���м(crumb)�������˳�ְ����м�ڳ�����
ALONG
		);
		crumb_present = 0;
		crumb = new( "/d/eastland/liang_shan/obj/crumb" );
		if( (int)crumb->move(this_player()) != MOVE_OK )
			crumb->move( this_object() );
	        return 1;
	}
}
