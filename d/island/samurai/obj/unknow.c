#include <mudlib.h>

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("unknow sword","������");
       add("id",({"sword"}) );
       set_short("������");
	   set_long(@AAA
һ�������Ҳ����۵Ľ�����˵����һ�����������İ���
AAA
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 45 );
    set("type","longblade");
	set( "min_damage", 25 );
	set( "max_damage", 45 );
	set( "weight", 110 );
	set( "value", ({ 501, "gold" }) );
//    set("hit_func","staff_damage");
    set("special_damage",5);
}

int staff_damage(object victim,int damage)
{
    object holder;
    int my_int,vic_int,dam,n;
    
    if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	my_int = (int)holder->query_stat("int");
	vic_int =(int)victim->query_stat("int");
        if( (random(my_int*3) < vic_int*2) && ((damage_count++)<=5))
		return 0;
	if( !(dam = (int)query("special_damage")) ) return 0;
	else {
		
		switch (n=random(4) )
{ case 0:			 
 {    
     tell_object(holder,
     "\n��ʹ������������һ�� ��Į�籩 ��������ŵ�����һ���������\n\n");
     tell_room(environment(holder),
      "\n"+holder->query("c_name")+"�Ľ�����ŵ�����һ���������\n\n",
      holder);
    victim->receive_special_damage("magic",dam);
    victim->set("last_attacker",holder);
    damage_count =0;
    return dam;
 }
 case 1:   
 {
      tell_object(holder,
      "\n��ʹ�����������ڶ�ʽ ������ѩ �������Ϸ����������Ľ���\n\n");
      tell_room(environment(holder),
      "\n"+holder->query("c_name")+"�Ľ����Ϸ����������Ľ����������\n\n",
      holder);
      victim->receive_special_damage("magic",dam+10);
      victim->set("last_attacker",holder);
      damage_count =0;
 return dam;
   }
 case 2:
   {
      tell_object(holder,
      "\n��ʹ��������������ʽ ŭ�ξ��� �����Ϸ������������������ \n\n");
      tell_room(environment(holder),
      "\n"+holder->query("c_name")+"�Ľ����Ϸ������������������ȥ\n\n",
      holder);
      victim->set("last_attacker",holder);
      victim->receive_special_damage("magic",dam+15);
      damage_count =0;
      return dam;
   }
 case 3:
   {
     
     tell_object(holder,
      "\n��ʹ��������������ʽ ������� �����˽���һ����˳�ȥ\n\n");
      tell_room(environment(holder),
      "\n"+holder->query("c_name")+"����һ�������������˹�ȥ\n\n",
      holder);
      victim->set("last_attacker",holder);
      victim->receive_special_damage("magic",dam+20);
      damage_count =0;
   return dam;
   }
  }
 }
}  
