#include "../moyada.h"

void to_climb_up( object player, string dest, int need )
{
    int skill;
    skill = player->query_skill("climbing");
    skill += 5;
    if( random(need) < skill ) {
      tell_object( player,"��С�������������ȥ��\n");
      tell_room( environment(player), 
        player->query("c_name")+"������ȥ��\n", player
      );
      player->move_player( dest, "SNEAK" );
      tell_room( environment(player),
        player->query("c_name")+"����������\n" , player
      );
    } else {
      tell_object( player,
        "�㳢��������ȥ������ֻ���������\n");
      tell_room( environment(player), 
        player->query("c_name")+"����������ȥ������ֻ���������\n" , player
      );
    }
}

void to_climb_down( object player, string dest1, string dest2, int need, int damage )
{
    int skill;
    skill = player->query_skill("climbing");
    if( skill > need && (random(100) < skill) ) {
      tell_object( player,"��С�������������ȥ��\n" );
      tell_room( environment(player),
        player->query("c_name")+"������ȥ��\n", player
      );
      player->move_player( dest1, "SNEAK" );
      tell_room( environment(player), 
        player->query("c_cap_name")+"����������\n", player
      );
    } else {
      tell_object( player,"�㳢��������ȥ�����һ��С�ĵ�����ȥ����! ��ʹ!\n" 
      );
      tell_room( environment(player),
        player->query("c_name")+"����������ȥ�����������ȥ��\n", player
      );
      player->move_player( dest2, "SNEAK" );
      player->receive_damage(damage);
      "/d/magic/magic"->report( this_object(), player );
      tell_room( environment(player),
        player->query("c_name")+"����������\n", player
      );
    }
}
