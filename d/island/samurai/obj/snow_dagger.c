#include <mudlib.h>
inherit WEAPON;

void create()
{
    set_name("Snow dagger","雪□颜");
    add("id",({"snow","dagger"}) );
    set_short("Snow dagger","雪□颜");
    set_long(@AAA
这是一把雕刻精美的匕首，让你感觉到这应该是把艺术品而不是武器，而在你
细细观看这把匕首之时，你彷佛可看见一幅雪国的景色！！！
AAA
       );
    set("unit","把");
    set("second",1);
    set("weapon_class",39);
    set("type","dagger");
    set("min_damage",15);
    set("max_damage",33);
    set("weight",90);
    set("value",({120,"gold"}));
//    set("hit_func","snow_damage");
    set("special_msg","  .\n\n");
    set("special_c_msg"," 散发出一阵阵的寒气 ！！！\n\n"
        "这一阵阵的寒气凝结出一只只的冰刃，射入敌人的心脏！！！\n");
}

int snow_damage(object victim,int damage)
{
    object holder;
    int my_kar,dam;
    string c_msg,msg;
    
    dam = 15 + random(20);
    
    if( !victim ) return 0;
      if( !(holder = environment(this_object())) || !living(holder) ) return 0;
        my_kar = (int)holder->query_stat("kar");
        
        if( random(20) > my_kar/5 )
                return 0;
        else {
                msg = (string)query("special_msg");
                c_msg = (string)query("special_c_msg");
                victim->receive_special_damage("cold",dam);
                victim->set("last_attacker", holder );
                if( !c_msg ) c_msg = msg;
                if( !msg ) return 0;
                tell_object( holder, can_read_chinese(holder)?
                        "\n你的"+query("c_name")+c_msg+"\n":
                        "\nYour "+query("name")+msg+"\n" );
                tell_room( environment(holder), 
                        holder->query("c_name") + "的"+query("c_name")+c_msg+"\n",
                        holder );
                return dam;
     }
        
}       

