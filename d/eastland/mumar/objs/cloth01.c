#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("golden cloth","��������");
        add("id",({"cloth"}) );
        set_short("��������");
        set_long(
"����һ���������͵Ľ����£�����������Ƭ�ý�˿���ɵġ�\n"
        );
        set( "unit", "��" );
        set( "weight",180 );
        set( "type", "body" );
        set( "material", "light_metal" );
        set( "armor_class", 29 );
        set( "defense_bonus", 7 );
        set( "special_defense",(["fire":10,"cold":-5,"evil":5,"none":1]) );
        set( "value", ({ 3000, "silver" }) );
        set( "no_sale",1);
}
