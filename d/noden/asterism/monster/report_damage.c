// default function for spells. Create by Kyoko.

// It is good for tactic funtion of monsters.

#include <mudlib.h>

void report_damage( object attacker, object victim )
{
   string message, c_message;
   seteuid(getuid());
   message= "/adm/daemons/statsd"->status_string(victim);
   c_message= "/adm/daemons/statsd"->c_status_string(victim);
  // tell_object( attacker, !can_read_chinese() ?
  //   "( " + victim->query("name") + message+" )\n" 
  //   :
  //   "( " + victim->query("c_name") + c_message+" )\n"  
  //     );
   tell_object( victim,!can_read_chinese(victim) ? 
     "( you "+message+" )\n" : "( ��"+c_message+" )\n"
     
     );
}
