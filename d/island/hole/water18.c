
#include <hole.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "����ʯ��Ѩ" );
	set_long(@LONG
���Ȼ����һ����ʪ�Ķ�Ѩ���������˵�ˮ���ɶ�Ѩ�������
��̧ͷһ���������������ߵ�����ʯ�ϣ���Ȼ���¼���������ˮ���
�������ϡ�ɲʱ��������ݷ������ɾ����������ǰ�������ϴִ��
����ʯ�м��γ�һ̲Сˮ�أ���ߵ�ˮ�������൱�峺�����������
�������ʯ��������ɵġ�
LONG
		);
	set( "exits",([ 
			"north" : HOLE"water19",
			"out" : HOLE"hole30",
		]) );
	set( "item_desc",([ 
	"pool" : "ˮ���������ӳ����ĵ�Ӱ������Ⱥ�(drink)��ߵ�ˮ��\n" ]) );
	set( "water_source",2 );
	reset();
	
}

void init(){ add_action( "to_drink","drink" ); }

int to_drink(string str)
{
	string him;
	object player;
	int max;

	player=this_player();
	him=player->query( "c_name" );
	max=player->query( "max_tp" );
	if( !str || str!="water" )
		return notify_fail( "��ʲ�᣿\n" );
	tell_room( environment(player),set_color(
	him+"������������һ�ڳ������ˮ���㷢��"+him+"�������������Ҹ��ı��顣\n","HIY" ),player );
	tell_object(player,set_color(
	"�����һ�ڳ������ˮ�ᣬ��ʱ���ú�ͷһ����ˬ��ͻȻ��󺰼�����\n","HIY" ) );
	player->set( "talk_points",max );
	player->force_me( "shout ���������ϣ�����Ч�� ES �����ж��ģ�Ը������ʦ�ʹ���PK��... " );
	return 1;
}