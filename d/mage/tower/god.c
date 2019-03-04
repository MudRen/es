#include "echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "evil wight", "����֮��" );
        add("id",({"wight"}));
        set_short( "evil shadow", "����֮��" );
        set_long(
                "a terrible evil wight.\n"
                "һ�����˾��µĵ���֮��\n"
        );
        //set( "gender", "natural" );
        set( "alignment", 10000 );
        set( "race", "human" );
        set( "gender", "male" );
        set( "hit_points", 2500 );
        set( "max_hp", 2500 );
        set_perm_stat( "str", 35 );
        set_perm_stat( "dex", 30 );
        set_perm_stat( "int", 30 );
        set_perm_stat( "kar", 30 );
        set_skill( "dodge", 100 );
        set( "tactic_func", "my_tactic" );
        set_natural_weapon( 40, 50, 45 );
        set_natural_armor( 90, 90 );
        set( "unbleeding",1);
        set("aggressive",1);
        equip_armor( "d/noden/moyada/obj/magic_robe" );
        wield_weapon("/d/noden/nodania/obj/ivory_dagger.c");
}
int my_tactic()
{
        object victim;

        if( random(20)>4 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim,
          "����֮�񷢳����µ�Ц��,�������������ٶ����������ȡ���������.\n"
          );
      tell_room(environment(this_object()),
          "����֮�񷢳����µ�Ц��,�������������ٶ���"+victim->query("c_name")+"��ȥ.\n"
          ,({victim,this_object(),}) );
      victim->receive_special_damage("evil",10+random(17));
      report(this_object(),victim);
      return 1;
         }
}
