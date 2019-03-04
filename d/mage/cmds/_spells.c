//#pragma save_binary
// _spells.c
// Lists a player's known spells.
// Mobydick@TMI-2, 1-31-93. Mobydick doesn't care who wins the Super Bowl.

#include <mudlib.h>

inherit DAEMON ;

int cmd_spells()
{
	int i,j;
	string *spell, s;
	mapping known;

	known = (mapping)this_player()->query("spells");
	if (!known || sizeof(known)==0) {
		write("��Ŀǰ�����κη�����\n");
		return 1 ;
	}

	s = "��Ŀǰ����ʹ�õķ�����:\n";
	spell = keys(known);
	j = sizeof(spell);
	for(i=0; i<j; i++)
		s += sprintf("  %s(%s) [%d] \n", to_chinese(spell[i]), 
			  capitalize(spell[i]), known[spell[i]] );
	write(s);
	return 1;
}

int help()
{
	write ( @HELP
Usage: spells
The spells command will list the names of all the spells you know.
See also: cast, magic.
HELP
) ;
	return 1 ;
}
