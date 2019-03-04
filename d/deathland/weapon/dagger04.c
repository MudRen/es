#include "../echobomber.h"

//inherit Echo+"/magic";
inherit WEAPON;
int damage_num = 20;

void create()
{
       set_name("night shadow dagger","ҹӰС��");
       add("id",({"dagger",}) );
       set_short("a night shadow dagger","ҹӰС��");
	set_long("@@desc");
	
	set( "unit", "��" );
 	set( "weapon_class", 24 );
    set("type","dagger");
	set( "min_damage", 15 );
	set( "max_damage", 26 );
	set( "weight", 34 );
	set( "value", ({ 2050 , "silver" }) );
    set("hit_func","evil_damage");
    set("special_damage",7);      
    set("special_c_msg","˵:�����ǰѵ��˵����������,�ҵ�����.\n\n");
}

int evil_damage(object victim,int damage)
{
    object holder;
    int my_ali,vic_ali,dam,max;
    string c_msg;
    
    if ( !victim ) return 0;
    if( !(holder = environment(this_object())) || !living(holder) ) return 0;
    my_ali =(int) holder ->query("alignment");
    vic_ali= (int) victim->query("alignment");
    dam = (int) query("special_damage") ;
    if ( my_ali > vic_ali &&  my_ali > -400 ) {
      tell_object(holder,"���а���С������а���Ц��:��ֻ����а�����.\n\n");
      holder->receive_special_damage("evil",dam+random(15));
     // report(holder,holder);
      victim->set("last_attacker", holder );
      return 0;
      }
    else {
	if (damage_num == 0) return 0;
        if (!holder->query("weapon_master")) damage_num--;
      max= my_ali > 0 ? 0 :(my_ali<-2000 ? 20 :(-my_ali)/100  ) ; 
      if ( random(35-max) < 5 )  {
		c_msg = (string)query("special_c_msg");
		victim->receive_special_damage( "evil",dam );
		victim->set("last_attacker", holder );
		tell_object( holder,
                        sprintf("\n���%s%s\n",query("c_name"),c_msg));
		tell_room( environment(holder), 
                        sprintf("%s��%s%s\n",holder->query("c_name"),query("c_name"),c_msg),
			holder );
        if ( vic_ali <= 0 ) 
            return dam;  
        else
            return dam+random(max/3);
	if (damage_num == 0)
		tell_object( holder,"\nҹӰС���ϵĺ�ɫ���󽥽���ʧ�ˡ�\n");
        }
      return 0;
      }    
}
string desc()
{
if (damage_num == 0)
return ("һ�����ض�����ֵ�С��,�ܹ������صش�����˵��������������������ȴ�ƺ�ʧȥ��ԭ�еĹ���\n");
else 
return ("һ�����ض�����ֵ�С��,�ܹ������صش�����˵���������������������������صĺ�ɫ����\n");
}
