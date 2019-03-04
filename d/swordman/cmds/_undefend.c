//#pragma save_binary
// _protect.c
// The protection command. One player may protect another. If A protects B,
// then all attacks directed against player B hit player A instead.
// Protection loops are not allowed; that is, if A protects B and B
// protects C, then attacks against A hit B regardless of C's best
// intentions.
// This makes it possible for fighters to protect spellcasters while
// spells are cast, for high-skill players to protect low-skill ones,
// whatever you like.
// Mobydick, 6-13-93

#include <mudlib.h>

inherit DAEMON;

int help();
int cmd_undefend(string str)
{
	object *foo, *tmp, me;
	int i, j, done;

	if( !str ) return help();
	me = this_player();
	foo = (object *)me->query_temp("protectees");
	if( sizeof(foo) < 1 )
		return notify_fail("�����ڲ�û�б����κ��ˡ�\n");
	done = 0;
	for( i=sizeof(foo)-1; i>=0; i-- ) {
		if ( !foo[i] ) continue ;
		if( !foo[i]->id(str) ) continue;
		write(sprintf("��ֹͣ����%s(%s)��\n", foo[i]->query("c_name"),
				foo[i]->query("name")));
		tell_object( foo[i], 
			sprintf("%s(%s)ֹͣ�����㡣\n", me->query("c_name"),
				me->query("name")));
		tmp = foo[i]->query_temp("protectors");
		tmp -= ({ me });
		foo[i]->set_temp("protectors", tmp);
		foo[i] = 0;
		done++;
	}
	if( done ) {
		if( sizeof(foo) > done ) {
			done = 0;
			tmp = allocate(sizeof(foo)-done);
			for( i=sizeof(foo)-1; i>=0; i-- ) {
				if( foo[i] == 0 ) continue;
				tmp[j] = foo[i];
				j++;
			}
			me->set_temp("protectees", tmp);
		} else me->delete_temp("protectees");
	} else return notify_fail( 
		"�����ڲ�û�б����κν��� " + str + " ���ˡ�\n");
	return 1;
}

int help() {
	write (@HELP
Usage: undefend <player>

If you are protecting <player> against attacks, then the undefend
command will allow you to stop protecting them.

See also: defend.
HELP
) ;
	return 1 ;
}
