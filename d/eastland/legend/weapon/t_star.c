#include <mudlib.h>

inherit WEAPON;

void create()
{
    set_name("Thounder star","地母雷公轰");
    add("id", ({ "star","thounder star" }) );
    set_short("地母雷公轰");
    set_long(@C_LONG
一柄八角小□，□柄长仅及尺，□头还没常人的拳头大，一般人看来小巧玲珑倒像
是孩童的玩具一般，用以临敌，看来全无用处。只有行家才看的出，这种兵器是青
城派双绝之一的雷公轰，而你手上拿的这柄雷公轰异常沈重，且□头银光闪闪，熠
□掩日，必是神兵。
C_LONG
    );
    set( "unit", "把" );
    set( "weapon_class", 30 );
    set( "type","chain");
    set( "min_damage",15);
    set( "max_damage",30);
    set( "weight",270);
    set( "wield_func","weapon_wield");
    set( "unwield_func","weapon_unwield");
    set( "value", ({ 2300, "gold" }) );
}

void weapon_wield()
{
  object holder;
  int my_ali,holder_level;

  holder=environment(this_object());

  if (my_ali=(int)holder->query("war_score")>20000) {
    holder_level=(int)holder->query_level();
    set("min_damage", 8+holder_level);
    set("max_damage", 26+holder_level);
    set("weapon_class", (holder_level*5/2));
    set("hit_func","special_attect");
    }

}

void weapon_unwield()
{
    set("min_damage", 15);
    set("max_damage", 30);
    set("weapon_class", 30);
    delete("hit_func");
}

int special_attect(object victim,int damage)
{
   object holder;
   int my_str,vic_kar,dam,degree;

   if( !victim ) return 0;

   if( !(holder = environment(this_object())) || !living(holder) ) return 0;
   
   if( holder->query("spell_points")< 4) return 0;
   my_str=holder->query_stat("str");
   vic_kar=victim->query_stat("kar");
   vic_kar=vic_kar<5?5:vic_kar;
   degree=3*my_str-2*vic_kar+10;
   if( random(degree)<vic_kar ) return 0;
   dam=((int)holder->query("war_score")-10000)/1000;
   if ( dam > 40 ) dam=40;
   victim->receive_special_damage( "electric",dam );
   victim->set("last_attacker", holder );
   holder->add("spell_points",-4);
   tell_object( holder,
         sprintf("\n你的雷公轰开始隆隆作响....\n       只听霹雳一声，%s\n",
         set_color("爆出一团金光炸的敌人血肉横飞。","HIY"))
         );
   tell_room( environment(holder),
    sprintf("\n%s的雷公轰开始隆隆作响....\n      只听霹雳一声，%s\n",
         holder->query("c_name"),
         set_color("爆出一团金光炸的敌人血肉横飞。","HIY")),holder );
   return 5;
}
