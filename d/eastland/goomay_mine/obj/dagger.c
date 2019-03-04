#include "../zeus.h"
inherit WEAPON;
void create()
{
       set_name("magic dagger","魔法匕首");
       add("id",({"magic","dagger",}) );
       set_short("魔法匕首");
       set_long(@LONG
这是一把由魔法磁铁矿所锻造出来的匕首，通体发出亮银色的闪光，
似乎充满了未知的魔法力量。
LONG
);
	
	set( "unit", "把" );
 	set( "weapon_class", 30 );
        set("type","dagger");
	set( "min_damage", 15 );
	set( "max_damage", 30 );
	set( "weight", 90 );
	set( "no_sale",1);
	set( "value", ({ 100 , "silver" }) );
//    set("hit_func","damage");
    set("wield_func","chname");
    set("unwield_func","rename");
    set("master","");
}
int chname()
{ 
	string who;
	object hero;
  hero=environment(this_object()); 
  if ( (string)hero->query("name") == (string)query("master") ) {
        set( "weapon_class", 42 );
	set( "min_damage", 25 );
        set( "max_damage", 39 );
  who="英雄"+this_player()->query("c_name")+"的匕首";
   set_name("magic dagger",who);
   set_short(who);
   tell_object(hero,"\n魔法匕首突然光芒大盛，在匕刃上突然浮现出你的名字 !!\n");
   }
}
int rename()
{ set_name("magic dagger","魔法匕首");
  set_short("magic dagger","魔法匕首");
 	set( "weapon_class", 30 );
	set( "min_damage", 15 );
	set( "max_damage", 30 );
  } 


int damage(object victim)
{
    object holder;
    int dam,min,max;
    holder=environment(this_object());
    if (!holder->query_temp("get_magnetite")) return 0;  
    if ( !victim ) return 0;
    if( !(holder) || !living(holder) ) return 0;
      max=(int)holder->query_stat("str");
      min=(int)holder->query_stat("kar");
        if ( random(140-min) <20) {
		victim->receive_damage(10+random(max) );
		victim->set("last_attacker", holder );
		tell_object( holder,
			"\n你的匕首泛出一道蓝茫茫的雾气飘向敌人，将他卷到半空．接著一道白光射进他的心脏．\n\n");
		tell_room(environment(holder),
		"\n你发觉"+(string)this_object()->query("c_name")+"发出一道旋风把敌人卷上半空中，白光突然一闪．\n\n",
		holder );
        }
      return 0;  
}
