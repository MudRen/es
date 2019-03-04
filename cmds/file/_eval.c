//#pragma save_binary
/*
// File:       _eval.c
// Purpose:    Evaluates a string as LPC commands
// Credits:
// 92-12-07    Pallando (aka Douglas Reay) created this command.
//             This file is a part of the TMI distribution mudlib.
//             Please retain this header if you use this code.
// 92-12-08    Pallando changed it not to use /tmp on idea from Watcher
// 92-12-12    Pallando changed it to use the identify() simul_efun
// 93-04-15    Pallando added final desting of object on idea from Robocoder
// 93-05-28    Artagel added strict typing
// 93-06-24    Pallando changed it to use /open on idea from Mobydick
// 93-07-16    Robocoder added some evil admin logging
*/

#include <uid.h>
#include <logs.h>
#include <config.h>
#include <mudlib.h>

inherit DAEMON;

#define SYNTAX "Syntax: \"eval <lpc commands>\".\n"

// If your mud allows objects in /tmp to load, use that, otherwise use /open
// If you have no loadable public directories, undefine TMP_FILE
// #define TMP_FILE temp_file( "eval", this_player() ) + ".c"
#define TMP_FILE OPEN_DIR + "eval." + geteuid( this_player() ) + ".c"

// Comment out the next line if you want failed evals to be deleted.
#define KEEP_FAILED_EVALS

int cmd_eval( string a )
{
  string file, filename;
  mixed err, ret;

  if( !a ) { notify_fail( SYNTAX ); return 0; }

  // The includes in the file arn't necessary (though inheriting OBJECT
  // allows remove() to work).  You should change them as necessary for
  // your own mud.  They do allow shorter eval commands though.  Eg:
  //     eval return children( USER )
  file = @EndText
#include <uid.h>
#include <config.h>
#include <daemons.h>
#include <net/daemons.h>
#include <commands.h>
#include <mudlib.h>
inherit OBJECT;
void create() { seteuid( getuid() ); }
mixed eval()
{
EndText
  + a + ";\n}\n";

#ifdef EVAL_CALL_LOG
    seteuid(ROOT_UID);
  if (!member_group(geteuid(this_player()), "admin"))
    log_file(EVAL_CALL_LOG, "************\n" + extract(ctime(time()), 4, 15) +
      " [" + geteuid(this_player()) + "] eval'd: " + a + "\n");
#endif

#if 0
  seteuid( getuid( previous_object() ) );
#else
  seteuid( geteuid( previous_object() ) );
#endif

  // Use a wizard's directory if it exists, a public directory if not.
  filename = user_path( geteuid( this_player() ) );
  if( file_size( filename ) == -2 )
  {
    filename += "CMD_EVAL_TMP_FILE.c";
  } else {
#ifdef TMP_FILE
    filename = TMP_FILE;
#else
    notify_fail( "You need a home directory to use the eval command.\n" );
    return 0;
#endif
  }

  // If anything has been left from a previous eval, remove it
  rm( filename );
  if( ret = find_object( filename ) ) ret-> remove();

  write_file( filename, file );

  if( err = catch( ret = (mixed)call_other( filename, "eval" ) ) )
  {
    write( "Error = " + err );
#ifdef KEEP_FAILED_EVALS
    write( "The file is in " + filename + "\n" );
#else
    rm( filename );
#endif
  } else {
    // If you don't have the identify() simul_efun, use dump_variable()
    write( wrap( "Result = " + identify( ret ) ) );
    rm( filename );
    if( ret = find_object( filename ) ) ret-> remove();
  }
  return 1;
}

int help()
{
  write( SYNTAX + @Endtext
Effect: calls a function containing <lpc commands>
Example: if you type:
    eval return function_exists("set",this_player())
this creates a temporary file in your home dir containing the line:
    eval() { return function_exists( "set", this_player() ); }
and then does call_other on the files's eval() and displays the returned value
Endtext
  );
  return 1;
}
