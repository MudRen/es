#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("asbestos net","ʯ����");
        add("id",({"net","cloak"}) );
        set_short("ʯ����");
        set_long(
"����һ��ʯ����������ô��������������������\n"
        );
        set( "unit", "��" );
        set( "weight", 100 );
        set( "type", "cloak" );
        set( "material", "element" );
        set( "armor_class", 6 );
        set( "defense_bonus", 5 );
        set( "value", ({ 1800, "silver" }) );
        set( "no_sale",1);
        set( "special_defense",(["fire":15]));
}
