//#pragma save_binary

#include <mudlib.h>

inherit DAEMON;

int cmd_ignore( string a )
{
  string * ignore;
  int i;

  ignore = this_player()-> query( "ignore" );
  if( !pointerp( ignore ) ) ignore = ({ });
  if( !a )
  {
    if( !sizeof( ignore ) ) write( "You are ignoring no-one.\n" );
    else write( wrap( "You are ignoring: " + implode( ignore, ", " ) ) );
    return 1;
  }
  if( -1 == member_array( a, ignore ) )
  {
    write( "You are now ignoring " + a + "\n" );
    ignore += ({ a });
  } else {
    write( "You are now no longer ignoring " + a + "\n" );
    ignore -= ({ a });
  }
  this_player()-> set( "ignore", ignore );
  return 1;
}

int
help() {
  write(@HELP
ָ���ʽ��ignore <�û���>

����ָ�����ʹ<�û�>�޷�����ʹ��tell����.

HELP
);
  return 1;
}