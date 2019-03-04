#include <mudlib.h>
inherit WEAPON;

void create()
{
    set_name("sound_raise_sword","����֮�� ");
    add("id",({"sword"}) );
    set_short("sound_raise_sword","����֮�� ");
           set_long(@AAA
����һ�Ѻ��п��ƴ������������Ķ̽�,�����Ͽ������ʹ������鶨��Լ�ķ�ӡ
AAA
        );
    set("unit","��");
    set("second",1);
    set("weapon_class",40);
    set("type","shortblade");
    set("min_damage",17);
    set("max_damage",40);
    set("weight",150);
    set("value",({120,"gold"}));
//    set("hit_func","sound_damage");
    set("special_c_msg","������֮��ͻȻ�俪ʼ�������� !! \n\n����֮���Ľ�������һ���������������˵�Ҫ��!!\n\n");
}

int sound_damage(object victim,int damage)
{
    object holder;
    int my_kar,dam;
    string c_msg;
    
    dam = 5 + random(15) ;
    
    if( !victim ) return 0;
      if( !(holder = environment(this_object())) || !living(holder) ) return 0;
        my_kar = (int)holder->query_stat("kar");
        if( random(20) > my_kar/5 )
                return 0;
        else {
                c_msg = (string)query("special_c_msg");
                victim->receive_damage( dam );
                victim->set("last_attacker", holder );
                tell_object( holder, 
                        "\n��"+c_msg );
                tell_room( environment(holder), 
                        holder->query("c_name") + c_msg,
                        holder );
                return dam;
     }
        
}       
