inherit ARMOR;

void create()
{
        set_name("sky shield","���֮��");
        add("id",({"shield"}) );
        set_long(@LONG
��Ѷ������ηǳ����죬��һֻ�ͻ�����Ҫ�������һ�������������
���Ʋ������Գ䵱���ߣ������Ż����˵�Ч��ࡡ�
LONG
        );
        set_short( "sky plate","���֮��");
        set( "no_sale",1);
        set( "unit", "��" );
        set( "weight", 100 );
        set( "type", "shield" );
        set( "armor_class", 6 );
        set("material","light_metal");
        set( "defense_bonus", 6 );
        set( "value", ({ 720, "silver" }) );
}
