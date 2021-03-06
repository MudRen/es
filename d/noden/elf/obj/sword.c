
#include <mudlib.h>
inherit WEAPON;

void create()
{
   set_name( "ether-genius sword", "以太精灵剑" );
        add( "id",({ "sword", "longsword" }) );
   set_short( "以太精灵剑" );
        set_long(
            "这是精灵王所使用的长剑，它的表面因沾满了敌人的鲜血，而呈现暗红色\n"
         "的斑纹, 但它的剑刃依旧锋利, 可见它是一把好武器。但只有战绩彪炳的人\n"
         "才能充份发挥其潜在的威力。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 42 );
        set( "type", "longblade" );
   set( "min_damage", 22 );
   set( "max_damage", 50 );
        set( "nosecond",1);
        set( "weight", 210 );
        set( "value", ({ 1000, "gold" }) );
   set( "hit_func", "weapon_hit" );
}

int weapon_hit(object victim, int damage)
{
   object owner;
   int myscore;

   owner = environment();
   myscore = owner->query( "war_score" );

   if( myscore < 50000 ) return 0;
   if( myscore > 500000 ) myscore = 500000;
// 公爵以上才能引出特殊攻击。
// 最高伤害 50。
   if( random(20) > 2 ) return 0;
   tell_object( owner,
"\n你手中的以太精灵剑尖聚集了一股奇异的光芒射向"+victim->query("c_name")+"\n" );
   tell_object( victim,
"\n"+owner->query("c_name")+"手中的以太精灵剑尖突然产生一股奇异的光芒射向你!\n" );
   tell_room( environment(owner),
   owner->query("c_name")+"手中的以太精灵剑上突然有一股光芒射向"+victim->query("c_name")+"!\n", ({ owner, victim }) );
   victim->receive_special_damage( "energy", myscore/10000 );
   return myscore/10000;
}
