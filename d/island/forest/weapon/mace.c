#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name("Police Mace","����");
    add("id",({"mace"}) );
    set_short("����");
    set_long(@LONG
���Ǹ����������ͽ��ʯ�ϳɵľ����񱩹�.
LONG
             ); 
    set("unit","��");
    set("weapon_class",25);
    set("type","blunt");
    set("min_damage",15);
    set("max_damage",30);
    set("weight",150);
//    set("hit_func","special_atk");
    set("special_damage",2);
    set("value",({400,"silver"}) );
 }
 
 int special_atk(object victim,int dam)
 {
     object holder;
     dam=(int)query("special_damage");

     if( !victim ) return 0;
     if( !(holder=environment(this_object())) || !living(holder) )
     return 0;
     
     if( random(20) > 5 ) return 0;
     tell_object(victim,
     "\nͻȻ��������һ�����������ȫ�������޷�ʹ��\n\n" );
     tell_room(environment(victim),
     "\nͻȻ��������һ������ֻ��"+victim->query("c_name")+"����̱����ȥ��\n\n"
     ,victim );
     victim->block_attack(6);
     victim->set("last_attacker",holder);
     victim->receive_damage( dam );
     victim->set_temp("msg_stop_attack",
     "(��ȫ�����¸е���ʹ�������޷����ֹ�����)\n" );
     return dam;
}
