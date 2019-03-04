#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "halfling black mage", "�����˺�ħ��ʦ" );
	add("id",({"mage","halfling"}) );
   set_short( "�����˺�ħ��ʦ" );
	set_long(
   "�㿴������Ц�����������۾��İ����˺�ħ��ʦ,Ҳ��������˼��һЩ����.\n"
	);
	set( "gender", "female" );
	set( "race", "halfling" );
	set( "alignment", 160 );
	set( "time_to_heal", 7 );
	set_natural_armor( 60, 20 );
	set_natural_weapon( 15 , 13 , 18 );
	set_perm_stat( "kar", 23 );
	set_perm_stat( "int", 24 );
	set("max_sp",700);
	set("spell_points",700);
	set_skill("concentrate",80);
	set_skill("target",70);
	set_skill("black-magic",100);
	set_skill("dodge",98);
	set_skill("whip",80);
	set("guild_levels/balck-magic",60) ;
        set("guild_levels/guild",60);
	set("spells",(["flare":1]));
	set( "wealth/gold", 33 );
	set( "special_defense", ([ "all": 32 ,"none":16 ]) );
	wield_weapon(WEAPONS"long_whip");
	equip_armor(ARMORS"cloak_h01");
	equip_armor(ARMORS"amulet_h01");
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
       guard[i]->query("c_name")+"��: ������һ��ѵ��˸��߰�!\n",guard[i] );
        guard[i]->kill_ob(victim);
      }
    if ( (int)this_object()->query("spell_points")< 300 )
       this_object()->set("spell_points",600);
    if ( random(10)<4 ) {
       name=victim->query("name");
       command("cast flare on "+name); 
       return 1;
       }
    else return 0;
}

