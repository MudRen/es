#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "chilin whip", "麒麟鞭" );
	add( "id", ({ "whip" }) );
	set_short( "麒麟鞭" );
	set_long(
	  "这是一条火红色麒麟鞭，平常是供在左殿，遇到敌人时可拿来对敌，\n"+
	  "充满了一种奇特的魔力。\n"
	);
	set( "unit", "条" );
	set( "weight", 30 );
        set("nosecond",1);
	setup_weapon( "whip", 20, 9,18);
	set( "value", ({ 320, "silver" }) );
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
          "\n麒麟鞭快速的舞著，鞭影似化成一只火麒麟向你扑来!!\n\n");
        tell_object( holder, 
          "\n你急速的舞著麒麟鞭，鞭影化成一只火麒麟向敌人扑去 !!\n\n");
        tell_room( environment(holder),
          "\n麒麟鞭快速的舞著，鞭影似化成一只火麒麟向" + victim->query("c_name") +"扑去 !!\n\n"
	, ({ victim, holder }));
        victim->receive_special_damage("fire",5+random(10));
        return 1;

}
