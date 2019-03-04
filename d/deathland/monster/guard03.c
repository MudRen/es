#include "../echobomber.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(18);
    set_name("dwarf guard","������������");
    add ("id", ({ "guard","dwarf"}) );
    set_short( "a dwarf final guard",
           "������������");
	set_long(@LONG
��������������ػ������˵�����һ������,������,
LONG
	);
    set("alignment",400);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "��" );
    set_perm_stat( "dex",  22);
    set_perm_stat( "str",  25);
    set_perm_stat( "int",  18);
    set_perm_stat( "piety", 8);
    set_perm_stat( "karma",24);
	set_skill("chain",88);
	set_skill("parry",95);
    set_skill("shortblade",80);
    set_skill("two-weapon",100);
    set ("max_hp",590);
    set ("max_sp",0);
    set ("hit_points",590);
    set ("spell_points",0);
    set ("wealth", ([ "gold":33]) );
    set ("natural_weapon_class1",27);
	set ("natural_weapon_class2",14);
	set ("natural_defense_bonus",32);
	set ("natural_armor_class", 53);
	set ("natural_defense_bouns",19);
	set ("natural_min_damage1", 15);
	set ("natural_max_damage1", 16);
	set ("natural_min_damage2", 1);
	set ("natural_max_damage2", 5);
    set ("special_defense",(["all":30,"none":20]) );
    set ("aim_difficulty",(["critical":30,"vascular":30]) );
    set ("weight", 350);
    set("chat_chance",10);
    set("chat_output",({
        "����˵:�뿪���� !!\n"
       }) );
      wield_weapon2(Weapon"/shortsword03");
      wield_weapon(Weapon"/chain01"); 
      equip_armor(Armour"/ringmail02");
      equip_armor(Armour"/armband02");
      equip_armor(Armour"/boots03");
      equip_armor(Armour"/gloves01");
}

