#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "wraith dagger", "����֮ذ" );
	add( "id", ({ "dagger" }) );
	set_short( "����֮ذ" );
	set_long(
		"����һ�Ѱ���֮ذ������մ����Ѫ����������һ���޷����ݵ�ħ����\n"
	);
	set( "unit", "��" );
	set( "weight", 40 );
	setup_weapon( "dagger", 35, 19, 33 );
	set( "value", ({ 1500, "silver" }) );
        set( "second", 1 );
//	set("hit_func","evil_damage");
	set("special_damage",8);
	set("special_msg","���һ��Ѫ�⣬������˵���ꡣ\n");
}

int evil_damage(object victim,int damage)
{
    object holder;
    int my_ali,vic_ali,dam,max;
    string msg;

    holder=environment(this_object());
    my_ali =(int) holder ->query("alignment");
    vic_ali= (int) victim->query("alignment");
    dam = (int) query("special_damage") ;
    if ( my_ali > vic_ali &&  my_ali > -3000 ) {
      tell_object(holder,"����֮ذ���һ��Ѫ�⣬ȴ�˵������Լ���\n\n");
      holder->receive_special_damage("evil",dam+random(20));
      victim->set("last_attacker", holder );
      return 0;
    }
    else {
      max= my_ali > 0 ? 0 :(my_ali<-2000 ? 35 :(my_ali)/-100  ) ;
      if ( random(35-max) < 5 )  {
        msg = (string)query("special_msg");
        msg = (string)query("special_msg");
        victim->receive_special_damage( "evil",dam );
        victim->set("last_attacker", holder );
        if( !msg ) return 0;
        tell_object( holder,
           "\n���"+query("c_name")+msg+"\n");
        tell_room( environment(holder),
           holder->query("c_name") + "��"+query("c_name")+msg+"\n",
           holder );
        if ( vic_ali < 0 )
            return dam;
        else
            return dam+random(max/3);
      }
      return 0;
    }
}
