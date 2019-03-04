#include "../echobomber.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(10);
    set_name("guardian","�ػ���");
    add ("id", ({ "guardian"}) );
    set_short( "a guardian",
           "�ػ���");
	set_long(@LONG
A strange and mystic guard 
LONG
    ,@C_LONG
һ����������ص��ػ���,�ƺ���һ����Ӱ.
C_LONG
	);
	set("alignment" , -700 );
    set("weapon_master",1);
    set( "gender", "male" );
    set( "race", "unknown");
    set( "unit", "��" );
    set_perm_stat( "dex",  12);
    set_perm_stat( "str",  15);
    set_perm_stat( "int",  18);
    set_perm_stat( "piety", 8);
    set_perm_stat( "karma",14);
    set ("max_hp",290);
    set ("max_sp",20);
    set ("hit_points",290);
    set ("spell_points",20);
    set ("wealth", ([ "gold":33]) );
    set_natural_weapon(17,1,9);
	set_natural_armor(65,18);
	set ("special_defense",(["all":17]) );
    wield_weapon(Weapon"/dagger04"); 
    set("tactic_func","to_close");
}

int to_close()
{
   object ob1;
   
   ob1=environment(this_object());
   if ((string)(ob1->query("doors/up/status"))!="close")
     command("close door");
   return 0;    
}

