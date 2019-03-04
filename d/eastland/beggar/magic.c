#include <mudlib.h>

void report( object attacker, object victim )
{
   string message, c_message;
   seteuid(getuid());
   message= "/adm/daemons/statsd"->status_string(victim);
   c_message= "/adm/daemons/statsd"->c_status_string(victim);
  // tell_object( attacker, !can_read_chinese(attacker) ?
  //   "( " + victim->query("name") + message+" )\n" 
  //   :
  //   "( " + victim->query("c_name") + c_message+" )\n"  
  //     );
   tell_object( victim,!can_read_chinese(victim) ? 
     "( you "+message+" )\n" : "( �� "+c_message+" )\n"
     
     );
}
void hurt_all( object obj )
{
   int i;
   object *env;
   
   env=all_inventory(environment(obj));
   for (i=0;i<sizeof(env);i++)
     if ( living(env[i])&&(!env[i]->query_attacker())&&
          (!env[i]->query("no_attack")) ){
        obj->kill_ob(env[i]);
        env[i]->kill_ob(obj);
   }
}
void delete_embattle_effect( object obj )
{
   object *env;
   int i;
   env=all_inventory(environment(obj));
   for (i=0;i<sizeof(env);i++)
      if( env[i]->query("couple") ){
        env[i]->delete_temp("embattle_busy");
        env[i]->delete_temp("embattle_ac");
        env[i]->delete_temp("embattle_busy_check");
        env[i]->delete_temp("embattle_db");
        env[i]->delete_temp("embattle_party");
        env[i]->delete_temp("embattle_victim");
        env[i]->delete_temp("embattle_wc");
        env[i]->delete_temp("extra_ac");
        env[i]->delete_temp("extra_db");
        env[i]->delete_temp("extra_wc");
      }
}