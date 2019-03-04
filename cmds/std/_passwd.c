//#pragma save_binary

// This is part of the TMI distribution mudlib.
// Please retain this header if you use this file.
// Written by Sulam (12-9-91)
// Help added by Brian (1/28/92)
// A security loop-hole found by Ellery and fixed by Pallando. (93/01/14)
// "Multithreading" added by Buddha (4/20/93)
// 93-08-15 Grendel@tmi-2 fixed to allow admins to change non-admins passwds
// 94-06-27 Kyoko@EasternStory added prepassword for admins.

#include <mudlib.h>
#include <daemons.h>

#define log( x ) log_file( "CHEAT", iwrap( "passwd " + ctime(time()) + " "+\
  identify( ({ this_object(), previous_object(), this_player(), x }) ) ) )
#define HACK log(0); notify_fail( "Sorry.  Password security problem.\n" );\
  return 0

inherit DAEMON;

#define SYNTAX "usage: passwd [<player>]\n"

nomask int cmd_passwd(string arg)
{
  string name;
  object link, ob;

  if( !this_player()
      || !userp( this_player() )
//      || this_player() != this_player( 1 )
      || this_player() != previous_object() 
	)
      { HACK; }

  name = geteuid(previous_object());
  if(arg && arg != "") {
      if(!user_exists(arg))
	    return notify_fail("passwd: no such user\n");
      if(!member_group(name, "admin") || member_group(arg, "admin"))
  	    return  notify_fail("passwd: parmission denied\n");
      name = arg;
      ob = find_player(arg);
      if(ob)
	    link = (object)ob->query_link();
      else
	    link = (object)FINGER_D->restore_data(name);
      write("Changing password for "+name+" on " + mud_name() + "\n");
      write("New password:");
      input_to("newpass", 1, link);
  } else {
      link = (object)previous_object()->query_link();
      write("Old password:");
      input_to("oldpass", 1, link);
  }
  return 1;
}

static nomask int oldpass(string pass, object link) 
{
  string password;

  write("\n");
  if (!pass) {
      write ("The null string is not an acceptable password.\n") ;
      return 0 ;
  }
  password = (string)link->query("password") ;
  if( password != crypt(pass, password) ) {
      write ("Password incorrect.\n") ;
      return 0 ;
  }
  write("New password:");
  input_to("newpass", 1, link);
  return 1;
}

static nomask int newpass(string pass, object link)
{
  write("\n");
  if( !pass || strlen(pass)<5 ) {
      write("Your new password must have more than 5 characters.\n");
      link->clean_up();
      return 0;
  }
  write("Again:");
  input_to("npass2", 1, pass, link);
  return 1;
}

static nomask int npass2(string pass, string tmp, object link)
{
  write ("\n") ;
  if (pass != tmp) {
      write("The passwords must match.\n");
      link->clean_up();
      return 0;
  }
  if (this_player(1) != this_player()) { HACK; } 

  pass = crypt(pass, 0);
  link->set("password", pass);
  link->save_data();
  link->clean_up();
  write ("passwd: password has been changed\n") ;
  return 1;
}

int help()
{
  write(SYNTAX +"\n"+ @HELP

���ָ�����ʹ�����������Լ�������.

HELP
			  );
  return 1;
}

/* EOF */
