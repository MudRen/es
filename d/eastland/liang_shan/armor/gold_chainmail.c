#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("gold chainmail","���ӻƽ��");
    add("id",({"chainmail","mail"}) );
    set_short( "gold chainmail","���ӻƽ��");
	set_long(
		"This is a suit of chainmail made of gold meterial.\n",
		"����һ����������ġ���,�ഫ�ǵ��������ʥ��װ��֮һ����Ȼ��\n"
		"�ǻƽ��Ƴɣ�����֪Ϊ�ηǳ������ɣ�\n"
	);
    set( "no_sale",1);
	set( "unit", "��" );
	set( "weight", 130 );
	set( "type", "body" );
	set( "armor_class", 40 );
        set("material","heavy_metal");
	set( "defense_bonus", 5 );
	set( "value", ({ 290, "gold" }) );
}
