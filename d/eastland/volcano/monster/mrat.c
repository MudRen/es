#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name( "mountain rat", "山老鼠" );
	add( "id", ({ "rat" }) );
	set_short( "山老鼠" );
	set_long(
		"这只山老鼠正在这里找东西吃。\n"
	);
	set_perm_stat("dex", 9 );
	set_perm_stat("str", 10 );
	set_skill( "dodge", 50 );
        set("chat_chance",10);
        set("chat_output",({
            "老鼠吱的一声，从你的前面跑过。\n"
           }) );
	set_c_verbs( ({ "%s用爪子乱抓%s", "%s张嘴往%s咬下",
		"%s抬起後腿，踢向%s", "%s向前猛窜，用爪子在%s乱挖" }) );
	set_c_limbs( ({ "头部", "身体", "前爪", "後腿", "尾巴" }) );

	set( "unit", "只" );
	set_natural_armor( 25,7 );
	set( "natural_weapon_class1", 2 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 5 );
	set( "max_hp", 160 );
	set( "hit_points", 160 );
#include <../replace_mob.h>
}
