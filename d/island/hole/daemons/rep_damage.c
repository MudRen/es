#include <mudlib.h>

void report( object victim )
{
   string message;
   seteuid(getuid());
   message= "/adm/daemons/statsd"->c_status_string(victim);
   tell_object( victim,"( ��"+message+" )\n\n" );
   return ;
}
