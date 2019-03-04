#include <takeda.h>

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
	set_short("��Ѩ");
	set_long( @C_LONG_DESCRIPTION
������һ����Ȼ�γɵ��Ҷ���������һ�Ⱥ�ʵ�Ĵ����ţ����ŷ��д���һ
����ĺ�������˼�������˵�����Ǹ����Σ��治֪����Щ���������᰾��ȥ
�ģ�ǽ����һ��С���ӣ�һ���������������ߺȾ�������
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"west" : TROOM"jail1",
	        "southwest" : TROOM"down_hall"
	        ]));
	set( "objects", ([
	        "han" : TMONSTER"han" 
	        ]));
	create_door( "west", "east", ([
	        "keyword" : ({"door", "iron door"}),
		"name" : "iron door",
		"c_name" : "����",
		"desc" : "A strudy iron door",
		"c_desc" : "һ�Ⱥ�ʵ�Ĵ�����",
		"status" : "locked",
		"lock" : "LiangShankey-1"
	]) );
	reset();
}
int clean_up() { return 0; }