inherit ARMOR;

void create()
{
        set_name("Purple shield", "紫辉盾牌");
        add( "id", ({ "shield" }) );
        set_short( "紫辉盾牌") ;
        set_long(@LONG 
这是一只紫色的盾牌，上面绘有火焰的图样，看起来似乎带有
一些神秘的力量。
LONG
	);
	set("unit","面");
        set( "type", "shield" );
	
        set( "material", "light_metal");
        set( "armor_class", 8 );
        set( "defense_bonus", 2 );
        set( "special_defense",
		([ "devine":-10, "fire":10, "evil":-10,
		"cold":-15,"electric":15 ]) );

        set( "weight", 100 );
        set( "value", ({ 300, "gold" }) );
}
