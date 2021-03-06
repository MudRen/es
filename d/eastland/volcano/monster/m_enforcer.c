#include "../oldcat.h"

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(11);
	set_name( "The middle_temple enforcer", "正殿执事" );
	add( "id", ({ "enforcer" }) );
	set_short( "正殿执事" );
	set_long(
                "一位神殿正殿执事。\n"
	);
	set( "race", "dwarf" );
	set( "gender", "male" );
	set( "alignment", 400 );
	set_perm_stat( "str", 17 );
        set_perm_stat( "dex", 17 );
        set_perm_stat( "int", 22 );
        set_perm_stat( "pie", 25 );
	set( "wealth/gold", 16 );
        set( "hit_points", 210);
        set( "max_hp", 210);
        set("natural_armor_class",35);
        set("natural_defense_bonus",20);
        set_natural_weapon(10,2,5);
        wield_weapon(OWEAPON"whip3");
        equip_armor(OARMOR"cloth3");
        set( "inquiry", ([
             "box" : "@@ask_box",
             "god" : "@@ask_god",
             ]) );
}

void ask_box(object who)
{
  tell_object(who,
     "\n执事说：哈 ! 你也见到那条黑龙了吗，假如你觉的黑龙宝盒的传说是真的，\n"
         "就去找吧。假如你觉的是假的，就把那条龙的话当做耳边风吧。\n\n"
     ); 
}

void ask_god(object who)
{
  tell_object(who,
     "\n我们这个殿中所供奉的是火神，火神掌管这座火山，每当有火山爆发时，就是火神\n在生气了，所以我们必须祈求火神，希望他不要迁怒於我们。\n\n"
  );
}
