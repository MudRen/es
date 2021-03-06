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
			"你现在什麽也看不见，没有办法搜索。\n");

	env = environment( this_player() );
	if( !env ) return notify_fail( 
		"这里一片虚无，无从搜索起....\n");

	if( !arg || arg=="" ) arg = "here";
	if( (msg= env->query("search_desc/"+arg)) ) {
		write( msg );
	} else if( herbs_skill = this_player()->query_skill("herbs")
	&& (reagent = (mapping)env->query("reagents")) ) {
		// Healers can get reagents in some place.
		write( 
			"你找了又找，并没有发现任何东西。\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name") + "在这里四处搜索，不知道在找些什麽？\n",
		    this_player() );
	} else {
		write( 
			"你找了又找，并没有发现任何东西。\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name") + "在这里四处搜索，不知道在找些什麽？\n" ,
		    this_player() );
	}

	return 1;
}

int help() {
	write (@HELP
使用格式: search <目标>

这个指令将搜索四周或<目标>，是解谜手段之一.
HELP
);
	return 1 ;
}
 
