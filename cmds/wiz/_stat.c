//#pragma save_binary

// Command to show a living object's status.
// Created by Mobydick@TMI-2, 11-11-92
// Replaced an existing _stat command which had no header and which had
// lost all touch with reality.

#include <mudlib.h>
#include <money.h>
#include <daemons.h>

inherit DAEMON;
inherit COINVALUE;

int help() ;

int cmd_stat(string name)
{
	string *coins, *list, *statnames, *skillnames;
	object ob;
	mapping skills, stats, wealth;
	int i, flag, exp_reward;
	string spouse, tempstr, subj, poss;

	if (!name) return help();

	ob = get_object(name);
	if (!ob || !living(ob))
		return notify_fail("没有这种东西....。\n");

	printf(inverse("[ %2d ]")+bold(" %s\n\n"), ob->query_level(),
		ob->query("short"));

	subj = subjective(ob->query("gender"));
	poss = possessive(ob->query("gender"));
	tempstr = ob->query("race");
	
	if( tempstr ) write(
		"状  态: "+to_chinese(tempstr)+to_chinese(ob->query("class"))+
			"(" + to_chinese(ob->query("gender")) + ")\n" );

	if( (spouse=ob->query("spouse")) )
		write ("配  偶: "+capitalize(spouse)+"\n");

	if( !exp_reward = ob->query("exp_reward") )
		exp_reward = (int)ob->query_experience() / (ob->query_level() + 10);
	write("经  验: "+ob->query_experience() + " (" + exp_reward + ")\n");
	write("探险度: "+ob->query_explore_points()+" 点\n");
	write("阵  营: "+(int)ob->query("alignment") + " (" 
			+ STATS_D->alignment_string(ob->query("alignment"))+ ") \n");

	if( ob->query("max_hp") ) write( 
		"\n体  力: "+ob->query("hit_points")+"/"+ ob->query("max_hp")+"\n");
	if( ob->query("max_sp") ) write( 
		"法  力: "+ob->query("spell_points")+"/"+ob->query("max_sp")+"\n");
	if( ob->query("max_fp") ) write( 
		"内  力: "+ob->query("force_points")+"/"+ob->query("max_fp")+"\n");
        if( ob->query("max_tp") ) write( 
		"交谈能力: "+ob->query("talk_points")+"/"+ob->query("max_tp")+"\n");

	write( "\n" );
	statnames = STATS_D->query_stat_names();
	for (i=0;i<sizeof(statnames);i++)
		printf("%12-s : %d (%d)\t\t%s",
			to_chinese(statnames[i]), 
			ob->query_stat(statnames[i]),
			ob->query_perm_stat(statnames[i]),
			(i%2)?"\n":"" );
	write ("\n");

	ob->calc_weapon_class();
	ob->calc_armor_class();
	printf("防护等级: \t%d\t\t额外防御: \t%d\n",
		ob->query("armor_class"), ob->query("defense_bonus") );
	printf( 
		"主要武器等级: \t%d\t\t伤害力范围: \t%d - %d\n",
		ob->query("weapon_class1"),
		ob->query("min_damage1"),
		ob->query("max_damage1") );
	printf( 
		"次要武器等级: \t%d\t\t伤害力范围: \t%d - %d\n\n",
		ob->query("weapon_class2"),
		ob->query("min_damage2"),
		ob->query("max_damage2") );

	wealth = ob->query("wealth") ;
	if (!wealth) {
		write ("身无分文。\n");
	} else {
		coins = keys(wealth) ;
		list = sort_array(coins,"sort_coins",this_object()) ;
		flag=0 ;
		for (i=0;i<sizeof(coins);i++) {
			if (wealth[list[i]]>0) {
				printf( "   %15-s %d\n", 
					to_chinese(list[i] + " coin"),
					wealth[list[i]]);
				flag=1 ;
			}
		}
		if (flag==0) write( "身无分文。\n");
	}

	skills = ob->query_skills() ;
	if (skills && sizeof(skills)) {
		skillnames = keys(skills) ;
		write ("\n") ;

		list = sort_array(skillnames, "sort_skills", this_object()) ;
		for (i=0;i<sizeof(skills);i++)
			printf("%12-s(%12-s) : %3-d\t%s",
				to_chinese(list[i]), capitalize(list[i]),
				skills[list[i]], i%2?"\n":"");
		write( "\n" );
	}
	return 1 ;
}

int sort_skills (string s1, string s2) {
	return strcmp( s1, s2 );
}


int sort_coins(string s1, string s2) {
	return (coinvalue(s1)<coinvalue(s2)) ;
}

int help() {
	write (@HELP
Usage: stat <living name>
The stat command shows the scores of a living object.
HELP
	       );
	return 1 ;
}
