#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "silvery dagger", "小银刀" );
	add( "id", ({ "dagger" }) );
	set_short( "小银刀" );
	set_long(
		"这是一把银色匕首，看起来十分锋锐，而且有一种无法形容的魔力。\n"
	);
	set( "unit", "把" );
	set( "weight", 40 );
	setup_weapon( "dagger", 25, 18, 28 );
	set( "value", ({ 220, "silver" }) );
        set( "second", 1 );
//	set("hit_func","holy_damage");
	set("special_damage",5);
	set("special_c_msg","%s的小银刀发出一道银光，射入%s的心脏。\n\n");
}
void report( object attacker, object victim )
{
   seteuid(getuid());
   tell_object( victim,sprintf("( 你%s )\n","/adm/daemons/statsd"->status_string(victim)));
}
int holy_damage(object victim,int damage)
{
    object holder;
    int my_ali,vic_ali,dam,max;
    string msg,c_msg;

    if ( !victim ) return 0;
    if( !(holder = environment(this_object())) || !living(holder) ) return 0;
    my_ali =(int) holder ->query("alignment");
    vic_ali= (int) victim->query("alignment");
    dam = (int) query("special_damage") ;
    if ( my_ali < vic_ali &&  my_ali < 400 ) {
      tell_object(holder,"小银刀发出一道银光，却伤到了你自己。\n\n");
      holder->receive_special_damage("divine",dam+random(10));
      report(holder,holder);
      victim->set("last_attacker", holder );
      return 0;
	    }
    else {
      max= my_ali < 0 ? 0 :(my_ali>2000 ? 20 :(my_ali)/100  ) ;
      if ( random(35-max) < 5 )  {
                c_msg = (string)query("special_c_msg");
                victim->receive_special_damage( "divine",dam );
                victim->set("last_attacker", holder );
                tell_object( holder,
                        sprintf(c_msg,"你",victim->query("c_name")));
                tell_room( environment(holder), 
                		sprintf(c_msg,holder->query("c_name"),victim->query("c_name")),
                        holder );
        if ( vic_ali >= 0 )
            return dam;
        else
            return dam+random(max/3);
}
      return 0;
}
}
