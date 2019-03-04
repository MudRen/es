#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("���¹㳡");
	set_long( 
@C_LONG_DESCRIPTION
�����һ���ǳ���Ĺ㳡���뵽�ڵص��¾�����˴�Ĺ㳡���㲻�����������Щ��
���˴��Ĺ����������Ŀ���Ƶ��㳡����ʱ����ֱ�޷������۾��������ľ���----�����Ǿ�
���澰!!�㿴��һ����Ȼ�γɵĳ��ӣ�ˮ�����滺������ת���������������뾹��һ������
�Ļ���!!����������ʽ�Ȼ��ͬ�Ķ����������ڴ˹���������Ǣ���޹ֺ����ʦ�������
�ϣ�����Ĺ춴ˣ��������һ�������֮�����ı�Ѩ��
C_LONG_DESCRIPTION
	);
	set( "light", 1);
	set( "exits", ([ 
		"north" : TOMB"/square19",
		"south" : TOMB"/square17", 
		"east" : TOMB"/square18",
		"west" : TOMB"/square20" ]) );
	reset();	
}

void init()
{
	add_action("search_pool","search");
}

int search_pool(string str)
{
	object ob,player;
	
	player = this_player();
	
	if ( !str || str == "" ) 
		return 0;
	if ( str == "pool" ) {
		if ( present("golden dragon orb", player) && !player->query_temp("ORB_POOL") ) {
			tell_object( player,
				"�㿿��������׼����������Ȼ�����ϵĽ����鼰���л���Թ�â��ʢ !! \n"
				"\n"
				"������Զ������¡¡��������\n"
				);
			player->set_temp("ORB_POOL",1);	
			return 1; }
		else tell_object( player,
			"�㻷����������������ȴû��ʲ���ر�ĵط���\n" );
			return 1; }
	else return 0;
}						