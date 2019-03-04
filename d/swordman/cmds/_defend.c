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

int cmd_defend(string str)
{
	object damsel,*prot,*prot2;
	string *foo;
	int	i;

        prot = (object *)this_player()->query_temp("protectees");

	if (!str) {
		if ( sizeof(prot) < 1 )
			return notify_fail("������û�б����κ��ˡ�\n");
		prot2 = ({ }) ;
		for ( i=0 ; i < sizeof(prot) ; i++) 
			if ( !nullp(prot[i]) && prot[i]) prot2 += ({ prot[i] }) ;
		prot = prot2 ;
		this_player()->set_temp("protectees",prot);
		write(set_color("�����ڱ����� :\n","HIY",this_player()));
		for ( i=0 ; i < sizeof(prot) ; i++)
			write(sprintf("%s(%s)\n",prot[i]->query("c_name"),prot[i]->query("name")));
		return 1;
	}

	damsel = present(str, environment(this_player())) ;
	if (!damsel || !living(damsel))
		return notify_fail("��Ҫ����˭��\n");

        if( prot && pointerp(prot) ) {
                if ( member_array( damsel,prot ) != -1 )
                return notify_fail("���Ѿ����������� !!\n");
		if (sizeof(prot) > 6 )
		return notify_fail("�㲻�ܷ��ı���������� !!\n");
	}

	write( sprintf("���ƶ���%sǰ�棬��%s���ܹ�����\n",damsel->query("short"),to_chinese(subjective(damsel))));
	tell_object( damsel, 
		sprintf("%s�ƶ�����ǰ�棬������ܵ��˵Ĺ�����\n",this_player()->query("c_name")));

	damsel->add_temp("protectors", ({ this_player() }) ) ;
	this_player()->add_temp("protectees", ({ damsel }) ) ;
	return 1 ;
}

int help() {
	write (@HELP
Usage: defend <player>
       
The defend command lets you protect a given player against attacks by
monsters or other players. If you are protecting another player, then
when you are in the same room as that player, all weapon attacks against
that player will hit you instead. Spell attacks will not be stopped.

See also: undefend.
HELP
	       );
	return 1 ;
}
