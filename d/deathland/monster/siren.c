#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
    object ob1;
	::create();
	set_level(18);
	set_name( "siren", "赛伦" );
	set_short( "赛伦" );
	set_long(
		"你见到一个美丽的女人,而且她的歌声是如此的优美以至於让你陶醉其中,无法自拔。\n"
	);
	set( "gender", "female" );
	set( "alignment", -1600 );
	set_perm_stat( "dex", 24 );
	set_perm_stat( "int", 25 );
	set_perm_stat( "kar", 21 );
	set_skill( "dodge", 100 );
	set_skill( "shortblade",100);
	
	set( "hit_points" , 500);
	set( "max_hp" , 500);
	set( "tactic_func", "my_tactic" );
	set_natural_armor(79,35);
	set( "special_defense",(["all":15,"none":30]) );
	set( "aim_difficulty", ([ "vascular":20,"weakest":20]) );
	set_natural_weapon(28,17,24);
    set( "killer" , 1 );
    wield_weapon(Weapon"/shortsword04");
    equip_armor(Armour"/ring03");
    equip_armor(Armour"/amulet04");
    ob1 = new( Object"/key02" );
  	ob1->move( this_object());
}

int my_tactic()
{
	object victim;
    object *all_vic;
	int i;
	
	if( random(20)>6 || !(victim= query_attacker()) )  return 0;
	if ( random(10)>5 ) {
	  if( victim->query("stop_attack") ) {
	     tell_object( victim, 
		 "赛伦用她的眼神注视著你.\n");
	     tell_room( environment(this_object()), 
                 "赛伦又用她的眼神注视著"+ victim->query("c_name") +".\n"
		 ,({ victim, this_object() }) );
	     victim->receive_special_damage( "mental" , 35+random(15) );
	     report( this_object() , victim );
	     }
	  else {  
	     tell_object( victim, 
		   "赛伦用她的眼神注视著你，把你给迷惑住了.\n");
	     tell_room( environment(this_object()), 
                   "赛伦用她的眼神注视著"+ victim->query("c_name") +"，把"+ victim->query("c_name") +"给迷惑住了.\n"
		   ,({ victim, this_object() }) );
	     victim->block_attack(6);
	     victim->set_temp("msg_stop_attack", 
		 "( 你现在意乱情迷，无法攻击！ )\n" );
	     }
	    return 1;
      }
    else if ( random(10)< 6 ) {
      all_vic=query_attackers();
      all_vic->receive_special_damage("mental",50 );
      tell_room(environment(),
                "赛伦正唱著歌来偷取你的生命力.\n"
                ,this_object() );
      for(i=0;i<sizeof(all_vic);i++) 
        report(this_object(),all_vic[i]);
      
      return 1; 
      }
    else 
      return 0;  
}
