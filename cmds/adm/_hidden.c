//#pragma save_binary
/* _hide.c
// brought you you by Buddha@TMI
// This isn't documented very well because only admins get to use it
// and it's kinda new.
// The security also isn't here because it's take care of elsewhere.
// So anyone can type 'hide' if this is in their path, and just get 'Ok.'
// Mobydick added help and stricter argument control, 11-25-92.
// Mobydick made it hide the connection object also, 2-6-92.
// 93-07-30 Grendel@tmi-2 Put in the check to tell you whether or not
//      		the attempt works.  Added report of whether or
//      		not you are hidden when called with no args.
*/

#include <mudlib.h>

inherit DAEMON ;

int help() ;

int cmd_hidden(string str) {

   int i;
   object connection ;

   if (!str||str=="") {
	if(hiddenp(previous_object()))
	    write("hidden: You are currently hidden.\n");
	else
	    write("hidden: You are not hidden.\n");
	return 1;
    }
   if(str!="off" && str!="on") return help() ;
   if (str=="on") {
	previous_object()->hide(1) ;
	connection = previous_object()->query("link") ;
	if (connection) connection->hide(1) ;
	if(hiddenp(previous_object()))
	    write ("hide: You are now hidden.\n") ;
	else
	    write ("hide: Attempt failed\n") ;
	return 1 ;
   }
   if(!hiddenp(previous_object()))
      write("hidden: You aren't hidden!  But anyway:\n");
   write ("hidden: You become unhidden again.\n") ;
   previous_object()->hide(0) ;
    connection = previous_object()->query("link") ;
   if (connection) connection->hide(0) ;
   return 1 ;
}

int help() {
	write ("Usage: hidden [on | off]\n\n"+@HELP
Without any arguments it reports whether or not you are currently
hidden.  With the arguments "on" or "off" the command sets your hidden
status. If you are hidden, then you will not appear in the users()
efun. This means you will not appear on people or finger, and says in
your environment will not reach you, and other similar effects.

See also: invis
HELP
		) ;
	return 1 ;
}
