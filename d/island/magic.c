#include <mudlib.h>

void report( object victim )
{
   string message ;
   seteuid(getuid());
   message= "/adm/daemons/statsd"->status_string(victim);
 //  c_message= "/adm/daemons/statsd"->c_status_string(victim);
   tell_object( victim," ( ��"+message+" )\n" );
   
}
