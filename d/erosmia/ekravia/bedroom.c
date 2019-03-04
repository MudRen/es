#include "ekravia.h"
inherit BASE_ROOM;

int		room_working;

void	create()
{
	::create();
	set_light(1);
	set_short("�ùݷ���");
	set_long(
@CLong
�������ùݵĿͷ�������ӳ����������һ��ľ�ƵĴ�, ���������
������׵Ĵ������ޱ���һ������ͷ����������ƽ������, ���ݳ�ֻҪ��
���Ŵ�����˯һ������, ���е����˶����Բ�ҩ������
    ���Ա���һ��С����, �����\��һ�澵����һյ�͵ơ��ڴ�����һ��
����һ�����³�����������һЩ�Ҿ�, ��˯�����������Ͼ��������ˡ�
CLong
);
	set("exits", ([
		"out"		: HERE"corridor2",
		]));
}

void	init()
{
	int		sleep_time;

	::init();
	if (!room_working)
	{
		room_working = 1;
		call_out( "do_sleep", 2, this_player() );
		sleep_time = random(60) +60;
		call_out( "wake_up", sleep_time, sleep_time, this_player(), 
			this_object() );
	}
}

void	do_sleep(object ob)
{
	if (ob) {
		tell_object( ob, "��������һ��, ���ñ������˯����\n" );
		ob->set_temp("block_command", 1);
	}
}

void	wake_up(int time, object ob, object this_room)
{
	object	key;

	if (ob) {
		ob->add( "hit_points", time*3/2 );
		if ( ob->query("hit_points") > ob->query("max_hp") )
			ob->set("hit_points", ob->query("max_hp") );
		ob->add( "spell_points", time*2 );
		if ( ob->query("spell_points") > ob->query("max_sp") )
			ob->set( "spell_points", ob->query("max_sp") );
		ob->add( "talk_points", time*4 );
		if ( ob->query("talk_points") > ob->query("max_tp") )
			ob->set( "talk_points", ob->query("max_tp") );
		ob->add( "medication_resistance", -time*5 );
		if ( ob->query("medication_resistance") < 0 )
			ob->set( "medication_resistance", 0 );
		ob->set_temp("block_command", 0);
		tell_object( ob, "��һ������, �о�������ȫ�ָ��ˡ�\n" );
		tell_object( ob, "��򿪷�������¥\n\n" );
		ob->move_player(HERE"corridor2", "", "out");
		key = present( "copper key", ob);
		if ((key) && (base_name(key) == OBJ"tavern_key")) 
			key->remove();
		key = present( "silver card", ob);
		if ((key) && (base_name(key) == OBJ"silver_card")) 
			key->use_card();
		this_room->remove();
	}
}