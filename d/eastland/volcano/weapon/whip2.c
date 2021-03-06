#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "fire dragon whip", "火龙鞭" );
	add( "id", ({ "whip" }) );
	set_short(  "火龙鞭" );
	set_long(
	  "这是一条火红色火龙鞭，平常是供在右殿，遇到敌人时可拿来对敌，\n"+
	  "充满了一种奇特的魔力。\n"
	);
	set( "unit", "条" );
	set( "weight", 30 );
        set("nosecond",1);
	setup_weapon( "whip", 20, 10,20);
	set( "value", ({ 340, "silver" }) );
//        set( "hit_func", "special_hit" );
        set_verbs(({"%s甩向%s","%s卷向%s","%s挥向%s"}));

}

int special_hit(object victim)
{	
	object holder;
	holder=environment(this_object());
        if( random(holder->query_perm_stat("pie")+
		   holder->query_perm_stat("int"))<20) return 0;
        if( victim->query("stop_attack") ) return 0;

        tell_object( victim,
          "\n火龙鞭快速的舞著，鞭影化成一条火龙向你扑来!!\n\n");
        tell_object( holder, 
          "\n你急速的舞著火龙鞭，鞭影化成一条火龙向敌人扑去 !!\n\n");
        tell_room( environment(holder),
          "\n火龙鞭快速的舞著，鞭影化成一只火龙向" + victim->query("c_name") +"扑去 !!\n\n"
	, ({ victim, holder }));
        victim->receive_special_damage("fire",8+random(10));
        return 1;

}
