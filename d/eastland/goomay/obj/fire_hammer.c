#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "fire hammer", "����֮��" );
	add( "id", ({ "hammer" }) );
	set_short("����֮��" );
	set_long(
		"����һ�ѻ��ľ޴�����˵���Է��������һ����������\n"
	);
	set( "unit", "��" );
	set( "weight", 250 );
	setup_weapon( "blunt", 45, 25, 45 );
	set( "value", ({ 220, "gold" }) );
        set("no_sale",1);
        set("nosecond",1);

//	set("hit_func","fire_damage");
	set("special_damage",25);
	set("special_c_msg","����������һ��������һ�����棬������˵����塣\n\n");
}
void report( object attacker, object victim )
{
   seteuid(getuid());
   tell_object( victim,
     sprintf("( ��%s )\n","/adm/daemons/statsd"->status_string(victim))
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
      tell_object(holder,"����֮����������һ�����췢��һ�����棬ȴ�䵽�����Լ���\n\n");
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
                        "\n���"+query("c_name")+c_msg+"\n");
                tell_room( environment(holder), 
                        holder->query("c_name") + "��"+query("c_name")+c_msg+"\n",
                        holder );
            return dam;
}
      return 0;
}
}
