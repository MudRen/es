#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("�鷿");
	set_long( 
@C_LONG_DESCRIPTION
����һ����ɨ���൱Ǭ�����鷿�����ܵļҾ߰��衢���ҵ��ֻ��ȵȣ����ڶ���ʾ����
�����˵�Ʒζ���С�ǽ�ߵ�����Ϸ����˸������ֵ��鼮������������㿴���������֡�һ
�������������������ϵ�С��¯Ʈ�𣬵�����̴���������ʮ��������㿴����������һЩ
�߲ʵ�ʯͷ(stones)���������ķ������ƺ��е���Ź֡�
C_LONG_DESCRIPTION
	);

	add( "c_item_desc" , ([
		"stones" : @STONE_DESC
����ע������Щʯͷʱ���е�һ��ͷ��Ŀѣ�����������
STONE_DESC
,  
	]) );
	set( "exits", ([ 
		"south" : TOMB"/house2",  ]) );
	set( "objects", ([
		"master" : MOB"/master" ]) );
	reset();	
}

void init() 
{
	object *obj;
	int i;
	
	obj = all_inventory(this_object());
		i = sizeof(obj);
	if( random(7) > 2 ) {
		while( i-- ) {
			if( (int)obj[i]->query("player_invisible") ) 
				obj[i]->set("player_invisible",0); }
		tell_room(this_object(),"���ϵ��߲�ʯ��������Ĳ���....\n");
	}
}

int clean_up() {return 0;}