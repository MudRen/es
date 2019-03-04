#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(14);
        set_name("cobra", "饭匙倩" );
        set_short("饭匙倩" );
        set_long(
@C_LONG
号称蛇王的饭匙倩，又名眼镜蛇，是蛇类中最毒最凶猛者
依照你对蛇类粗浅的认知，你也明白，不去惹它才是正确
的选择。
C_LONG
        );
        set( "unit", "条" );
        set( "alignment", -730 );
        set( "natural_weapon_class1", 10 );
        set( "natural_min_damage1", 14 );
        set( "natural_max_damage1", 18 );
        set( "tactic_func", "emit_poison" );
        set( "chat_chance",15);
//        set( "chat_output", ({
//                                         });
        set_c_limbs( ({ "头部", "身体", "尾巴" }) );
        set_c_verbs( ({ "%s昂头张嘴，往%s咬去" }) );
}
int emit_poison()
{
        object victim;

        if( random(15)>4 || !(victim= query_attacker()) ) return 0;
        tell_room( environment(this_object()),
                "饭匙倩扬起颈部的大眼，狠狠向你咬下，你觉得一阵刺痛 ....\n",
                this_object() );
        (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 
25, 6 );
        return 1;
}       
