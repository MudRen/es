#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "dwarf red mage", "���˺�ħ��ʦ" );
	add("id",({"mage","dwarf"}) );
   set_short( "���˺�ħ��ʦ" );
	set_long(
	"�㿴��һ�����˺�ħ��ʦ,�������о�һЩ�µ�ħ��.\n"
	);
	set( "gender", "male" );
	set( "race", "dwarf" );
	set( "alignment", 700 );
	set( "time_to_heal", 7 );
	set_natural_armor( 66, 30 );
	set_natural_weapon( 19 , 11 , 15 );
	set_perm_stat( "kar", 23 );
	set_perm_stat( "int", 25 );
	set("max_sp",600);
	set("spell_points",600);
	set_skill("concentrate",100);
	set_skill("target",100);
	set_skill("black-magic",100);
	set_skill("dodge",95);
	set_skill("dagger",80);
        set("guild_levels/elemental",80) ;
        set("guild_levels/guild",60) ;
	set("spells",(["sleet":4]));
	set( "wealth/gold", 33 );
	set( "special_defense", ([ "all": 35 ]) );
	wield_weapon(WEAPONS"dwarven_dagger");
	equip_armor(ARMORS"cloak_d01");
	equip_armor(ARMORS"amulet_h02");
	set("echo_asterism",1);
    set( "tactic_func", "cast_help" ); 
}
int is_a_guard( object ob )
{
    if( ob->query_attackers() ) return 0;
    if( ob->query("echo_asterism") ) return 1;
    return 0;
}

int cast_help()
{ 
    object victim, *guard;
    string name;
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
    if ( (int)this_object()->query("spell_points")< 300 )
       this_object()->set("spell_points",600);
    if ( random(10)<7 ) {
       name=victim->query("name");
       command("cast sleet on "+name); 
       return 1;
       }
    else return 0;
}

