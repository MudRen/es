#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("sable skin","��Ƥ");
        add("id",({"skin","cloak"}) );
        set_short("��Ƥ");
        set_long(
"����һ��Ƥ�ݣ���˵���Է������ꡣ\n"
        );
        set( "unit", "��" );
        set( "weight",70 );
        set( "type", "cloak" );
        set( "material", "leather" );
        set( "armor_class", 6 );
        set( "defense_bonus", 5 );
        set( "value", ({ 1800, "silver" }) );
        set( "no_sale",1);
        set( "special_defense",(["cold":15]));
}
