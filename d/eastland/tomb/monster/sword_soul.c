#include "../almuhara.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "Sword Soul", "剑魂" );
	add( "id", ({ "soul", "guard" }) );
	set_short( "剑魂" );
	set_long(
		"你看到一位冷酷的年轻人坐在这儿。他的双目微闭，对於你的到来丝\n"
		"毫没有反应。\n"
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 1000 );
	set( "hit_points", 1200 );
	set( "max_hp", 1200 );
	set_natural_armor( 105, 40 );
	set_natural_weapon( 45, 25, 35 );
	set_perm_stat( "str", 22 );
	set_perm_stat( "dex", 28 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "pie", 20 );
	set_perm_stat( "con", 20 );
	set_perm_stat( "kar", 25 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "dodge", 100 );
	set_skill( "tactic", 100 );
	set("alt_corpse","NONE");
	set( "tactic", "berserk" );
	set( "force_effect", 8 );
	set( "force_type", "cold" );
	set( "wealth/gold", 200 );
	set( "special_defense", ([ "all": 50,"none":60 ]) );
        set( "aim_difficulty", ([ "vascular":20 ]) );
        set( "tactic_func", "my_tactic");
   
	wield_weapon( WEAPONS"/famous_sword" );
}

int my_tactic()
{
  object victim;
  int dam;
  
  if ( !(victim=query_attacker()) || (random(10)>3)) return 0;
  tell_object(victim,
       "\n剑魂手上之剑化成一道七色彩虹分刺你周身大穴 !!\n");
	tell_room(environment(this_object()),
		sprintf("剑魂手上之剑化成一道七色彩虹向%s周身大穴刺去 !\n\n",
			victim->query("c_cap_name")),({ this_object(),victim }) );
  dam = 25 + random(15);
  victim->receive_damage(dam);
  return 1;
}

int is_a_weapon(object item)
{
 	return ((int)item->query("wielded")) ;
}

void relay_message(string class1,string msg)
{
     string who,str,tmp;
     object *weapons,obj;
     
     if( sscanf( msg, "%s(%s)走了过来。\n", tmp,who )==2 ) 
        {
         obj = find_player(lower_case(who));
         if(!obj) return ;
	weapons = filter_array( all_inventory( obj ), "is_a_weapon", this_object() );
	if( !sizeof(weapons) || !weapons ) return;
	tell_object( obj,
		"剑魂手上之剑突然响起一声轻吟，似乎要和你的武器一较长短。\n");
	this_object()->kill_ob(obj);
	return;
	}
}

void die()
{
	tell_room( environment(this_object()), 
		"\n"+"剑魂的□首迅速地化成了灰烬。\n"+"\n" ,
		this_object() );
	::die(1);	
}
