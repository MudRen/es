#include <mudlib.h>

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("unknow sword","�����潣");
       add("id",({"sword"}) );
       set_short("�����潣");
	   set_long(@AAA
һ�������ɵ��������Ҳ��һ���Ϲ��������˵�������Ϳ���ʹ�������ʮ�Ľ�
AAA

	);
	
	set( "unit", "��" );
 	set( "weapon_class", 35 );
        set("type","longblade");
//        set("bleeding",10);
	set( "min_damage", 15 );
	set( "max_damage", 35 );
	set( "weight", 110 );
	set( "value", ({ 501, "gold" }) );
//        set("hit_func","sword_damage");
        set("extra_look","$N����һ���������������ŵĽ�");
        set("special_damage",5);
        set_c_verbs( ({"��%s����һ����âն��%s","�Ӷ�%s�ɿ����%s��������",
                       "��%s������Ľ�������%s","��ת%s��һ������ĽǶ�ն��%s"}));
}

int sword_damage(object victim,int damage)
{
    object holder;
    int my_int,dam,n;
    
    if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	my_int = (int)holder->query_stat("int");
        if( (my_int/5) < random(30) )
		return 0;
	if( !(dam = (int)query("special_damage")) ) return 0;
	else {
		
		switch (n=random(5) )
{ case 0:			 
 {    
     tell_object(holder,
     "\n��ʹ�����𽣷�֮ ������� ���糤���������\n\n");
     tell_room(environment(holder),
      "\n"+holder->query("c_name")+"ʹ�����𽣷�֮ ������� ���糤���������\n\n",
      holder);
    victim->receive_special_damage("magic",dam+random(15));
    victim->set("last_attacker",holder);
    return dam;
 }
 case 1:   
 {
      tell_object(holder,
      "\n��ʹ�����𽣷�֮ �Ż����� �����Ϸ�������Ľ�â�������\n\n");
      tell_room(environment(holder),
      "\n"+holder->query("c_name")+"ʹ�����𽣷�֮ �Ż����� �����Ϸ�������Ľ�â�������\n\n",
      holder);
      victim->receive_special_damage("magic",dam+random(20));
      victim->set("last_attacker",holder);
 return dam;
   }
 case 2:
   {
      tell_object(holder,
      "\n��ʹ�����𽣷�֮ Ѫ������ �����Ϸ������������������ \n\n");
      tell_room(environment(holder),
      "\n"+holder->query("c_name")+"ʹ�����𽣷�֮ Ѫ������ �Ľ����Ϸ������������������ȥ\n\n",
      holder);
      victim->set("last_attacker",holder);
      victim->receive_special_damage("magic",dam+random(25));
      return dam;
   }
 case 3:
   {
     
     tell_object(holder,
      "\n��ʹ�����𽣷�֮ ��ʯ��� ������£���ڽ���֮���������\n\n");
      tell_room(environment(holder),
      "\n"+holder->query("c_name")+"ʹ�����𽣷�֮ ��ʯ��� ������£���ڽ���֮���������\n\n",
      holder);
      victim->set("last_attacker",holder);
      victim->receive_special_damage("magic",dam+random(30));
   return dam;
   }
 case 4:
 {
    tell_object(holder,
    "\n��ʹ�����𽣷�֮ ��̶ӡ�� ����Ϊ������������ĽǶȴ������\n\n");
    tell_room(environment(holder),
    "\n"+holder->query("c_name")+"ʹ�����𽣷�֮ ��̶ӡ�� ����Ϊ������������ĽǶȴ������ \n\n", 
    holder);
    victim->set("last_attcaker",holder);
    victim->receive_special_damage("magic",dam+random(15));
    return dam;
 }   
  }
 }
}  