#include <mudlib.h>

inherit ARMOR;
 
void create()
{
        set_name("Green bracelet", "��������");
        add( "id", ({"bracelet" }) );
        set_short("@@looks");
        set_long(
                "����һ������ɫ�Ĵ������ӣ���Լ������ǳǳ�Ĺ�â��\n"
        );
        set( "unit", "��");
        set( "type", "arms" );
        set( "material", "element" );
        set( "defense_bonus",4 );
        set( "armor_class",4 );
        set( "weight", 20 );
        set( "value", ({ 123, "gold" }) );
        set( "special_defense", ([ "none" : 5 ]) );
        set( "no_sale",1);
}

string looks()
{
	return set_color("��������","GRN");
}