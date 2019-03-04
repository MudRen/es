//#pragma save_binary
/*
// This file is part of the TMI Mudlib distribution.
// Please include this header if you use this code.
// Originally written by Sulam (sometime)
// Rewritten cause of grossity by Sulam(1-22-92)
// Help added by Brian (1/28/92)
// tmp_home clonable workroom stuff put in by Pallando 92-12-20
// tmp_home stuff updated by Watcher 93-01-31
*/

#include <move.h>
#include <daemons.h>
#include <mudlib.h>
#include <fingerd.h>

inherit DAEMON;

int cmd_home( string pl_name )
{
	object pl_obj, tmp_home, old_env;
	string home_dir, home, c_mess, mess;

	if( pl_name ) {
		home = (string)FINGERD-> _query_environment( pl_name, "home" );
		if( !home ) home = "workroom";
		home_dir = user_path( pl_name );
		home = resolv_path( home_dir, home );
	    if( file_size( home ) < 0  && file_size( home + ".c" ) < 0 ) {
      if( !( pl_obj = find_player( pl_name ) ) ||
          !( tmp_home = pl_obj-> query( "tmp_home" ) ) )
      {
        notify_fail( "Couldn't find " + capitalize( pl_name ) + "'s home.\n" );
        return 0;
      }
    }
  } else {
    home = (string)this_player()-> getenv( "home" );
    if( !home ) home = "workroom";
    home_dir = user_path( geteuid( this_player() ) );
    home = resolv_path( home_dir, home );
  }
    
  if( environment(this_player()) &&
      file_name(environment(this_player())) == home) {
  	  write(
  	    "����һ���Ұ�? �㱾�����ڼ����ˡ�\n");
      return 1; 
  }
 
  mess = this_player()->query_mhome() + "\n";
  c_mess = this_player()->query_c_mhome() + "\n";
  old_env = environment(this_player());
  
  if( !file_exists(home) && !file_exists(home + ".c") ) {
   	if( !(tmp_home = this_player()->query( "tmp_home" )) ) {
      tmp_home = clone_object( "/obj/workroom" );
      this_player()->set( "tmp_home", tmp_home );
    }
    if( !tmp_home ||
    	(int)this_player()->move_player(tmp_home, "SNEAK") != MOVE_OK )
      return notify_fail(
     	"������ԭ�ء�\n");
  } else if( (int)this_player()->move_player(home, "SNEAK") != MOVE_OK )
    return notify_fail("������ԭ�ء�\n");
 
/*
  this_player()-> describe_current_room( this_player()-> query_verbose() );
  say( this_player()-> query_mmin() + "\n" );
*/
  tell_room(old_env, c_mess);
  return 1;
}

int
help() {
  write( "Command: home\nSyntax: home [player]\n" +
    "If no user is specified this command takes you to\n" +
    "your workroom.  If you do not have a workroom that\n" +
    "will load then you will go  to a cloned workroom.  If you name a\n" +
    "player then you will be taken to that player's workroom\n" +
    "instead.\n" );
  return 1;
}
/* EOF */
