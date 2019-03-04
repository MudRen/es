//#pragma save_binary
// _say.c
// The ghost's say command. It won't actually give his message, but it will
// at least indicate to live players that he's around and unhappy. Clever
// ghosts will manage to communicate using this. ("One gust for yes, two
// gusts for no. Is your corpse north of here?")
// Written by Mobydick, 11-14-92. Loosely based on the existing player _say
// command.

#include <mudlib.h>

inherit DAEMON ;

int cmd_say (string str)
{
	write( 
		"����Ȼ��ǧ��������˵�����Ƕ�������������˶���ֻ��һ������ҲҶ��ѡ�\n",
	);
	tell_room( environment(this_player()), 
		"��е�һ����ɭ�����⣬�ƺ�����ʲ��������\n",
		this_player() );
	return 1;
}
