#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("quaspect robe","��������");
        add("id",({"robe"}) );
        set_short("��������");
        set_long(
"�������ۣ�������������һ�����ۡ�\n"
        );
        set( "unit", "��" );
        set( "weight", 150 );
        set( "type", "body" );
        set( "material", "cloth" );
        set( "armor_class", 20 );
        set( "defense_bonus", 5 );
        set( "value", ({ 2000, "silver" }) );
        set( "no_sale",1);
}
