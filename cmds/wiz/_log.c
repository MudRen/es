//#pragma save_binary
/*
// Author (??)
// Help added by Brian (1/28/92)
*/
#include <config.h>
#include <mudlib.h>
#include <logs.h>
#include <uid.h>

inherit DAEMON;

int cmd_log(string path)
{
   seteuid(getuid(previous_object()));
   
   if( path ) {
      if( member_group(geteuid(this_player()), "admin") )
         path = LOG_DIR + path;
      else {
         if( member_array(path, WIZ_CAN_LOG_FILES) == -1 )
            return notify_fail("Sorry, you can read that log file!\n");
         seteuid(ROOT_UID);
         "/cmds/file/_cp"->cmd_cp(LOG_DIR+path+" "+WIZ_LOG_DIR+path);
         seteuid(getuid(previous_object()));
         path = WIZ_LOG_DIR + path;
      }
   } else {
      path = user_path(getuid(this_player()));
      path += "log";
   }
 
   if( !path ) path = LOG_DIR + "log";
 
   if( !file_exists(path) )
     return notify_fail("Log: " + path + " does not exist.\n");
     
   write( path+ ":\n" );
   if( !tail(path) )
     return notify_fail("Log: Could not read " + path + "\n");
   return 1;
}

int help()
{
   write("Command: log\nSyntax: log [log | lpmud.log | other]\n"+
      "If no parameter is passed then this command will show\n"+
      "you the end of the log file in your directory.  This is\n"+
      "where errors in your objects code will appear.  If you\n"+
      "pass a filename then it will look for and tail the file\n"+
      "by that name in the /log/wiz directory.  log.log and log\n"+
      "lpmud.log contain most of the errors there.\n");
   return 1;
}
