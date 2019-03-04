#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "���" );
	set_long(
	"�������һ��Ͱ��ķ��ӣ�������û��ʲ���\�裬����һ�ֿտյ���\n"
	"�ĸо���ǽ����һ��С���ӣ���������ɽ����������ϵ����磬��ʱ�Ӵ�\n"
	"���д����������·���һ�Ŵ���һ���������ĺ��ص������������ڴ��ϡ�\n"
	  );
        set("c_item_desc",(["bed":
"����һ����ͨ��ľ������������˯�����⣬û�������Ĺ�\��\������ı��춼��\n"
"Ǭ�����ɴ˿�����������Ų������������ϡ�\n"
            ]));        
        set( "exits", ([
                "west" : TROOM"village2"
        ]));
        set( "objects", ([
                "lady" : TMONSTER"dapo"
        ]) );
        reset();
}
void init()
{
     add_action("do_search","search");
}
int do_search(string arg)
{
 if ( !arg || arg != "bed")
    return notify_fail(
    "Ҫ��ʲ��?\n");
 if ( !present("da") ) 
    return notify_fail(
    "���ڴ��Ϸ��˰��죬�Ҳ����κο��õĶ���.....\n");
write(@ALONG
���ڴ��Ϸ�����ȥ����С�����������ţ��������������ˣ�������������һ��
���: С�����ӣ�û�������ﴲ����ʲ��? ��Ͽ�����վ��
ALONG
		);
	        return 1;
}
