#include <almuhara.h>
 
inherit ROOM;
 
void create()
{
	::create();
	set_short("����");
	set_long( 
@C_LONG_DESCRIPTION
���߽���һ�䲻������ң�������Ƚ�֮�£�����Ե��൱���ء�������ͨ�ļҾ��⣬
����һ�����������ء����ӳɰ�����״�����������ĸ�С���ۣ��������Ը���һ���εİ���
����֪����������ʲ�ᶫ���ġ��㻷�����ܣ�ȴ�Ҳ���ʲ����Ȥ�Ķ����ˡ�
C_LONG_DESCRIPTION
	);
 
	set( "exits", ([ 
		"north" : TOMB"/house2",  ]) );
	set( "objects", ([
		"wife" : MOB"/wife" ]) );
        set("c_item_desc",(["box":@C_LONG
������ӿ�����֣�������ʵ���о��������Ǹ�ɶ�õ�......Ҳ������������ˡ�
C_LONG
      ]));
	reset();	
#include <replace_room.h>
}
 
