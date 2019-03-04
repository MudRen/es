#include <mudlib.h>
inherit ARMOR;
 
int wielded;
object player;
 
void create()
{
        wielded=0;
        seteuid(getuid());
        set_name("ying-yang ring","����ָ��");
        add("id",({"ring"}) );
        set_short("����ָ��");
        set_long(
"����һ��ָ����һ��һ�����������ּ��໥��ӳ�������ҵļҴ�֮����\n"
        );
        set( "unit", "��" );
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
       "\n�����������ָ����ͬʱ���ƺ��е���Լ�ĵ������öָ��������...\n\n"
       ,"HIB") );
    tell_room( environment(this_player()),set_color(
       "\n�㿴��΢������Լ�ĵ���"+this_player()->query("c_name")+
       "���ֵ�ָ���䷺��.........\n\n"
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
       "\n��ȡ�µ�ָ����ԭ������ɢ�ȫ��ĵ���������ɢȥ......\n\n"
       ,"HIB") );
    tell_room( environment(holder),set_color(
       "\n"+holder->query("c_name")+
       "���ּ�ĵ��������ȡ��ָ����������ɢȥ......\n\n"
       ,"HIB"),holder );
    wielded=0;
    remove_call_out("effect");
    return;
}                 
 
string color()
{ 
  return set_color("$N������֮���ƺ���Լ������ɫ���׹�...\n","HIB");
}
void effect()
{
  int hp;
    
  if (wielded!=1) return;
  if ( ((int) player->query("npc")) == 1 ) return;
    
  tell_object( player, 
     set_color("������ɫ����ָ���ƺ�������ܵ��紥���΢����\n","HIC"),
              );
  hp = player->query("hit_points");
  hp = hp - 5;
  player->set("hit_points",hp);
  if (hp<80) {
  tell_object( player,
     set_color("���������״�����Ǻܺ�, ����������ָ��ȡ��, �Բⰲȫ��\n","HIY"),
               ) ;
  this_object()->unequip();
  return;
  }
  call_out("effect",30);
}         
