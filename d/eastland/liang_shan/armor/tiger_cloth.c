#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("tiger fur cloth","��Ƥ����");
    add("id",({"fur","cloth"}) );
    set_short( "tiger fur cloth","��Ƥ����");
	set_long(
		"This is a cloth made of fur of tiger\n",
		"�����û�Ƥ�Ƴɵ�������÷ǳ�����ʵ�޻������ܱ��壮\n"
	);
	set( "unit", "��" );
	set( "weight", 160 );
	set( "type", "body" );
	set( "armor_class", 24 );
        set("material","leather");
	set( "defense_bonus", 3 );
	set( "value", ({ 75, "gold" }) );
        set( "special_defense",(["none":8]));
}
