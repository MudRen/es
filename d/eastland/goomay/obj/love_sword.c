#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "sword of love", "�ϵ��Ļ��齣" );
        add( "id", ({ "sword" }) );
        set_short( "�ϵ��Ļ��齣" );
        set_long(
                "����һ��ͨ������ɫ�Ľ�����ѽ����������⴦һ�գ����ǰ��\n"
                "����Ҳû�С�����Լ���Ըо�������ɢ����һ���º����õĸо���\n"
                "�ڽ������ɴ����㷢�ֿ���һ��С�� �� ��˿��ն �Ͻ����顣\n"
        );

	set( "unit", "��" );
	set( "weight", 150 );
	setup_weapon( "longblade", 40, 20, 40 );
	set( "value", ({ 400, "gold" }) );
        set("no_sale",1);

//	set("hit_func","love_damage");
	set("special_damage",10);
    set("special_c_msg","��Ļ��齣�Ķϴ�ͻȻ������ԣ�һ����âֱֱ����������ţ�\n
��ͻȻ�����˹�ȥ���е�����ʱ�⣬����һ���ʹ������������Ҳ�ղ�ס�� .\n\n");
	set("special_c_msg2","%s�Ļ��齣�ϴ�ͻȻ������ԣ�һ����âֱֱ����%s������ .\n\n");
}
void report( object attacker, object victim )
{
   seteuid(getuid());
   tell_object( victim,
   sprintf("( ��%s )\n","/adm/daemons/statsd"->status_string(victim))
   );
}
int love_damage(object victim,int damage)
{
    object holder;
    int dam,max;
    string c_msg;

    if ( !victim ) return 0;
    if( !(holder = environment(this_object())) || !living(holder) ) return 0;
    if ( (int)holder->query_skill("longblade")<85 ) {
      tell_object(holder,
		  query("special_c_msg"));
      holder->receive_special_damage("mental",dam+random(15));
      report(holder,holder);
      victim->set("last_attacker", holder );
      return 0;
    }
    else {
    dam = (int) query("special_damage") ;
	max=random(100);
      if ( max < 20 )  {
                c_msg = (string)query("special_c_msg2");
                victim->receive_special_damage( "mental",dam+max );
                victim->set("last_attacker", holder );
                tell_object( holder, 
                        sprintf(c_msg,"\n��",victim->query("c_name")));
                tell_room( environment(holder), 
                        sprintf(c_msg,holder->query("c_name"),victim->query("c_name")),
                        holder );
            return dam;
}
      return 0;
}
}
