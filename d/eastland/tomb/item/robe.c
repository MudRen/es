#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("emperor robe","����");
        add("id",({"robe"}) );
        set_short("����");
	set_long(
"���Ƕ����ʵ۵����ۣ���������һֻ������\n");
	set( "unit", "��" );
	set( "weight", 135 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 30 );
	set( "defense_bonus", 5 );
	set( "no_sale", 1 );
	set( "prevent_insert", 1 );
	set( "value", ({ 1000, "gold" }) );
}
