#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("Golden Necklace","�������");
        add("id",({"necklace"}) );
        set_short("�������");
        set_long(
"����һ�����൱�ֵĽ��Ӵ�������͵����,����Ӧ��ֵ����Ǯ���ǡ�\n"
        );
        set( "unit", "��" );
        set( "weight", 50 );
        set( "type", "misc" );
        set( "material", "light_metal" );
        set( "armor_class", 0 );
        set( "defense_bonus", 5 );
        set( "special_denense", (["fire":10]));
        set( "value", ({ 2300, "silver" }) );
        set( "no_sale", 1 );
}
