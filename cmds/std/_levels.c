//#pragma save_binary

// _levels.c
// This command lists experience required for each level.
// By Annihilator 11-04-93

#include <stats.h>
#include <daemons.h>
#include <guilds.h>
//by cach 2001.5
#include <mudlib.h>
#include <org.h>

int cmd_levels(string arg)
{
        int i;
        object guild;
        string *c_titles;

        seteuid(getuid());
        guild = (object)GUILD_MASTER ( (string)this_player()->query("class") );
        c_titles = (string *)guild->query_c_titles();
        write("\n");
        for( i=1; i<=MAX_PLAYER_LEVEL-1; i++ ) {
                write( 
                     sprintf( "�ȼ� %2d : %30-s %8d �㾭��\n", i, c_titles[i-1], STATS_D->query_level_exp(i-1) ) 
                );
        }
        i=MAX_PLAYER_LEVEL;
        if(this_player()->query("level")<1)
        {
                write( 
                      sprintf( "�ȼ� %2d : %30-s %8d �㾭��\n", i, c_titles[i-1], STATS_D->query_level_exp(i-1) ) 
                );
   
               return 1;
         }

        guild = (object)GUILD_MASTER ( (string)this_player()->query("organization") );
        c_titles = (string *)guild->query_c_titles();

        for( i=1; i<=MAX_ORG_LEVEL; i++ ) {
                write( 
                        sprintf( "�ȼ� %2d : %30-s %8d �㾭��\n", MAX_PLAYER_LEVEL+i-1, 
                                  c_titles[i-1], NEW_GUILD->query_org_exp(i-1) ) 
                );
        }
        return 1;

}

int help()
{
                write( @C_HELP
ָ���ʽ: levels

���ָ����г�һ�����еȼ�������پ���ֵ���б�
C_HELP
                );
        return 1;
}
