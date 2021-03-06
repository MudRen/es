#include <mudlib.h>
#define WANTED "/d/island/hole/daemons/enemy_d"

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
          query("c_cap_name")+"大声喝道：『小子好大胆，竟敢在此任意残害我族人，去死吧！』\n",this_object() );
      else {
          tell_room( environment(),
	  query("c_cap_name")+"大喝：『好小子，竟敢在我面前杀人！纳命来！』\n",
                       this_object() );
        if( !pointerp(attackers) || member_array(player, attackers)==-1 )
        kill_ob(player);
                }
    else if( !pointerp(will_attack) )
        will_attack = ({ player });
    else if( member_array(player, will_attack)==-1 )
        will_attack += ({ player });
}
