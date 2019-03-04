// this file will included by some monk in saulin. added by Kyoko.
#include "../saulin_temple.h"

inherit MONSTER;

void relay_message(string class1, string msg)
{
	string name,str;
	object who;
	if (!msg || sscanf( msg, "%s(%s)���˹�����", str,name )!=2 ) return;
                if( !who = find_player(lower_case(name)) ) return;
	if(!who->query_temp("saulin_killer") ) return;
	tell_room( environment(who), 
		sprintf("%s����%s���: �㾹��������ɱ��!!\n" ,this_object()->query("c_name"),who->query("c_name")), ({ this_object(), who })
	);
	tell_object( who, 
		sprintf("%s��������: �㾹��������ɱ��!!\n",this_object()->query("c_name"))
	);
	this_object()->kill_ob(who);
}
