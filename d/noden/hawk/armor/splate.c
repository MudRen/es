inherit ARMOR;

void create()
{
        set_name("sky plate","天空之铠");
        add("id",({"plate"}) );
        set_long(@LONG
这是天空之城自古相传的铠甲，由天空之城所独有的奇里斯金属所打造，外加
上天界神圣的力量加诸其上，因此成为史上最强大的防具之一。\n"
LONG
        );
        set_short( "sky plate","天空之铠");
        set( "no_sale",1);
        set( "unit", "件" );
        set( "weight", 140 );
        set( "type", "body" );
	set( "armor_class", 31 );
        set("material","light_metal");
        set( "defense_bonus", 6 ); // 希望能高一点 *因为是轻金属 ac 不大高*
	set("special_defese",(["cold" :10 ,"fire" : -20," electric": 10 ]) );
        set( "value", ({ 290, "silver" }) );
}
