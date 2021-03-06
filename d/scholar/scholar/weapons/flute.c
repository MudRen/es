#include <mudlib.h>

inherit WEAPON;

void create()
{
   set_name( "old_jade flute", "古玉箫" );
   add("id", ({"flute"}) );
   set_short( "古玉箫" );
   set_long(
     "这是一只由汉代古玉所雕成的玉箫，玉箫上面布满龙形花纹，另外还有用\n"
     "篆文刻著几个小字：『安邦定国』，据说这是当今皇帝所御赐的东西。\n" );
   set( "unit", "只" );
   set( "type", "longblade" );
   set( "hit_func", "weapon_hit" );
   set( "weight", 50 );
   set( "weapon_class", 35 );
   set( "no_sale", 1 );
   set( "min_damage", 20 );
   set( "max_damage", 36 );
   set( "value", ({ 2000, "silver" }) );
   set( "no_sale", 1 );
}

int weapon_hit( object victim, int damage )
{
   object owner;
   int inte, intv, fp;

   owner = environment();
   inte = owner->query_stat("int");
   fp = owner->query("force_points");
   if (!((string)owner->query("class")=="scholar")){
     tell_object( owner,
     "\n你手中的玉箫发出一阵音波：哈哈 ! 你不配做我的主人。\n\n");
     owner->receive_special_damage("energy",inte/2);
     return 0;
   }
   if (!victim) return 0;
   intv = victim->query_stat("int");
   if( random(inte*3)>(intv*2) && fp >2 ) {
       tell_object( owner,
       "\n你将一阵内力贯输於玉箫, 管中突然发出一阵音波向"+victim->query("c_name")+"射去\n\n" );
       tell_object( victim,
     "\n" +
          owner->query("c_name") + "的玉箫突然发出一阵音波向你袭来!\n\n" );
       tell_room( environment(owner),
     "\n" +
         owner->query("c_name") + "的玉箫突然向" + victim->query("c_name") + "射出一阵音波!\n\n"
         , ({ victim, owner }) );
       victim->receive_special_damage( "energy", inte/2 );
          owner->add( "force_points", -3 );
          return inte/2;
	}
}
