#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "dwarf soldier", "����ʿ��" );
	add("id",({"soldier"}) );
   set_short( "����ʿ��" );
	set_long(
		"һ������İ���ʿ��.\n"
	);
	set( "gender", "male" );
	set( "race", "dwarf" );
	set( "alignment", 450 );
	set( "time_to_heal", 7 );
	set_natural_armor( 56, 12 );
	set_natural_weapon( 17 , 9 , 15 );
	set("max_hp",550);
	set("hit_points",550);
	set_perm_stat( "str", 20 );
	set_skill( "parry",80 );
	set( "wealth/gold", 3 );
	set( "special_defense", ([ "all": 12 ]) );
	wield_weapon(WEAPONS"blunt02");
	equip_armor(ARMORS"ringmail03");	
	equip_armor(ARMORS"leggings02");
	set("echo_asterism",1);
	set("astr_soldier",1);	
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
    if( (((int)this_object()->query("hit_points"))<150) && random(5)<2 )
      { 
       command("say heal me please\n") ;
      }           
    victim = query_attacker();
    if( !victim ) return 0;
    guard = filter_array( all_inventory(environment(this_object())),
            "is_a_guard", this_object() );
    for( i=0; i<sizeof(guard); i++ )
      {
       tell_room( environment(this_object()),
       guard[i]->query("c_name")+"��: ͬ����.������һ��ѵ��˸��߰�!\n", guard[i]
              );
       guard[i]->kill_ob(victim);
      }
    return 0;
}

