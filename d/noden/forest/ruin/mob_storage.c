#include "ruin.h"
inherit ROOM;

#define MIN_GARGOYLES 6

void create()
{
	::create();
	set("light", 0);
    set_short("�ض�");
    set_long(@CLong
������һ��, ���ں�С, �ƺ������Ѩ�����ܾ����㾹Ȼû����
��, �������ϵĻҳ�, ��ʼ�۲�����... ����Ĳ���: ���Ź��ϵ�ʯ����
��ɢ�ҵ��ڵ��ϵ�ʯ�顢���Ű�����ڵ��ϵ�ʯ��Ⱥ�����ż���ڼ�ֱһ
ģһ��, ������е���һЩ��̫�Ծ�... ����ϸһ��... ��Ȼ����: ����
���ǵ���, �ǻ�������... ��
CLong
    );
    set("mob_storage", MIN_GARGOYLES);
  	reset();
}

void init()
{
	add_action("climb_up", "climb");
}

int climb_up(string arg)
{
	int skill;
	object player;
	if( !arg || !(arg == "out" || arg == "up") )
		return notify_fail("Climb what?\n");
	player = this_player();
    skill = player->query_skill("climbing");
    skill += 5;
    if( random(65) < skill ) {
      tell_object( player, "��С����������˳�ȥ��\n" );
      tell_room( environment(player),
        player->query("c_name")+"���˳�ȥ��\n" , player );
      player->move_player( RUIN"entry", "SNEAK" );
      tell_room( environment(player),
        player->query("c_name")+"ͻȻ�ӵ������˳�����\n", player
      );
      player->set_explore("noden#18");
    } else {
      tell_object( player,"�㳢��������ȥ������ֻ���������\n" );
      tell_room( environment(player),
        player->query("c_name")+"����������ȥ������ֻ���������\n" , player
      );
    }
    return 1;
}

int is_a_gargoyle(object mob)
{
	if( (string)mob->query("name") == "Gargoyle" ) return 1;
	return 0;
}

void reset()
{
	int i;
	object *gargoyles;
	gargoyles = filter_array(
		all_inventory(this_object()), "is_a_gargoyle", this_object() );
	for( i=sizeof(gargoyles); i<query("mob_storage"); i++ )
		new(MOB"gargoyle")->move(this_object());
	::reset();
}
