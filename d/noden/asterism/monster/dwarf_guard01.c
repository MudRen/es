#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "dwarf guard", "��������" );
	add("id",({"guard","dwarf"}) );
   set_short( "��������" );
	set_long(
		"һ������İ�������.\n"
	);
	set( "gender", "male" );
	set( "race", "dwarf" );
	set( "alignment", 400 );
	set( "time_to_heal", 7 );
	set_natural_armor( 36, 0 );
	set_natural_weapon( 15 , 13 , 18 );
	set("max_hp",500);
	set("hit_points",500);
	set_perm_stat( "str", 23 );
	set_skill( "parry",50 );
	set( "wealth/gold", 10 );
	set( "special_defense", ([ "all": 22 ]) );
	set( "aim_difficulty",(["critical":10,"vascular":10]) );
	wield_weapon(WEAPONS"blunt01");
	equip_armor(ARMORS"ringmail03");
	equip_armor(ARMORS"gloves01");
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
      guard[i]->query("c_name")+"��: ������һ��ѵ��˸��߰�!\n", guard[i]
      );
      guard[i]->kill_ob(victim);
    }
     return 0;
}

