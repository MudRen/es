#include <almuhara.h>

inherit ROOM;

int gua;

void create()
{
	::create();
	set_short("���¹㳡");
	set_long( 
@C_LONG_DESCRIPTION
�����һ���޴�Ĺ㳡�������л�Ȼ���ʵĸо���ʵ���޷�������Ĺ������������
�ص��½�����˴�Ĺ㳡���㲻������Щ�������˷־��⡣�㳡����һ����Բ�����Ĵ�ʯ��
����������һ�����(charm)���ӷ����Ϸ�����ǳ��ɫ�Ĺ�â��ӳ����ΧһƬ��ɫ��
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north" : TOMB"/square14", 
		"east" : TOMB"/square16",  ]) );
	add( "c_item_desc", ([
		"charm" :@AMULET_DESC
����һ��������������ҫ��ǳ��ɫ�Ĺ�â������Ը��ܵ���������������Ҳ\��\���
\��\������(get)������
AMULET_DESC
	]) );
	reset();	
}

void init()
{
	add_action( "get_amulet", "get" );
	add_action( "look_amulet", "look" );
}	

int get_amulet(string str)
{
	object player;
	
	player = this_player();
	
	if ( !str || str != "charm" )
		return 0;
	if ( gua )
		return 0;
	else 
		tell_object( player, 
			"���������������ʱ��ͻȻ����һ������....��������������� !!\n");
		tell_room( environment(player), 
			"��" + player->query("c_cap_name") + "�����������ʱ��ͻȻ����һ������....��������������� !!\n",
			player );
		new(MOB"/wind_guard")->move(environment(player));
		gua = 1;
		return 1;
}	

int look_amulet(string str)
{
	object player;
	
	if ( present("guard", this_object()) && str == "charm" )
		return 1;
	return 0;
}	