#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "Dragon sword", "龙剑" );
	add( "id", ({ "sword", "dragon sword" }) );
	set_short( "龙剑" );
	set_long(
   "这是一把用海底精铁粹炼百年再滴上龙血所铸成之剑，是井龙王的必胜武器。\n" );
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "hit_func", "weapon_hit" );
	set( "weight", 200 );
	set( "weapon_class", 45 );
	set( "min_damage", 30 );
	set( "max_damage", 50 );
        set( "special_damage", 40 );
	set( "value", ({ 500, "gold" }) );
	set( "no_sale", 1 );
}

int weapon_hit( object victim, int damage )
{
	object owner;
        int my_pie,vic_pie,sp,dam;

	owner = environment();
        sp=owner->query("spell_points");
        if ( sp < 6 ) return 0;
        my_pie = (int)owner->query_stat("pie");
        vic_pie =(int)victim->query_stat("pie");
        if( random(my_pie*3) < vic_pie*2 ) return 0;
        if( !(dam = (int)query("special_damage")) ) return 0;
        owner->set("spell_points",sp-6);
        if ((int)owner->query_skill("longblade")<95) {
          tell_object(owner,
              "\n你勉强挥动龙剑剑光所幻成的冰龙反蚀了自己.\n\n");
          tell_room(environment(owner),
              "\n"+owner->query("c_name")+"的龙剑剑光所幻成的冰龙反蚀了自己
.\n\n",
              owner );
          owner->receive_special_damage("cold",dam);
          return dam;
        }

          tell_object(owner,
           "\n你的龙剑挥出一道剑光，幻成一条冰龙向你的敌人扑去。\n\n");
          tell_room(environment(owner),
            "\n"+owner->query("c_name")+"的龙剑挥出一道剑光，幻成一条冰龙向敌人扑去。\n\n" 
            , owner );
           victim->receive_special_damage("cold",dam);
           return dam; 
}
