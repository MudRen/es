
#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "iron claws", "铁爪");
        add ("id",({ "claws"}) );
        set_short( "铁爪");
        set("unit", "对");
        set_long(
            "这是一对可以装在手上的利爪，虽然看起来不起眼，但泛蓝的爪刃却有著异样的光彩\n"
        );
        set( "weapon_class", 10 );
        set( "type", "unarmed" );
        set( "min_damage", 8);
        set( "max_damage", 16);
	set("wield_func","wield_claws");
	set("unwield_func","unwield_claws");
        set( "weight", 55 );
	set("nosecond",1);
        set_c_verbs(({"%s刺向%s","%s抓向%s","%s挥向%s"}));
        set( "value", ({ 180, "silver" }) );
}

void unwield_claws()
{
	object owner;
	owner = environment(this_object());
 if (query("form"))
	{
        set( "weapon_class", 10 );
        set( "min_damage", 8);
        set( "max_damage", 16);
		set("prevent_drop",0);
        tell_room( environment(owner), 
        	owner->query("c_name")+"的黄金爪光芒退去，变回原来的样子。\n"
			, ({ owner }) );
        tell_object( owner, 
         "你的黄金爪奇光敛去，自动与你的手分离。\n");

        set_name( "iron claws", "铁爪");
        set_short( "铁爪");
		set("form",0);
		return ;
	}
	return ;
}

void wield_claws()
{
	int st,iq,dx,kr,i,j;
	object owner;
	owner = environment(this_object());
	if ( (string)owner->query("class")=="adventurer")
	{
	st=owner->query_perm_stat("str");
        iq=owner->query_perm_stat("int");
        dx=owner->query_perm_stat("dex");
        kr=owner->query_perm_stat("kar");
	i = (st+dx+iq+kr)/3+random(6);
	j = ((int)owner->query_skill("unarmed"))/2 ;
        set( "weapon_class", ( j > 40 ? 40 : j ) );
        set( "min_damage", ( i<11 ? i : i-10 ));
        set( "max_damage", i);
	set("no_sale",1);
	set("prevent_drop",1);
        tell_room( environment(owner), 
         owner->query("c_name")+"的铁爪发出一阵光芒，与他的手结合，变成他身体的一部份。\n"
	, ({ owner }) );
        tell_object( owner, 
	      "你的铁爪泛出一片奇光，自动与你的手紧密结合。\n");
        set_name( "golden claws", "黄金爪");
        set_short( "黄金爪");
	set("form",1);
		return ;
	}
        return ;
}
