#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("iron plate","����������");
    add("id",({"plate","mail"}) );
    set_short( "iron plate","����������");
	set_long(
		"This is a suit of mail made of iron meterial.\n",
		"����һ�������ɾɵĽ�������У���Ȼ�����Զ��������ã�\n"
		"��������Ȼ�����ϳ���ս��\n"
	);
	set( "unit", "��" );
	set( "weight", 180 );
	set( "type", "body" );
	set( "armor_class", 25 );
        set("material","heavy_metal");
	set( "defense_bonus", 4 );
	set( "value", ({ 166, "gold" }) );
}
