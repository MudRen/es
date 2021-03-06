#include "../story.h"

inherit SMOB"pmob";
void create()
{
	::create();
	set_level(19);
	set_name( "Blue-Face scorpio's head", "人面蓝蝎" );
	add( "id", ({ "head","scorpio" }) );
	set_short( "人面蓝蝎的头部" );
	set_long(@C_LONG
你眼前所见的是只体型巨大无比，全身泛出紫蓝色的蝎子。它的头好像是一个人的
脸，但额前却多凸出两只茶杯大小的怪眼，睁合之间凶芒四射，忽红忽蓝，奇光闪
烁不定。
C_LONG
        );
	set("pname","人面蓝蝎");
	set( "alignment", -1000 );
        set_perm_stat( "str", 25 );
        set_perm_stat( "dex", 30 );
        set_perm_stat( "pie", 10 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "kar", 30 ); 
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set("hit_points",2000);
        set("max_hp",2000);
        set_natural_armor(90,15);
        set_natural_weapon( 61,44,56 );
        set("special_defense", (["all":30,"none":25]) );
        set_c_limbs( ({ "眼睛", "牙齿", "额头", "颈部"}) );
        set_c_verbs( ({ 
            "%s用它的额头猛撞%s",
            "%s用它的牙齿往%s一咬",
            "%s从後面伸出尖锐的毒刺往%s一螫"}) );
}
