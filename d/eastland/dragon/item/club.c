
#include "../../layuter.h"
inherit WEAPON;

void create()
{
        seteuid(getuid());
        set_name( "dragon god drumstick", "龙神鼓槌" );
        add( "id",({ "drumstick"}) );
        set_short( "龙神鼓槌" );
        set_long(
            "这把鼓槌可以击(beat)鼓(drum)。\n"
        );
        set( "unit", "把");
        set("no_sale",1);
        set( "weapon_class", 23 );
        set( "type", "blunt" );
        set( "min_damage", 10);
        set( "max_damage", 15 );
        set( "weight", 180 );
        set( "value", ({ 50, "gold" }) );
}

void init()
{
  add_action("to_beat","beat");
 }
  
int to_beat(string str)
{  
   object owner,env,mob;
   
   if(!str||str=="") return notify_fail("你要敲什麽??\n");
   if(str!="drum") return 0 ;
    
   owner=environment(this_object());
   if(owner!=this_player()) return 0 ; 
   
   env=environment(this_player());
   if(!(env->query("beat_control")))
         { return notify_fail("这儿没有合适的鼓可以敲。\n") ; }
   if(this_object()->query("once_beat"))
        { return notify_fail("这根鼓槌已经被敲烂了。\n") ; }

   this_object()->set("once_beat",1) ;
   mob=find_object_or_load(Ldmonster"dragon");   
   
   if(present(mob,env))
        {return notify_fail("鼓声大作但没有任何事发生\n"); }
   mob->move(env);
   write("从湖的中央，一只巨龙缓缓地从湖中升起，它的狰拧型态，令人望而生惧\n");
   this_player()->set_explore("eastland#5");
   return 1; 
}
