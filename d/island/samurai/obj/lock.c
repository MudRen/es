/*
 * ԭ���ߣ�Mercury (1995.1)
 * �޸��ߣ�Ishige (1995.12)
 */

#include <mudlib.h>

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("Blade Lock","����");
       add("id",({"lock","blade"}) );
       set_short("����");
	   set_long(@AAA
����һ����״�൱��ֵĵ���������ʲ�����⹦��
AAA

	);
	
	set( "unit", "��" );
	set( "second",1);
 	set( "weapon_class", 40 );
        set("type","longblade");
	set( "min_damage", 15 );
	set( "max_damage", 40 );
	set( "weight", 200 );
	set( "value", ({ 200, "gold" }) );
//        set("hit_func","sword_damage");
//        set("special_damage",15);
}

int sword_damage(object victim,int damage)
{
    object holder;
    int my_int,dam,n;
    
    if( !victim ) return 0;
    if( (int)victim->query("weapon1") == 0 ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	my_int = (int)holder->query_stat("int");
	if( (my_int/5) < random(25) )
		return 0;
	if( !(dam = (int)query("special_damage")) ) return 0;
	else {
		
		switch (n=random(2) )
{ case 0:			 
 {    
     tell_object(holder,
     "\n�㽫���ϵĵ�������������˵�������ס\n\n");
     tell_room(environment(holder),
      "\n"+holder->query("c_cap_name")+"�����ϵĵ����������"+victim->query("c_cap_name")+"��������ס\n\n",
      holder);
    victim->receive_damage(dam);
    victim->set("last_attacker",holder);
    victim->block_attack(6);
    victim->set_temp("msg_stop_attack",
    "( �����ϵ����������������ˣ����޷����ֹ���!! )\n");
    return dam;
 }
 case 1:   
 {
      tell_object(holder,
      "\n�����ϵĵ�������ҫ�۵Ĺ�â��ն�����\n\n");
      tell_room(environment(holder),
      "\n"+holder->query("c_cap_name")+"���ϵĵ�������ҫ�۵Ĺ�â��ն����\n\n",
      holder);
      victim->receive_damage(dam+random(15));
      victim->set("last_attacker",holder);
 return dam;
   }
  }
 }
}  
