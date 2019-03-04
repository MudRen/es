#include "../moyada.h"

inherit WEAPON;

void create()
{
    seteuid( getuid() );
	set_name("Death Scythe", "死神镰刀");
	add ("id",({ "scythe", }) );
	set_short("死神镰刀");
	set_long(@C_LONG
一把很十分锋利的大镰刀，据说是死神心爱的武器。
它可以用来割草(cropp)吗? 
C_LONG
	);
	set( "unit", "把" );
	set( "weapon_class", 21 );
        set( "type", "longblade" );
	set( "min_damage", 12 );
	set( "max_damage", 20 );
	set( "weight", 150 );
	set( "no_sale", 1);
	set( "nosecond", 1);
	set( "value", ({ 10, "silver" }) );
}

void init()
{
        add_action("to_cropp","cropp");
}

int to_cropp(string str)
{
      object ob;
      write(@ALONG
            
        死神镰刀很生气地说: 你想用我来割草! 从来没人敢如此对待我。
        死神镰刀从你的手中跳起来，飞到空中并很不爽的舞著。

ALONG
             );
      ob=new( MOYADA"monster/death_scythe" );
      ob->move( environment(environment(this_object())) );
      this_object()->remove();
      return 1;
}
