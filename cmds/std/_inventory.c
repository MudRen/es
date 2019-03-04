//#pragma save_binary

/*
// This file is part of the TMI Distribution Mudlib.
// Please include this header if you use this code.
// Slick Ace, 01/02/91
// Help added by Brian (1/28/92)
// Rewritten by Buddha to show equipped items properly (2/3/92)
// Changed by Mobydick@TMI-2 (9/16/92) to capitalize short descriptions
// and to handle the new equipping system.
// Replaced the hardcoded weight limit with included #defines. Moby, 4-26-93
*/

// Modified by Annihilator to fit mounted animals.

#include <move.h>
#include <player.h>
#include <mudlib.h>

#define SHORT_DESCRIPTION "short"

inherit DAEMON ;

int filter_invis(object ob, object carrier)
{
	return visible(ob,carrier);
}
int cmd_inventory(string arg)
{
	object *items, me, ob;
	int coin, i, x, count;
	string result, tmp, *names, unit;
	mapping inv;

	count = 0;
	if( arg && wizardp(this_player()) ) {
		me = find_living(arg);
		if( !me ) return notify_fail("û�������....��\n");
	} else me = this_player();

	coin = me->coins_carried();
	items = filter_array(all_inventory(me), "filter_invis", this_object(), me);
	for (i = 0; i < sizeof(items); i++)
		if(items[i]->query(SHORT_DESCRIPTION))
			count++;
	result = count? ("�������ܹ����� "+count+" ����Ʒ" + (coin?("���� "+coin+" öǮ��: \n"):": \n"))
			 : ("����������û���κζ���"+(coin?"�������� "+coin+" öǮ�ҡ�\n":"��\n"));

	result += sprintf("(������ %d.%d ����, ���� %d.%d ����)\n",
		(int)me->query("load")/10,
		(int)me->query("load")%10,
		(int)me->query("max_load")/10,
		(int)me->query("max_load")%10);

	ob = me->query_temp("mounting");
	if( ob ) result += 
		"������������һ" + ob->query("unit") + ob->query("c_name") + "�ϣ��� * �Ǻŵ���Ʒ\n"
		"��ʾ�����������ϡ�\n";

// Always use compact mode. Compact mode is more convenient for players.
// It also costs fewer eval cost when the user carry many objs of the same.
//                            Modified by Iris 2/24/96
//	if( this_player()->getenv("compact") ) {
		inv = unique_mapping(items, "query", "short");
		names = keys(inv);
		for (x=sizeof(names)-1; x > -1; x--) {
			if(tmp=(string)inv[names[x]][0]->query(SHORT_DESCRIPTION)) {
		tmp += " ("+inv[names[x]][0]->query("name")+")";
		if( inv[names[x]][0]->query("wielded")) tmp += " (����)";
		if( inv[names[x]][0]->query("equipped")) tmp += " (����)";
		if( inv[names[x]][0]->query("invisible")) tmp += " (����)";
		if( inv[names[x]][0]->query("mounted")) tmp += " (����)";
		if( inv[names[x]][0]->query("secure")) tmp+= " [����趨]";
				if( sizeof(inv[names[x]]) > 1 ) {
					if( !unit= inv[names[x]][0]->query("unit") ) unit = "��";
					tmp = chinese_number(sizeof(inv[names[x]])) + unit + tmp;
				}
				if( inv[names[x]][0]->query("on_mounted")) result += "* " + tmp + ".\n";
				else result += "  " + tmp + ".\n";
			}
		}
//	}
/*	else for (x=0; x < sizeof(items); x++) {
		if(tmp=(string)items[x]->query(SHORT_DESCRIPTION)) {
		tmp += " ("+items[x]->query("name")+")";
		if(items[x]->query("wielded")) tmp += " (����)";
		if(items[x]->query("equipped")) tmp += " (����)";
		if(items[x]->query("invisible")) tmp += " (����)";
		if(items[x]->query("mounted")) tmp += " (����)";
		if(items[x]->query("secure")) tmp += " [����趨]";
		if(items[x]->query("on_mounted")) result += "* " + tmp + ".\n";
			else result += "  " + tmp + ".\n" ;
		}
	}
*/
	write(result);
	return 1;
}

int help()
{
	write( @HELP
ָ���ʽ: inventory

	���ָ������г�������������Я������Ʒ��
HELP
	);
	return 1;
}
/* EOF */
