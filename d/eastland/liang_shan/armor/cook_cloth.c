#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("cook cloth","����ĳ�ʦ��");
    add("id",({"cloth"}) );
    set_short( "cook cloth","����ĳ�ʦ��");
	set_long(
		"???\n",
		"����һ������������ĳ�ʦ������,ɢ����һ������֮��ζ\n"
	);
    set( "no_sale",1);
	set( "unit", "��" );
	set( "weight", 180 );
	set( "type", "body" );
	set( "armor_class", 25 );
        set("material","cloth");
	set( "defense_bonus", 3 );
	set( "value", ({ 140, "gold" }) );
}
