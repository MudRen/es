#include <mudlib.h>

void report( object attacker, object victim )
{
   string c_message;
   seteuid(getuid());
   c_message= "/adm/daemons/statsd"->c_status_string(victim);

   tell_object( victim, sprintf("( Äã %s )\n",c_message));
}
