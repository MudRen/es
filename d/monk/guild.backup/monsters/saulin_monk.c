// this file will included by some monk in saulin. added by Kyoko.
#include "../saulin_temple.h"

inherit MONSTER;

void receive_message(string class, string msg)
{
	string name;
	object who;
	if( !msg || sscanf(msg, "%s arrives.\n", name) != 1 ) return;
	who = find_living( name );
	if( !who || !who->query_temp("saulin_killer") ) return;
	tell_room( environment(who), ({
		this_object()->query("cap_name")+" shouts: Killer!!\n",
		this_object()->query("c_cap_name")+"����"+who->query("c_name")+
		"���: �㾹��������ɱ��!!\n" }), ({ this_object(), who })
	);
	tell_object( who, can_read_chinese(who) ?
		this_object()->query("c_cap_name")+"��������: �㾹��������ɱ��!!\n":
		this_object()->query("cap_name")+" shouts: Killer!!\n"
	);
	this_object()->kill_ob(who);
}

void die()
{
	object killer;
	killer = this_object()->query("last_attacker");
	killer->set_temp("saulin_killer", 1);
	::die();
}
