#include "../lilia.h"

inherit ARMOR;

void create()
{
        set_name("white cloth","����");
        add("id",({"cloth"}) );
	set_short( "����" );
        set_long(
"����һ����ɫ�Ĳ���\n"
        );
        set( "unit", "��" );
        set( "weight", 80 );
        set( "type", "body" );
        set( "material", "cloth" );
        set( "armor_class", 10 );
        set( "defense_bonus", 2 );
        set( "value", ({ 520, "silver" }) );
}
