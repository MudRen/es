#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("Octrophet Shoes","������Ь");
        add("id",({"shoes","boots"}) );
        set_short("������Ь");
        set_long(
"����һ˫Ьͷ�ϰ���һ�����Ե�Ь�ӡ�\n"
        );
        set( "unit", "˫" );
        set( "weight",80 );
        set( "type", "feet" );
        set( "material", "cloth" );
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "value", ({ 2000, "silver" }) );
        set( "no_sale",1);
}
