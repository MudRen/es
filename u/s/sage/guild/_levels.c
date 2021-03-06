//#pragma save_binary

// _levels.c
// This command lists experience required for each level.
// By Annihilator 11-04-93

#include <stats.h>
#include <daemons.h>
#include <guilds.h>

int cmd_levels(string arg)
{
	int i;
	object guild;
	string *c_titles;

     guild = (object)GUILD_MASTER ( (string)this_player()->query("class") );
	c_titles = (string *)guild->query_c_titles();

	for( i=1; i<=MAX_PLAYER_LEVEL; i++ ) {
		write( 
			sprintf( "等级 %2d : %30-s %8d 点经验\n", i, c_titles[i-1], STATS_D->query_level_exp(i-1) ) 
		);
	}
	return 1;
}

int help()
{
		write( @C_HELP
指令格式: levels

这个指令会列出一份所有等级各需多少经验值的列表。
C_HELP
		);
	return 1;
}
