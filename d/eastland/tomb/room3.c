#include "almuhara.h"

inherit ROOM;
int bury,paper,pick;
void create()
{
	::create();
	set_short( "����ʯ��" );
	set_long( 
@C_LONG_DESCRIPTION
�������һ��СС��ʯ�ң���ǰ���ʯ�ұ��������������С��΢��������������ܿ�
��һ���.....���ƺ��ȵ�ʲ�ᶫ��������һ������.....�Ǿ����á������ϵķ�����ʽ��
�ӣ����Ի�ɢ����һЩ���ߣ���֪��Ϊʲ�����������
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"east" : TOMB"/room1",  ]) );
	set( "item_desc" , ([
		"skeleton" : "һ�ߺ��˵�����\��Ҳ��\���������һ�¡�\n" ]) );
	reset();	
}

void reset()
{
	bury = bury;
	::reset();
}

void init()
{
	add_action("search_skeleton", "search");
	add_action("bury_skeleton", "bury");
}

int search_skeleton(string str)
{
	object player;
	
	player = this_player();
	
	if ( !str || str == "")
		return 0;
	if ( bury ) return 0;
	if ( str == "skeleton" ) {
		if ( paper ) return 0;
		tell_object( player, 
			"������ϸ��Ѱ�ᣬ������һ����Ƥֽ��\n");
		new(ITEM"/paper1")->move(player);
		paper = 1;
		return 1;
		}
	else if ( str == "tools" || str == "tool" ) {
		if ( pick ) return 0;	
		tell_object( player,
			"�㷭�˷���Щ���ߣ�ֻʣ��һ��ʮ�ָ��ǿ��õġ�\n");
		new("/d/noden/moyada/obj/pick")->move( environment(player) );
		pick = 1;
		return 1;
		}
	else return 0;
}

int bury_skeleton(string str)
{
	object player,ob;
	
	player = this_player();
	
	if ( !str || str == "")
		return notify_fail("��ɶ??\n");
	if ( bury ) return 1;
	if ( str == "skeleton" ) {
		if ( !present( "pick" , player ) ) {
			tell_object( player, 
				"��û���ʵ��Ĺ��ߣ��������Ӳʯ�𣿣�\n"
				);
			return 1;
			}	
		else tell_object( player, 
			"����úõذ����˺����ᣬ��Ȼ���ֺ����²��˷�̺���һ����������ӡ�\n"
			);
			new(ITEM"/orbkey")->move( player );
			new(ITEM"/paper2")->move( player );
			bury = 1;
                        this_player()->set_explore("eastland#34");
			return 1;
		}
	else return notify_fail("��ɶ??\n");
}
