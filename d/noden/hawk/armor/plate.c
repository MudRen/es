inherit ARMOR;

void create()
{
        set_name("heavy plate","���Ϳ���");
        add("id",({"plate"}) );
        set_short( "heavy plate","���Ϳ���");
        set( "no_sale",1);
        set_long(
                "����һ�����������������õĿ��ף���������츳"+
                "�������´����������������ܶ��ޡ�\n" );
        set( "unit", "��" );
        set( "weight", 410 );
        set( "type", "body" );
	set("armor_class", 30 );
        set( "material","heavy_metal");
        set( "defense_bonus", 7 );
        set( "value", ({ 2190, "silver" }) );
        set( "extra_stats",([
                        "con" : -1,"int" : -1,"dex" : -1,
                        "pie" : -1,"kar" : -1,"str" : -1,
                                ]) );

}
