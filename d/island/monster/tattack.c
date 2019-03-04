#include <mudlib.h>
#define WANTED "/d/island/daemons/tattack_d"

inherit MONSTER;

void create()
{
    ::create();
    WANTED->add_member();
}

void remove()
{
    WANTED->remove_member();
    return ::remove();
}

int stop_attack()
{
    WANTED->add_huntee(this_player());
    return 0;
}

void pseudo_hunt(object me, object player)
{
   if( environment() && present(player, environment()) )
      if( this_object()==me )
          tell_room( environment(),
          query("c_name")+"喝道：『大家一起赶走这欺负乌龟的坏蛋吧！！』\n",this_object() );
      else {
          tell_room( environment(),
	  query("c_name")+"大喝：『今天要你知道乌龟不是好欺负的！』\n",
                       this_object() );
        if( !pointerp(attackers) || member_array(player, attackers)==-1 )
        kill_ob(player);
                }
    else if( !pointerp(will_attack) )
        will_attack = ({ player });
    else if( member_array(player, will_attack)==-1 )
        will_attack += ({ player });
}
