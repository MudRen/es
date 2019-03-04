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
          query("c_cap_name")+"�����ȵ�����С�Ӻô󵨣������ڴ�����к������ˣ�ȥ���ɣ���\n",this_object() );
      else {
          tell_room( environment(),
	  query("c_cap_name")+"��ȣ�����С�ӣ�����������ǰɱ�ˣ�����������\n",
                       this_object() );
        if( !pointerp(attackers) || member_array(player, attackers)==-1 )
        kill_ob(player);
                }
    else if( !pointerp(will_attack) )
        will_attack = ({ player });
    else if( member_array(player, will_attack)==-1 )
        will_attack += ({ player });
}
