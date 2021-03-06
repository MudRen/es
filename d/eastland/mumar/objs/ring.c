#include <mudlib.h>
inherit ARMOR;
 
int wielded;
object player;
 
void create()
{
        wielded=0;
        seteuid(getuid());
        set_name("ying-yang ring","两仪指环");
        add("id",({"ring"}) );
        set_short("两仪指环");
        set_long(
"这是一对指环，一阴一阳，在你两手间相互辉映。是诸葛家的家传之宝。\n"
        );
        set( "unit", "对" );
        set( "weight", 60 );
        set( "type", "finger" );
        set( "material", "element" );
        set( "armor_class", 0 );
        set( "defense_bonus", 9 );
        set( "value", ({ 5000, "silver" }) );
        set("equip_func","daemon_wear");
        set("unequip_func","daemon_unwear");
}
 
void daemon_wear()
{
    set("prevent_drop",1);
    set("light",1);
    set("extra_look","@@color");
    write( set_color(
       "\n当你戴上两仪指环的同时，似乎感到隐约的电光在两枚指环中流动...\n\n"
       ,"HIB") );
    tell_room( environment(this_player()),set_color(
       "\n你看到微弱而隐约的电光从"+this_player()->query("c_name")+
       "两手的指环间泛出.........\n\n"
       ,"HIB"),this_player() );
    wielded=1;
    player=this_player();
    call_out("effect", 10);
}
 
void daemon_unwear()
{
    object holder;
    if ( !this_object() ) return ;
    if ( !holder=environment(this_object()) ) return;
//  holder=this_player();
    set("light",0);
    delete("extra_look");
    set("prevent_drop",0);
    tell_object( holder,set_color(
       "\n你取下的指环，原本几乎散於全身的电流缓缓地散去......\n\n"
       ,"HIB") );
    tell_room( environment(holder),set_color(
       "\n"+holder->query("c_name")+
       "两手间的电光随著他取下指环而缓缓的散去......\n\n"
       ,"HIB"),holder );
    wielded=0;
    remove_call_out("effect");
    return;
}                 
 
string color()
{ 
  return set_color("$N的两手之间似乎隐约泛著蓝色的雷光...\n","HIB");
}
void effect()
{
  int hp;
    
  if (wielded!=1) return;
  if ( ((int) player->query("npc")) == 1 ) return;
    
  tell_object( player, 
     set_color("泛著蓝色电光的指环似乎让你感受到如触电的微颤。\n","HIC"),
              );
  hp = player->query("hit_points");
  hp = hp - 5;
  player->set("hit_points",hp);
  if (hp<80) {
  tell_object( player,
     set_color("你觉得身体状况不是很好, 决定将两仪指环取下, 以测安全。\n","HIY"),
               ) ;
  this_object()->unequip();
  return;
  }
  call_out("effect",30);
}         
