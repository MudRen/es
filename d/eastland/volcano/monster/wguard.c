#include "../oldcat.h" 

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(14);
	set_name( "The soldier", "矮灵族卫兵" );
	add( "id", ({ "soldier" }) );
	set_short( "矮灵族卫兵" );
	set_long(
		"他守护著矮灵族部落，负责部落的安全。\n"
	);
	set( "max_hp", 600 );
	set( "hit_points", 600 );
	set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 16 );
	set_skill( "longblade",100);
	set_skill( "parry", 80 );
	set_skill( "dodge", 60 );
	
	set( "gender", "male" );
	set( "race", "dwarf" );
	set( "alignment", -200 );
	set( "natural_armor_class", 50 );
	set( "natural_defense_bonus", 15 );
	set( "wealth/gold", 15 );
        set("inquiry", ([
            "head" : "@@ask_head",
            "cut" : "@@ask_head",
            "volcano" : "@@ask_volcano",
            ]) );
     
        ob1=new(OWEAPON"wsword");
        ob1->move( this_object() );
	wield_weapon(ob1);
        equip_armor(OARMOR"mail2");
}

void ask_volcano(object who)
{
  tell_object(who,"守卫对你说：火山随时都有爆发的可能，我们在这里做了望的工作。\n");
  return;
}

void ask_head(object who)
{
  int i;
  object ob,*item;

  item=all_inventory(this_player());
  for(i=0;i<sizeof(item);i++) {
    if ((string)item[i]->query("name")=="sharp knife") {
      write("守卫说：你已经有一把割人头的利器了。\n");
      return;
    }
  }
  if (this_player()->query_temp("head_knife")) {
     write("守卫说：我记得已经给过你那锐利的刀子了。\n");
     return;
  }
  tell_object(who,
    "守卫说：嗯、要想顺利的把人头割下来，须要一把锐利的刀子。\n");
  ob=new(OOBJ"head_knife");
  ob->move(this_object());
  command("give "+(string)ob->query("name")+" to "+lower_case((string)this_player()->query("name")));
  this_player()->set_temp("head_knife",1);
  return;
}
