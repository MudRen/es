//#pragma save_binary
// _effects.c	By Yueh 1995/3/1
// Lists a player's effects spells.

#include <mudlib.h>

inherit DAEMON ;

int cmd_effects()
{
	int i;
	string s;
	object me;
	
	me = this_player();
	i = 0;
	s = "";
	if ( me->query_temp("effect/energy-shield") ){
		s += sprintf("  %s(%s) \n", to_chinese("energy-shield"), "Energy-shield" );
		i++;
	}
	if ( me->query_temp("effect/mirror-shield") ){
		s += sprintf("  %s(%s) \n", to_chinese("mirror-shield"), "Mirror-shield" );
		i++;
	}
	if ( me->query_temp("effect/flamming-shield") ){
		s += sprintf("  %s(%s) \n", to_chinese("flamming-shield"), "Flamming-shield" );
		i++;
	}
	if ( me->query_temp("effect/ice-shield") ){
		s += sprintf("  %s(%s) \n", to_chinese("ice-shield"), "Ice-shield" );
		i++;
	}
	if ( me->query_temp("effect/magical-shield") ){
		s += sprintf("  %s(%s) \n", to_chinese("magical-shield"), "Magical-shield" );
		i++;
	}
	if ( me->query_temp("effect/heart-protect-shield") ){
		s += sprintf("  %s(%s) \n", to_chinese("heart-protect-shield"), "Heart-protect-shield" );
		i++;
	}

	if ( me->query_temp("effect/detect-invis") ){
		s += sprintf("  %s(%s) \n", to_chinese("detect-invis"), "Detect-invis" );
		i++;
	}

	if ( me->query_temp("effect/detect-hide") ){
		s += sprintf("  %s(%s) \n", to_chinese("detect-hide"), "Detect-hide" );
		i++;
	}

	if (i == 0){
		write("��Ŀǰû���κ�ħ�������С�\n\n");
		return 1;
	}
	
	s = sprintf ("��Ŀǰ���� %d ��ħ�������У�\n",i)+s;
	write(s);
	return 1;
}

int help()
{
	write ( @HELP
Usage: effects
���ָ��������㿴��Ŀǰ�������������ϵ�ħ�����ࡣ
HELP
) ;
	return 1 ;
}
