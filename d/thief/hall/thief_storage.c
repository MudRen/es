#include <mudlib.h>
inherit ROOM;

init()
{
	add_action("do_drop","drop");
}
do_drop(string str)
{
	int tmp1,tmp2;
	string stmp1,stmp2;
	if ( ! wizardp(this_player()) ) return 0; 	// ����ʱ��
#if 0
	if ( !str ) return 0;
	if( sscanf(str, "%d %s %s", tmp1, stmp1, stmp2) == 3 ||
        	sscanf(str, "%d %s", tmp1, stmp1) == 2) return 0;
	if ( str == "all" )
		return notify_fail("��һ��һ����.\n");
#endif
	
}

void create()
{
	::create();
	set_short( "С͵���ᴢ����");
	set_long(	@C_LONG_DESCRIPTION
������С͵����Ĵ����ҡ�����ǰһЩ��Ǯ��С͵����ЩǮ��������������,
�ߵȼ���С͵��һЩ���ŵ�װ����������, �ṩ��Ҫ����ȡ�á�
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"east" : "/d/thief/hall/thief_shop" ]) );
}

int clean_up() { return 0; }
