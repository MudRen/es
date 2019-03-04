#include "ruin.h"
inherit ROOM;

#define GARGOYLE_NUM_ONCE 4
#define GARGOYLE_NUM 2
#define MAX_GARGOYLES 16

void create()
{
	::create();
	set_outside("noden");
	set_short("�ż�");
	set_long(@CLong
���Ź��ϵ�ʯ���� (statues)�� ɢ�ҵ��ڵ��ϵ�ʯ�� (stones)����
�Ű�����ڵ��ϵ�ʯ��Ⱥ, ��ǰ��������ĳ����������ԡ���ҫ�����
��! ����ʱ����ȥ, �⻪����, ���ڴ˱����������֮��, Ҳ�������Զ
�����ر�������, ���ö�֪�ˡ������ҵ�ʯ��Ⱥ��, һ���˹�����Ķ�Ѩ
�����ڰ��ڵ������ڱ�����ɽ���ϡ��ϱ�����ͨ���Ϸ�ɽ��ش���С����
CLong
);
	set("exits",([
              "south"	: RUIN"hidden_path4",
              "north"	: RUIN"s_hall",
             ]));
    set("exit_suppress", ({ "north", }) );

	add("item_desc", ([
		"statues": @C_ITEM_DESC_1
    ��Щʯ������ʯ��� (gargoyle) �������������, ���Ǹ��и���
��̬, ��������������\����������ġ������, ��������������õ�ʱ��
, ħ�����������ʧ�����ˡ�
C_ITEM_DESC_1
,		"stones"	: @C_ITEM_DESC_2
    һ��ɢ�ҵ�ʯͷ, ��Щ����ԭ���Ǹ���֪����ΰ�����е�һ���ݡ�
��Щʯͷ�ϻ�������Լ�ؿ��������ĵ��ͼ����
C_ITEM_DESC_2
,		"tunnel": @C_ITEM_DESC_3
    �������Ϊһ����Ѩ, ���������Ϊͨ���Ƚ�ǡ��, ��Ѩ��ǽ�ڶ���
ʯ����, �����൱�Ŀ��, �ƺ�ͨ���൱��ĵط�������������ԼԼ����
�����ڴ���һ�ɳ�����
C_ITEM_DESC_3
		]));
		
	set( "pre_exit_func", ([
		"north" : "loop_exit" ]) );
//	set( "search_desc", ([
//    	"here" : "@@search_here" ]) );
	set("seal", GARGOYLE_NUM);
	reset();
}

int loop_exit()
{
	int i;
	object me, storage;
	
	me = this_player();
	if( !me->query("invisible") && present( "gargoyle", this_object() ) ) {
		write( 
		"ʯ���ס�����ȥ·, ʹ���޷����붴Ѩ��\n");
		tell_room( environment(me), 
	sprintf("%s����붴Ѩ, ���Ǳ�ʯ���ס�ˡ�\n", me->query("c_name"))
		, me);
		return 1;
    } 
	if( me->query("invisible") || query("seal") < 1 ) return 0;
	write( 
	"��������Ѩ��ȥ, ͻȻ��һ������Ĺ���ʯ���з���, ��ס�����ȥ·��\n"
 	"��������ֻʯ����۾�һ��, ����������\n" 
	);
	tell_room(this_object(),
		sprintf("%s������������ȥ, ͻȻ��һ������Ĺ�â��ʯ���з�������������\n"
			"ֻʯ����۾�һ��, ���˹���\n", me->query("c_name"))
		, me
	);
	tell_room(find_object(RUIN"mob_storage"),
		"ͻȻ��һ������Ĺ�â��ʯ��������з�����������ֻʯ�����˹�����\n"
	);
	storage = find_object_or_load(RUIN"mob_storage");
	for( i=0; i<GARGOYLE_NUM_ONCE; i++ ) {
		if( (int)storage->query("mob_storage") < MAX_GARGOYLES )
			storage->add("mob_storage", 1);
		new(MOB"gargoyle")->move(storage);
		new(MOB"gargoyle")->move(this_object());
	}
	add("seal", -1);
	return 1;
}

void reset()
{
	::reset();
	set("seal", GARGOYLE_NUM);
}
