//#pragma save_binary
 
//	File	:  /cmds/xtra/_shell.c
//	Creator	:  Watcher@TMI  (02/11/93)
//
//	This command replaces a user's preselected shell if
//	it is missing.
 
#include <mudlib.h>
 
inherit DAEMON;
 
int cmd_shell() {
   object check, new;
   string shell;
 
   //	Get user's set shell system, if any.
 
   shell = (string)this_player()->query("shell");
  
   if(!shell || shell == "" || shell == "none") {
   write("You have no shell system selected. Use chsh to select one.\n");
   return 1; }
 
   //	Check to see if user has a "shell" of some form.
 
   check = present("shell", this_player());

   //	Check to see if they already have that shell system.
 
   if(check && base_name(check) + ".c" == shell) {
   write("You already have the shell system active.\n");
   return 1; }
 
   //	Try to clone and move shell system to player
 
   if(!(new = clone_object(shell)) || new->move(this_player())) {
   write("Shell: Could not restore your selected shell system.\n");
   if(new)  new->remove();		//  cleanup stray shells
   return 1; }
 
   this_player()->save_data();
 
   write("Shell system restored.\n");
 
return 1; }
 
int help() {

   write("Syntax: shell\n\n" +
     "This command is used to restore your shell system if you accidently\n" +
     "lose it in a crash or similar occurance.\n\nSee also: chsh\n");
 
return 1; }
 
