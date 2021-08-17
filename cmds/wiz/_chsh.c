//#pragma save_binary

//	File	:  cmds/xtra/_chsh.c
//	Creator	:  Watcher @ TMI
//
//	Command used to set user shell from choices found in
//	reserved SHELL directory.

#include <mudlib.h>

inherit DAEMON ;

#define SHELL_LIST	"/adm/etc/shells"
#define NAME		capitalize((string)this_player()->query("name"))

#define SYNTAX	"Syntax: chsh [shell | ?]\n"

protected string get_shell();
protected int input_shell(string str);
protected int list_shells();
protected int load_shells();

string *SHELLS;

int cmd_chsh(string str) {

   if(!SHELLS)	load_shells();

   if(str == "?")  return list_shells();

   if(str && str != "")  return input_shell(str);

   write("Changing login shell for " + NAME + ".\nShell [" +
	 get_shell() + "]: ");
   input_to("input_shell");

return 1; }

protected int input_shell(string str) {
   object shell;
   string old_shell;
   int loop;

   if(!str || str == "") {
   write("Login shell unchanged.\n");
   return 1; }

   old_shell = (string) this_player()->query("shell");

   if(str == "none")  str = 0;
   else if(member_array(str, SHELLS) == -1) {
   write("Invalid shell selection, shell unchanged.\n");
   write(list_shells());
   return 1; }

   if((string)this_player()->query("shell") == str) {
   write("Login shell unchanged.\n");
   return 1; }

   this_player()->set("shell", str);
   if(!str)  write("Login shell removed.\n");
   else write("Login shell changed.\n");

   shell = present("shell", this_player());
   if(shell && (base_name(shell) + ".c") == old_shell)  shell->remove();

   if(str && catch(clone_object(str)->move(this_player())))
   write("Chsh:  Error in shell creation.\n");

return 1; }

protected string get_shell() {
   string tmp;

   tmp = (string)this_player()->query("shell");
   if(!tmp || tmp == "")  tmp = "none";

return tmp;  }

protected int load_shells() {
   string list;
   int loop;

   list = read_file(SHELL_LIST);
   if(!list)  return 0;

   SHELLS = explode(list, "\n");

   for(loop=sizeof(SHELLS)-1; loop>-1; loop--)
   if(SHELLS[loop][0] == '#' || SHELLS[loop] == "")
	SHELLS = exclude_array(SHELLS, loop);

return 1; }

protected int list_shells() {
   int loop;

   write("Available shell environments:\t");

   for(loop=0; loop<sizeof(SHELLS); loop++) {
        if(loop)  write("\t\t\t\t");
        write(SHELLS[loop] + "\n");
   }

   write("\t\t\t\tnone\n\n");

return 1; }

int help() {

   write( SYNTAX + "\n" +
     "This command allows a user to change their shell working environment.\n"+
     "The choices may be found in " + SHELL_LIST + ", and can be listed \n" +
     "with \"?\" as a shell argument.\n");

return 1; }
