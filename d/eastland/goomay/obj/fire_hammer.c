#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "fire hammer", "火焰之锤" );
	add( "id", ({ "hammer" }) );
	set_short("火焰之锤" );
	set_long(
		"这是一把火红的巨锤，据说可以发出像火神一样的威力。\n"
	);
	set( "unit", "把" );
	set( "weight", 250 );
	setup_weapon( "blunt", 45, 25, 45 );
	set( "value", ({ 220, "gold" }) );
        set("no_sale",1);
        set("nosecond",1);

//	set("hit_func","fire_damage");
	set("special_damage",25);
	set("special_c_msg","「哗啦」的一声，发出一道火焰，轰击敌人的身体。\n\n");
}
void report( object attacker, object victim )
{
   seteuid(getuid());
   tell_object( victim,
     sprintf("( 你%s )\n","/adm/daemons/statsd"->status_string(victim))
   );
   return 1;
}
int fire_damage(object victim,int damage)
{
    object holder;
    int dam,max;
    string msg,c_msg;


    if ( !victim ) return 0;
    if( !(holder = environment(this_object())) || !living(holder) ) return 0;
    if ( (int)holder->query_skill("blunt")<90 ) {
      tell_object(holder,"火焰之锤「哗啦」一声巨响发出一道火焰，却轰到了你自己。\n\n");
      holder->receive_special_damage("fire",dam+random(20));
      report(holder,holder);
      victim->set("last_attacker", holder );
      return 0;
    }
    else {
    dam = (int) query("special_damage") ;
	max=random(100);
      if ( max < 20 )  {
                c_msg = (string)query("special_c_msg");
                victim->receive_special_damage( "fire",dam+max );
                victim->set("last_attacker", holder );
                tell_object( holder, 
                        "\n你的"+query("c_name")+c_msg+"\n");
                tell_room( environment(holder), 
                        holder->query("c_name") + "的"+query("c_name")+c_msg+"\n",
                        holder );
            return dam;
}
      return 0;
}
}
