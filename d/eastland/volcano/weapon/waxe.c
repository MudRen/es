#include "../oldcat.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("wraith axe","矮灵之斧");
       add("id",({"axe",}) );
       set_short("矮灵之斧");
       set_long(
           "矮灵族猎头者所用的斧头\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 31 );
        set("type","axe");
        set("bleeding",10);
	set( "min_damage", 22 );
	set( "max_damage", 35 );
	set( "weight", 190 );
	set( "value", ({ 250, "gold" }) );
//	set("hit_func","sword_damage");
        set("special_damage",15);
        set("special_c_msg","呼叫火之灵，一道火光，嘶的一声，击中敌人的要害\n");
}

int sword_damage(object victim,int damage)
{
    object holder;
    int my_kar,vic_kar,dam;
    string c_msg,msg;
    
    if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	my_kar = (int)holder->query_stat("kar");
	vic_kar =(int)victim->query_stat("kar");
	if( random(my_kar*3) < vic_kar*2 )
		return 0;
	if( !(dam = (int)query("special_damage")) ) return 0;
	else {
		c_msg = (string)query("special_c_msg");
		victim->receive_damage( dam );
		victim->set("last_attacker", holder );
		tell_object( holder, 
			"\n你的"+query("c_name")+c_msg+"\n");
		tell_room( environment(holder), 
			holder->query("c_name") + "的"+query("c_name")+c_msg+"\n",
			holder );
		return dam;
     }
	
}	
