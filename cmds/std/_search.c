//#pragma save_binary

// search.c
// This is a default search command that doesn't find anything. The main
// purpose of it is that if a player searches in a room that doesn't have
// anything to search for, he gets the "You search but find nothing" instaed
// of "What?". If a room defines a search command via add_action it will
// override this command. (If it doesn't then dike this command out!)
// Written by Mobydick, 11-13-92
// If you use this code, please leave this header in.
// If you don't, the Code Police will hunt you down and kill you.
// Added cusstomized messages by Annihilator@Eastern.Stories (12-19-93)

int cmd_search(string arg)
{
	object env;
	string msg, func;
	int herbs_skill;
	mapping reagent;

	if(!this_player()->query("vision")) 
		return notify_fail(
			"������ʲ��Ҳ��������û�а취������\n");

	env = environment( this_player() );
	if( !env ) return notify_fail( 
		"����һƬ���ޣ��޴�������....\n");

	if( !arg || arg=="" ) arg = "here";
	if( (msg= env->query("search_desc/"+arg)) ) {
		write( msg );
	} else if( herbs_skill = this_player()->query_skill("herbs")
	&& (reagent = (mapping)env->query("reagents")) ) {
		// Healers can get reagents in some place.
		write( 
			"���������ң���û�з����κζ�����\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name") + "�������Ĵ���������֪������Щʲ�᣿\n",
		    this_player() );
	} else {
		write( 
			"���������ң���û�з����κζ�����\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name") + "�������Ĵ���������֪������Щʲ�᣿\n" ,
		    this_player() );
	}

	return 1;
}

int help() {
	write (@HELP
ʹ�ø�ʽ: search <Ŀ��>

���ָ��������ܻ�<Ŀ��>���ǽ����ֶ�֮һ.
HELP
);
	return 1 ;
}
 
