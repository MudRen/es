#include <mudlib.h>

inherit WEAPON;

void create()
{
     set_name("the evil wand", "天魔□杖");
     add ("id",({ "wand",}) );
     set_short("天魔□杖");
     set_long(@LONG
天魔□杖是由天魔穷尽毕生的法力研制而成的一把魔杖。杖前刻著一颗青郁郁的骷
髅头，头上有两个赤红色的眼睛，让人一望不寒而栗。
LONG
     );
     set( "unit", "把" );
     set( "weapon_class", 30 );
     set( "type", "wand" );
     set( "min_damage", 10 );
     set( "max_damage", 20 );
     set( "value", ({ 9000, "silver" }) );
     set( "charge_left",10);
     set( "damaged",0 );
     set("weight",100);
     set("hit_func","wand_damage");
}
int wand_damage(object victim,int damage)
{
    object holder;
    string my_name,ho_name;
    int skill,hint,dam;
    
    if( !victim ) return 0;
    if( !(holder = environment(this_object())) || !living(holder) ) 
        return 0;
    if ( holder->query_temp("cast_busy") )
        return 0;
    if ( query("damaged") ) return 0;
    if ( (holder->query("spell_points") < 20 )&&(!holder->query("npc")) )
       return 0;
    my_name=query("c_name");
    ho_name=holder->query("c_name");
    if( (query("charge_left")<1 ) && ( !query("damaged") ) ) {
       set("damaged",1);
       tell_object(holder,
           sprintf("\n忽地，敌人狠狠往你手中的%s一击，结果%s被敌人敲坏了!!!\n\n",my_name,my_name));
       tell_room(environment(holder),
           sprintf("%s手中的%s被敌人敲坏了～\n",ho_name,my_name),holder);
       add("short"," (受损)") ;
       add("c_name"," (受损)");
       setup_weapon("wand",25,8,15);
       return 0;
    }
    hint=holder->query_stat("int");
    skill=holder->query_skill("wand");
    if ( random(skill + hint*3) > (int)query("weapon_class") )
       return 0; 
    dam=50+random(10);
    tell_object( holder,sprintf(
       "\n你手中的%s发出古老的神秘咒语向敌人袭去!\n\n",my_name)); 
    tell_room( environment(holder),sprintf(
       "\n\n%s手中的%s发出古老的神秘咒语！\n",ho_name,my_name),holder);
    if ( !holder->query("npc") ) {
       add("charge_left",-1);
       holder->add("spell_points",-20);
       dam=40+random(10);
    }
    victim->receive_special_damage("evil",dam);
    victim->set("last_attacker", holder );
    return dam;
}
