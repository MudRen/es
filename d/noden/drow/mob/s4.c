#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(12);
        set_name("snake","龟壳花" );
        set_short("snake","龟壳花" );
        set_long(
@C_LONG
这是一条美丽的龟壳花，你知道，这是某种名贵的蛇类，并且
含有剧毒，可是还是别碰它的好！
C_LONG
        );
        set( "unit", "条" );
        set( "alignment", -500 );
        set( "natural_weapon_class1", 12 );
        set( "natural_min_damage1", 10 );
        set( "natural_max_damage1", 15 );
        set( "tactic_func", "emit_poison" );
        set_c_limbs( ({ "头部", "身体", "尾巴" }) );
        set_c_verbs( ({ "%s昂头张嘴，往%s咬去" }) );
}

int emit_poison()
{
        object victim;

        if( random(15)>4 || !(victim= query_attacker()) ) return 0;
        tell_room( environment(this_object()),
                "龟壳花用它的尖牙狠狠的向你咬下，你觉得一阵刺痛 ....\n",
                this_object() );
        (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 
25, 9 );
        return 1;
}       
