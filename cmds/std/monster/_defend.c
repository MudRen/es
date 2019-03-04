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

int cmd_defend(string str)
{
	object damsel;
	string *foo;

	if (!str) return help();

	damsel = present(str, environment(this_player())) ;
	if (!damsel || !living(damsel))
		return notify_fail( "��Ҫ����˭��\n") ;
	write( 
                "���ƶ���" + damsel->query("c_name") + "ǰ�棬��" + to_chinese(subjective(damsel))
		+ "���ܹ�����\n") ;
	tell_object( damsel, 
		this_player()->query("c_name") + "�ƶ�����ǰ�棬������ܵ��˵Ĺ�����\n");

	damsel->add_temp("protectors", ({ this_player() }) ) ;
	this_player()->add_temp("protectees", ({ damsel }) ) ;
	return 1 ;
}

int help() {
	write ("Usage: defend <player>\n\n"+
"The defend command lets you protect a given player against attacks by\n"+
"monsters or other players. If you are protecting another player, then\n"+
"when you are in the same room as that player, all weapon attacks against\n"+
"that player will hit you instead. Spell attacks will not be stopped.\n"+
"\nSee also: undefend.\n") ;
	return 1 ;
}
