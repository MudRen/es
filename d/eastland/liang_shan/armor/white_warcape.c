#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("white robe","�׶�������");
    add("id",({"robe"}) );
    set_short( "white robe","�׶�������");
	set_long(
		"This is a white silk robe for warriors. \n",
		"������սʿ�ǳ���ʱ����������ܴ��������·����������Ѵﵽ\n"
		"һ����ˮ׼�������ð׶���֯�ɵ����£��侭��ϴ���Կ���Ѫ���߰ߣ�\n"
	);
	set( "unit", "��" );
	set( "weight", 70 );
	set( "type", "body" );
	set( "armor_class", 18 );
        set("material","cloth");
	set( "defense_bonus", 5 );
	set( "value", ({ 63, "gold" }) );
        set( "special_defense",(["none":5,"poison":1]));
}
