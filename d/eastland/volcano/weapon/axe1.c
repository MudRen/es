#include "../oldcat.h"

inherit WEAPON;

void create()
{
       set_name("Huge Axe","���鸫");
       add("id",({"axe",}) );
       set_short("���鸫");
       set_long(
           "������������õ�һ�Ѹ�ͷ\n"
     	);
	
	set("no_sale",1);
	set( "unit", "��" );
 	set( "weapon_class", 45 );
        set("type","axe");
        set("bleeding",8);
	set( "min_damage", 28 );
	set( "max_damage", 40 );
	set( "weight", 210 );
	set( "value", ({ 300, "gold" }) );
//	set("hit_func","axe_damage");
        set("special_damage",20);
        set("special_msg","�ӳ�һ���ƿ�����ֱ������˵ķ�������.\n");
}

int axe_damage(object victim,int damage)
{
    object holder;
    int my_pie,vic_pie,dam;
    string c_msg,msg;
    
        if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	my_pie = (int)holder->query_stat("pie");
	vic_pie =(int)victim->query_stat("pie");
	if( random(my_pie*3) < vic_pie*2 ) return 0;
	if( !(dam = (int)query("special_damage")) ) return 0;
        if ((int)holder->query_skill("axe")<80) {
          tell_object(holder,
              "\n����ǿ�Ӷ��ľ��鸫��������������С���˵����Լ�.\n\n");
          tell_room(environment(holder),
              "\n"+holder->query("c_name")+"�ľ��鸫��������������С���˵����Լ�.\n\n",
              holder );
          holder->receive_damage(dam);
          return dam;
        }
	msg = (string)query("special_msg");
	victim->receive_damage( dam );
	victim->set("last_attacker", holder );
	if( !c_msg ) c_msg = msg;
	if( !msg ) return 0;
	tell_object( holder, 
		"\n���"+query("c_name")+c_msg+"\n");
	tell_room( environment(holder),
	holder->query("c_name") + "��"+query("c_name")+msg+"\n",
		holder );
	return dam;
	
}	

