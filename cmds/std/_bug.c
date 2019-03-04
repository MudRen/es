 
/*
// File:        _praise.c
// Purpose:     A generic report command, inherited by _bug, _idea, etc
// History:
// 93-02-11     Written by Pallando based on Sulam's _bug.c
//              This file is part of the TMI Mudlib distribution.
//              Please include this header if you use this code.
// 93-07-13     Grendel added timestamping to make possible rlog.
// 93-07-20     Grendel added domain logging.
// 93-09-02     Checking for domain directory added.
//              NB Domains with directories different from their euids
//              will not have report logs.
*/
 
/****************** GENERIC CMD_REPORT *************************/
 
#include <config.h>
#include <mudlib.h>
 
#define TMP_FILE TMP_DIR + report_type + "_" + getoid( this_player() )
// Use getoid not geteuid to handle multiple logins of same character.
 
// DELIM must be the same as in the rlog and clog commands.
#define DELIM "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
 
inherit DAEMON;
 
string report_type, report_file;
 
int help();
 
// NB do _not_ put in a seteuid( geteuid( previous_object() ) )
// It needs to be able to write reports to files in other wizards dirs
int cmd_report( string a )
{
  if( a ) { help(); return 1; }
  write( "Begin writing your " + report_type + " report.\n" );
  this_player()-> edit( TMP_FILE, "callback", this_object() );
  return 1;
}
 
int callback()
{
  string text, report, author, domain;
  object where;
 
  text = read_file( TMP_FILE );
  rm( TMP_FILE );
  if( !text )
  {
    write( "Report not found ... aborting.\n" );
    return 1;
  }
  where = environment( this_player() );
  report = capitalize((string)this_player()->query("name")) + " at " +
    ctime(time()) + (where?(" in "+file_name(where)+"\n"):"\n") + text + "\n";
  log_file(report_file, DELIM + time() + "\n" + report);
  report = capitalize( report_type ) + " : " + report;
  if( where && ( domain = master()-> domain_file( file_name( where ) ) ) )
  {
    if( domain == "User" )
    {
      // Wizards generally don't want copies of reports they
      // make themselves in their own worroms.
      if( ( author = master()-> author_file( file_name( where ) ) ) &&
          ( author != geteuid( this_player() ) ) )
        write_file( user_path( author ) + "reports", report );
    } else {
      domain = "/d/" + domain;
      if( (int)get_dir( domain ) == -2)
        write_file( domain + "/reports", report );
    }
  }
  write("Thanks for the report.  It is now saved.\n" );
  return 1;
}
 
void abort() { catch( rm( TMP_FILE ) ); }
// Probably don't need the catch, but I am not certain that TMP_FILE
// will always exist on abortion or what rm does if you try to rm
// a non-existant file.  If someone knows, then change it.
 
int help()
{
 
    write(@TEXT
ָ���ʽ: bug

����������ָ���ᣬ������һ����Ϥ�ı༭��ʽ����������Դ��
�йش���ѶϢ���������ʱ�������ֺ�ʱ��ȵȵ�ѶϢ�����Զ��ĸ�
�������༭�ĵ����У����͸��ʵ�����ʦ��
 
TEXT
);
  return 1;
}
 
/* bug command */
 
int cmd_bug( string a ) { return cmd_report( a ); }
create() { ::create(); report_type = "bug"; report_file = "BUGS"; }
