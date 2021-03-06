#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(16);
	set_name( "dwarf sentry", "观察站哨兵" );
	add("id",({"guard","sentry","dwarf"}) );
   set_short( "观察站哨兵" );
	set_long(
		"一个矮人哨兵,他正固守著他的岗位,严肃的他正面无表情地监视著\n"
		"山路上来往的人群。\n" );
	set( "gender", "male" );
	set( "race", "dwarf" );
	set( "alignment", 400 );
	set( "time_to_heal", 8 );
	set_natural_armor( 40, 8 );
	set_natural_weapon( 24 , 12 , 15 );
	set("max_hp",350);
	set("hit_points",350);
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 20 );
	set_skill( "parry",40 );
	set_skill( "longblade",80 );
	set( "wealth/gold", 20 );
	set( "special_defense", ([ "all": 22 ]) );
	set( "aim_difficulty",(["critical":10,"vascular":10]) );
	wield_weapon(WEAPONS"longsword03");
	equip_armor(ARMORS"ringmail03");
	equip_armor(ARMORS"gloves03");
	set("echo_asterism",1);
        set( "tactic_func", "cast_help" ); 
}

int is_a_guard( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("echo_asterism") ) return 1;
    return 0;
}

int cast_help()
{ 
    object victim, *guard;
    int i;
    victim = query_attacker();
    if( !victim ) return 0;
    guard = filter_array( all_inventory(environment(this_object())),
            "is_a_guard", this_object() );
    for( i=0; i<sizeof(guard); i++ ) {
      tell_room( environment(this_object()), 
      guard[i]->query("c_name")+"大喊: 让我们一起把敌人赶走吧!\n", guard[i]
      );
      guard[i]->kill_ob(victim);
    }
     return 0;
}

