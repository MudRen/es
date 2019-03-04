//#pragma save_binary
#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;
inherit REF_D;

#define SYNTAX "Syntax: eref [<ref_name>;]<object>\n"

int cmd_eref( string a )
{
  mixed ob;
  object env;
  string ref_name;

  if( !a ) { notify_fail( SYNTAX ); return 0; } 
  seteuid( geteuid( previous_object() ) );

  if( sscanf( a, "%s;%s", ref_name, ob ) < 2 )
  {
    ref_name = "default";
    ob = a;
  }
  ob = ref_ob( ob ); 
  if( !objectp( ob ) )
  {
    notify_fail( wrap( "Could not identify " + identify( ob ) +
      " as an object." ) );
    return 0;
  }
  env = environment( ob );
  if( !env )
  {
    notify_fail( wrap( identify( ob ) + " has no environment." ) );
    return 0;
  }
  set_ref( ref_name, env );
  write( wrap( "Reference \"" + ref_name + "\" set to " + identify( env ) ) );
  return 1;
}

int help()
{
  write( SYNTAX +
    "Effect: sets reference <ref_name> to the environment of <object>\n"+
  "" );
  return 1;
}
