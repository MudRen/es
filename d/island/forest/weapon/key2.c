#include "../tsunami.h"

inherit WEAPON;

void create()
{
        set_name( "Main key Janser","树雷主钥");
        add( "id", ({ "key","janser"}) );
        set_short( "树雷主钥");
        set_long(@C_LONG
这是树雷王家嫡传的三把主钥之一，也是血统的证明，乍看只是一把雕工精细
的小手杖，一旦和心思细腻的人相感应，就能换化成强力的攻击武器。
C_LONG
        );

        set("unit", "柄" );
        set("weight", 100 );
        set("type","dagger" );
        set("weapon_class",30 );
        set("max_damage",5);
        set("min_damage",0);
        set("value", ({1000, "silver" }) );
        set("wield_func","daemon_wield");
        set("unwield_func","daemon_unwield");
}

void daemon_wield()
{
    if( (string)this_player()->query("class")==("healer") || 
        (string)this_player()->query("class")==("mage") ||
        (string)this_player()->query("class")==("thief") ){
    set("prevent_drop",1);
    set("min_damage",18);
    set("max_damage",32);
    set("extra_look","@@color");
    tell_object( this_player(),set_color(
       "\n『船穗』感应到你细腻的心思，而发出耀眼的蓝光，幻化成一把匕首...\n\n"
       ,"HIC") );
    tell_room( environment(this_player()),set_color(
       "\n"+this_player()->query("c_name")+
       "手中的主钥突然发出耀眼的蓝光，化成一把匕首...\n\n"
       ,"HIC"),this_player() );
    set_name("Main key Janser","树雷主钥『船穗』");
    set_short("树雷主钥『船穗』");
    return;
    }return;
}

void daemon_unwield()
{
	object holder;
	if ( !holder=environment(this_object()) ) return;
    if( (int)this_object()->query("wc_damaged") ){
         tell_object( this_player(),"你手中的树雷主钥突然间强光一闪就消失不见了....\n");
         tell_room( environment(this_player()),
           this_player()->query("c_name")+"手中的树雷主钥突然强光一闪就消失了....\n",
           this_player() );
           this_object()->remove();
           return;
           }	
    else{
    set("min_damage",0);
    set("max_damage",5);
    set("prevent_drop",0);
    delete("extra_look");
    if( (string)holder->query("class")==("healer") ||
        (string)holder->query("class")==("mage") ||    
        (string)holder->query("class")==("thief") ){
   tell_object( holder,set_color(
      "\n你脱手後，『船穗』身上的蓝光逐渐散去，恢复成平凡的小木杖...\n\n"
      ,"HIC") );
   tell_room( environment(holder),set_color(
      "\n"+holder->query("c_name")+
      "手中主钥的蓝光逐渐散去.......\n\n"
      ,"HIC"),holder );
    };
   set_name("Main key Janser","树雷主钥");
   set_short("树雷主钥");
   return;
   }
}       

string color()
{
   return set_color("$N的右手中正握著一柄细长的蓝色匕首，不时泛出耀眼的光芒...\n","HIC");
}

    
