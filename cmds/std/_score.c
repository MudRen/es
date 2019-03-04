//#pragma save_binary
 
//	File	:  /cmds/std/_score.c
//	Creator	:  Mobydick@TMI  (8-24-92)
//	Updated	:  Watcher@TMI   (4-10-93)
//
//	This command shows a user's status.

#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;
inherit COINVALUE;

// the function for color for any datas.
string query_attr_color(int current, int perm)
{
	switch( 100 * current / perm ) {
		case  0..20 : return "RED";
		case 21..40 : return "HIR";
		case 41..64 : return "HIY";
		case 65..90 : return "GRN";
			default : return "HIG";
	}
}

string query_stat_color(int current, int perm)
{
	if( current == perm ) return "HIC";
	if( current <  perm / 2) return "HIR";
	else return "HIG";
}

string query_coin_color(string type)
{
	switch( type ) {
		case "silver"   : return "HIC";
		case "gold"     : return "HIY";
		case "copper"   : return "HIM";
		case "platinum" : return "HIW";
		    default     : return "WHT";
	}
}

int cmd_score(string who)
{
	int level, age, exp, ali, money, i, limit, current, perm;
	string line, race, class1, gender, spouse, cond_str, clr;
	string *cond_name, *coins, *stat_names;
	mapping wealth, conds;
	object me;

	me = this_player();
	if( who && wizardp(me) && !(me=find_player(who)) )
		return notify_fail("û����λ���\n");

	// basic data.
	level = (int)me->query_level();
	age = (int)me->query("age")/86400 + (int)me->query("natural_age");
	exp = (int)me->query_experience();
	ali = (int)me->query("alignment");

	line = set_color(sprintf("�� %2d ��%s (%s)\n\n",
		level, 
		me->query("short"), 
		capitalize((string)me->query("name"))),
		"HIW");

	spouse = (string)me->query("spouse");
	race = (string)me->query("race");
	gender = (string)me->query("gender");
	class1 = (string)me->query("class");

	conds = (mapping)me->query("conditions");
	wealth = (mapping)me->query("wealth");

	if( !race ) race = "monster";
	if( !gender ) gender = "neuter";
	if( !class1 ) class1 = "adventurer";

	cond_str = "";
	if( sizeof(conds) ) {
		cond_name = keys(conds);
		for( i=0, limit=sizeof(cond_name); i<limit; i++ ) {
			if( cond_name[i][0] == '_' ) continue;
			cond_str += to_chinese(cond_name[i]);
//			cond_str = sprintf("%s %s", cond_str, to_chinese(cond_name[i]));
		}
	}
	if( cond_str == "" ) cond_str = "����";

	// print all data.

	line += sprintf(" ״  ̬ :   %s\n", set_color(sprintf("%s%s(%s)��%s�꣬%s��",
		to_chinese(race), to_chinese(class1), to_chinese(gender),
		chinese_number(age), cond_str), "HIC") );

	if( spouse ) line += sprintf(" ��  ż :   %s\n", set_color(spouse, "HIM"));

	line += sprintf(" ��  �� :   %s\n", set_color(exp, "HIY"));
	line += sprintf(" ��  Ӫ :   %s\n", STATS_D->alignment_string(ali));
	line += sprintf(" ״  �� :   %s\n\n", STATS_D->body_status_string(me));

//	write("\n");
	if( perm = (int)me->query("max_hp") ) {
		current = (int)me->query("hit_points");
		line += sprintf(" ��  �� : %8s \t/ %s\n",
			set_color(current, query_attr_color(current, perm)),
			set_color(perm, "HIG"));
	}
	if( perm = (int)me->query("max_sp") ) {
		current = (int)me->query("spell_points");
		line += sprintf(" ������ : %8s \t/ %s\n",
			set_color(current , query_attr_color(current, perm)),
			set_color(perm, "HIG"));
	}
	if( perm = (int)me->query("max_fp") ) {
		current = (int)me->query("force_points");
		line += sprintf(" ��  �� : %8s \t/ %s\n",
			set_color(current,	query_attr_color(current, perm)),
			set_color(perm, "HIG"));
	}
	if( perm = (int)me->query("max_tp") ) {
		current = (int)me->query("talk_points");
		line += sprintf(" ��̸�� : %8s \t/ %s\n\n",
			set_color(current ,query_attr_color(current, perm)),
			set_color(perm, "HIG"));
	}
/*	if( perm = (int)me->query("max_ap") ) {
		current = (int)me->query("action_points");
		line += sprintf(" �ж��� : %8s \t/ %s\n\n",
			set_color(current ,query_attr_color(current, perm)),
			set_color(perm, "HIG"));
	}
*/
//	write("\n");
	stat_names = (string *)STATS_D->query_stat_names();
	for( i=0, limit=sizeof(stat_names); i<limit; i++ ) {
		current = (int)me->query_stat(stat_names[i]);
		perm = (int)me->query_perm_stat(stat_names[i]);
		clr = query_stat_color(current, perm);
		line += sprintf(" %s : %2s %4s \t\t%s", to_chinese(stat_names[i]),
			set_color(current, clr), set_color(sprintf("(%2d)",perm), "HIC"),
			((i%2)?"\n":""));
	}

	line += "\n ";

	if( !wealth || !sizeof(wealth) )
		line += "���������޷��ġ�\n";
	else {
		coins = sort_array(keys(wealth), "sort_coins", this_object());
		money = 0;
		for( i=0, limit=sizeof(coins); i<limit; i++ ) {
			if( wealth[coins[i]] < 1 ) continue;
			clr = query_coin_color(coins[i]);
			line +=	set_color(to_chinese(coins[i] + " coin") + "\t\t" + wealth[coins[i]], clr) + "\n ";
			money += coinvalue(coins[i]) * wealth[coins[i]];
		}
		if( money < 1 ) line += "���������޷��ġ�\n";
	}
	write(line);
	return 1;
}

int sort_coins(string s1, string s2)
{
	int i,j;

	i=coinvalue(s1);
	j=coinvalue(s2);
	return j-i;
}

int help()
{
	write(@HELP
ָ���ʽ��score <����>

���ָ������鿴�Լ�������״����(����ʦ)�������Ҫ�鿴���ܣ�����
skills ָ�

HELP
);
	return 1;
}
