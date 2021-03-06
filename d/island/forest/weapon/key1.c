#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name( "Main key Luoko","树雷主钥" );
    add("id",({"key","luoko"}) );
    set_short( "树雷主钥" );
    set_long(@C_LONG
这是树雷王家嫡传的三把主钥之一，也是血统的证明，乍看只是一把雕工精细
的小手杖，一旦和拥有智慧的人相感应，就能换化成强力的攻击武器。
C_LONG
            );
    set("unit","柄");
    set("weapon_class",35);
    set("type","longblade");
    set("max_damage",5);
    set("min_damage",0);
    set("weight",100);
    set("value",({1000,"silver"}) );
    set("wield_func","daemon_wield");
    set("unwield_func","daemon_unwield");
}

void daemon_wield()
{
    if( (string)this_player()->query("class")=="scholar") {
    set("prevent_drop",1);
    set("min_damage",20);
    set("max_damage",35);
    set("extra_look","@@color");
    tell_object( this_player(),set_color(
       "\n『龙皇』感应到你崇高的智慧，而发出耀眼的金光，幻化成一把长剑...\n\n"
       ,"HIY") );
    tell_room( environment(this_player()),set_color(
       "\n"+this_player()->query("c_name")+
       "手中的主钥突然发出耀眼的金光，化成一把长剑...\n\n"
       ,"HIY"),this_player() );
    set_name("Main key Luoko","树雷主钥『龙皇』");
    set_short("树雷主钥『龙皇』");
    return;
    }
}

void daemon_unwield()
{
	object holder ;
	if ( !holder = environment(this_object()) ) return;
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
    if( (string)holder->query("class")=="scholar") {
    tell_object( holder,set_color(
       "\n你脱手後，『龙皇』身上的金光逐渐散去，恢复成平凡的小木杖...\n\n"
       ,"HIY") );
    tell_room( environment(holder),set_color(
       "\n"+holder->query("c_name")+"手中主钥的金光逐渐散去...\n\n"
       ,"HIY"),holder );
    };
    set_name("Main key Luoko","树雷主钥");
    set_short("树雷主钥"); 
    return ;
    }
}                 

string color()
{
    return set_color("$N的右手中握著一柄凝聚智力而形成的金色长剑...\n","HIY");
}
