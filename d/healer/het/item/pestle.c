#include <mudlib.h>
inherit WEAPON;

int damage_count=0;
void create()
{
	set_name("poison pestle","����ҩ��");
        add("id",({"mace","pestle"}) );
       	set_short("����ҩ��");
       	set_long(@LONG
�Ȿ�Ƕ���ɳ��ζ������, ��֪Ϊ�����䵽��ҩʦ����,
��֧������˸������ɫ���׹�, �Եü�Ϊ���졣
LONG
        );
	set("no_sale",1);
	set( "unit", "��" );
 	set( "weapon_class", 36 );
        set("type","blunt");
	set( "min_damage", 13 );
	set( "max_damage", 33 );
	set( "weight", 160 );
	set( "value", ({ 350, "gold" }) );
//        set("hit_func","blunt_damage");
//        set("special_damage",15);
//        set("special_c_msg","����һ����ֲ����׹�,����ס����.\n\n");
}
/*
int blunt_damage(object victim,int damage)
{
    object holder;
    int my_kar,vic_kar,dam;
    int my_int,vic_int;
    string c_msg;
    
    if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	my_kar = (int)holder->query_stat("kar");
	vic_kar =(int)victim->query_stat("kar");
	my_int = (int)holder->query_stat("int");
	vic_int =(int)victim->query_stat("int"); 
	if( random(my_kar*4) + my_int < random(vic_kar*5) + 10 + vic_int  &&
	    (damage_count++) <= 8 )
		return 0;
	if( !(dam = (int)query("special_damage")) ) return 0;
	else {
		c_msg = (string) query("special_c_msg") + "\n";
		victim->receive_special_damage( "poison" , dam );
		victim->set("last_attacker", holder );
		tell_object( holder,
			"\n���"+query("c_name")+c_msg);
		tell_room( environment(holder), 
			holder->query("c_cap_name") + "��" + query("c_name") + c_msg,
			holder );
		damage_count=0;
		return dam;
     }
	
}
*/
