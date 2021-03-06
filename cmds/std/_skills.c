//#pragma save_binary

// _skills.c
// Command to show a player's skills.
// Created by Mobydick, 10-28-92, mostly ripped out of the existing _score.c

int cmd_skills(string arg)
{
	string *skillnames, *list, s;
	mapping skills;
	int i, j, k;
	object act_ob;

	if( arg && member_group(getuid(this_player()), "admin") )
		act_ob = find_player(arg);
	else act_ob = this_player();
	if( !act_ob ) act_ob = this_player();
	skills = act_ob->query_skills();
	skillnames = keys(skills);
	list = sort_array(skillnames, "sort_skills", this_object());
	if( !sizeof(list) ) {
		write(
			"你目前并没有学过任何技能。\n");
		return 1;
	}
	s = "你的技能如下:\n";
	for (i=0; i<sizeof(skills); i++) {
		j = act_ob->query_skill(list[i]);
		k = act_ob->query_perm_skill(list[i]);
		s += sprintf("  %15-s : %3d  (%3d)%s", 
			to_chinese(list[i]), j, k, (i%2?"\n":"\t\t") );
	}
	if( i%2 ) s += "\n";
	write(s);
	return 1 ;
}

int sort_skills (string s1, string s2)
{
	return strcmp(s1,s2);
}

int help()
{
		write( @C_HELP
指令格式: skills

显示你目前的所有技能，你可以用 score 指令看你现在其他的状态。
C_HELP
		);
	return 1;
}
