inherit ARMOR;

void create()
{
        set_name("Strange shield", "��ֵĶ���");
        add( "id", ({ "shield" }) );
        set_short( "��ֵĶ���") ;
	set_long("����һֻ���ι�״�Ķ��ơ�\n");
        set("unit","ֻ");
        set( "type", "shield" );
        set( "material", "heavy_metal");
        set( "armor_class", 4 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "magic":5 ]) );
        set( "no_sell",1);
        set( "weight", 100 );
        set( "value", ({ 300, "gold" }) );
}
