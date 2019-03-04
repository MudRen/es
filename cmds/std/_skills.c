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
			"��Ŀǰ��û��ѧ���κμ��ܡ�\n");
		return 1;
	}
	s = "��ļ�������:\n";
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
ָ���ʽ: skills

��ʾ��Ŀǰ�����м��ܣ�������� score ָ�������������״̬��
C_HELP
		);
	return 1;
}
