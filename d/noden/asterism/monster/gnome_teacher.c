#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "gnome magic teacher", "�ؾ�ħ����ʦ" );
	add("id",({"mage","gnome","teacher"}) );
   set_short( "�ؾ�ħ����ʦ" );
	set_long(
	        "һ������ħ������ʦ.\n"
           	);
	set( "gender", "female" );
	set( "race", "gnome" );
	set( "alignment", 160 );
	set( "time_to_heal", 7 );
	set_natural_armor( 20, 22 );
	set_natural_weapon( 15 , 13 , 18 );
	set_perm_stat( "kar", 23 );
	set_perm_stat( "int", 24 );
	set("max_sp",700);
	set("spell_points",700);
	set_skill("concentrate",100);
	set_skill("target",100);
	set_skill("black-magic",90);
	set_skill("dodge",75);
	set_skill("wand",80);
	set_skill("invoke",80) ;
	set("guild_levels/black-magic",50);
        set("guild_levels/guild",60);
	set("spells",(["flare":1]));
	set( "wealth/gold", 33 );
        set( "magic_delay",2) ;
	set( "special_defense", ([ "all": 32 ]) );
	wield_weapon(WEAPONS"wand02");
	equip_armor(ARMORS"gloves02");
	equip_armor(ARMORS"robe03");
	equip_armor(ARMORS"amulet_h01");
        set( "tactic_func", "cast_help" ); 
}

int cast_help()
{ 
    object victim ;
    string name;
    int i;
    victim = query_attacker();
       name=victim->query("name");    
    if( !victim ) return 0; 
    if ( (int)this_object()->query("spell_points")< 300 )
          this_object()->set("spell_points",600);
    if ( random(10)<4 ) {
//       command("say fulea on ");        
       command("cast flare at "+name); 
       return 1;
       }
    else return 0;
}
