#include "../../layuter.h"
inherit ARMOR;

void create()
{
        set_name("jade chainmail", "������");
        add( "id", ({ "mail","chainmail" }) );
        set_short("������");
        set_long(
                "����һ��������Ƴɵġ��׿�����ʮ�ֻ�����\n"
        );
        set("unit","��");
        set( "type", "body" );
        set( "material", "element" );
        set( "armor_class", 28 );
        set( "defense_bonus", 4 );
        set( "special_defense", ([ "divine" :5, "magic":-7 ]) );
        set( "weight", 200 );
        set( "value", ({ 200, "gold" }) );
}