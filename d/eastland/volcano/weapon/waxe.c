#include "../oldcat.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("wraith axe","����֮��");
       add("id",({"axe",}) );
       set_short("����֮��");
       set_long(
           "��������ͷ�����õĸ�ͷ\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class", 31 );
        set("type","axe");
        set("bleeding",10);
	set( "min_damage", 22 );
	set( "max_damage", 35 );
	set( "weight", 190 );
	set( "value", ({ 250, "gold" }) );
//	set("hit_func","sword_damage");
        set("special_damage",15);
        set("special_c_msg","���л�֮�飬һ����⣬˻��һ�������е��˵�Ҫ��\n");
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
			"\n���"+query("c_name")+c_msg+"\n");
		tell_room( environment(holder), 
			holder->query("c_name") + "��"+query("c_name")+c_msg+"\n",
			holder );
		return dam;
     }
	
}	
