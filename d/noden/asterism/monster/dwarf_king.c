#include "../asterism.h"

inherit "/d/noden/asterism/monster/report_damage";
inherit MONSTER;

void create()
{
	::create();
	set_level(13);
	set_name( "dwarf king Alaits IV", "������������˹����" );
	add("id",({"king","dwarf","alaits"}) );
   set_short( "������������˹����" );
	set_long(
		"һ����������,��������Ŀǰ���˵���,������˹����.\n"
	);
	set( "gender", "male" );
	set( "race", "dwarf" );
	set( "alignment", 500 );
	set( "time_to_heal", 6 );
	set_natural_armor( 66, 35 );
	set_natural_weapon( 25 , 14 , 23 );
	set("max_hp",400);
	set("hit_points",400);
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "kar", 30 );
	set_skill( "parry",100 );
	set_skill( "longblade",100 );
	set( "wealth/gold", 30 );
	set( "special_defense", ([ "all": 28 ,"none":10 ]) );
	set( "aim_difficulty",(["critical":25,"weakest":40
	                         ,"vascular":45,"gonglion":45 ]) );
	wield_weapon(WEAPONS"blacksword");
        equip_armor(ARMORS"shield01");        
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
    object victim, *guard,*victims;
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

