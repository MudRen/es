#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(16);
	set_name( "dwarf royal body guard", "���˻��ұ���" );
	add("id",({"bodyguard","guard","dwarf"}) );
   set_short( "���˻��ұ���" );
	set_long(
		"һ������İ��˻��ұ���,�����𱣻����˹����İ�ȫ.\n"
	);
	set( "gender", "male" );
	set( "race", "dwarf" );
	set( "alignment", 800 );
	set( "time_to_heal", 7 );
	set_natural_armor( 46, 6 );
	set_natural_weapon( 25 , 18 , 24 );
	set("max_hp",550);
	set("hit_points",550);
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex", 22 );
	set_skill( "parry",70 );
	set( "wealth/gold", 15 );
	set( "special_defense", ([ "all": 22 ]) );
	set( "aim_difficulty",(["critical":10,"vascular":10]) );
	wield_weapon(WEAPONS"longsword05");
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

