#include "../almuhara.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "Sword Saint", "剑圣" );
	add( "id", ({ "saint", "guard" }) );
	set_short( "剑圣" );
	set_long(
		"你看到一位神情冷漠的年轻人坐在这儿。虽然他对於你的到来丝毫没有反应，但\n"
		"是你想总比另外两个人好沟通。你不妨问他有关这儿(here)的事。\n"
			);
	set( "gender", "male" );
	set( "race", "daemon" );
	set( "alignment", 1000 );
	set( "hit_points", 1200 );
	set( "max_hp", 1200 );
	set_natural_armor( 110, 45 );
	set_natural_weapon( 50, 30, 40 );
	set_perm_stat( "str", 23 );
	set_perm_stat( "dex", 29 );
	set_perm_stat( "int", 29 );
	set_perm_stat( "pie", 23 );
	set_perm_stat( "con", 20 );
	set_perm_stat( "kar", 25 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "dodge", 100 );
	set_skill( "tactic", 100 );
	set("alt_corpse","NONE");
	set( "tactic", "melee" );
	set( "force_effect", 8 );
	set( "force_type", "cold" );
	set( "wealth/gold", 200 );
	set( "special_defense", ([ "all": 50,"none":60 ]) );
        set( "aim_difficulty", ([ "vascular":20 ]) );
        set( "tactic_func", "my_tactic");
        set( "inquiry", ([
"here" : 
	    "这儿是我的练剑室，我想你是要问剑冢(sword_tomb)吧....\n" ,
"sword_tomb" : 
	          "剑冢是皇帝下令兴建的。因为皇帝喜爱收集各种剑，又想要这些剑永远\n"
	          "陪伴他，於是下令兴建剑冢。\n" ,
"stone" : 
	     "那石墩是一个由大国师  孝光所施的封印(seal)。由於冢内的一把邪剑在吸取\n"
	     "了此处的灵气，竟幻化成一之异常邪恶的奇兽。国师当时无力将其除去，只有把它封在封\n"
	     "印中，等待後人能除此异兽。\n" ,
"seal" : 
	     "我也不是很清楚，你可以试著问问那两个小童。\n" ,
	     ]) );     
	wield_weapon( WEAPONS"/antique_sword" );
}

int my_tactic()
{
  object victim;
  
  if ( !(victim=query_attacker()) || (random(10)>3)) return 0;
  tell_object(victim,
       "\n剑圣对你大喊 : 看「剑二十一」 !!\n");
	tell_room(environment(this_object()),
		sprintf("剑圣对%s大喊 : 看「剑二十一」 !!\n\n",
			victim->query("c_cap_name")),({ this_object(),victim }) );
  victim->receive_damage( 25 + random(15));
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
	if( !weapons || !sizeof(weapons) ) return;
	tell_object( obj,"剑圣手上之剑突然响起一声轻吟，似乎要和你的武器一较长短。\n" );
	this_object()->kill_ob(obj);
	return;
	}
}

void die()
{
	tell_room( environment(this_object()), 
		"剑圣仰天大笑 : 我终於败了 !! 我终於败了 !!\n长笑声中，剑圣的身体化成飞灰，纷飞四散。\n\n" ,
		this_object() );
	::die(1);
}
