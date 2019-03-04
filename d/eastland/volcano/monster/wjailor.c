#include "../oldcat.h" 

inherit MONSTER;

void create()
{
	object ob1,ob2;

	::create();
	set_level(14);
	set_name( "guard", "����������" );
	add( "id", ({ "guard" }) );
	set_short( "����������" );
	set_long(
	  "һ�������ؼ�Ʒ���������������������������ٵ�һ����ɡ�\n"
	);
	set( "max_hp", 500 );
	set( "hit_points", 500 );
	set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "kar", 20 );
	set_skill( "chain", 80 );
	set_skill( "parry", 80 );
	set_skill( "dodge", 60 );
        set_skill( "tactic", 80 );
	
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", -800 );
        set( "tactic", "melee" );
	set( "natural_armor_class", 40 );
	set( "natural_defense_bonus", 29 );
        set_natural_weapon(2,5,8);
	set( "wealth/gold", 20 );

	ob1=new(OWEAPON"wstar");
	ob1->move( this_object() );
	wield_weapon(ob1);

        ob2=new(OOBJ"wguard_key");
        ob2->move(this_object());

        equip_armor(OARMOR"mail4");
}

void die()
{
  object ob1,killer;

  killer=query("last_attacker");
  if (!killer) {
    ::die();
    return;
  }
  tell_object(killer,
    "����˵������춻��Ǽ���һ���������Ҽ�ס����Ҫ�����ٱ�һ�������������䡣\n");

  ::die();
}
