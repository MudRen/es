#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("bear fur cloth","��Ƥ���ͼ�");
    add("id",({"fur","cloth"}) );
    set_short( "��Ƥ���ͼ�");
	set_long(
		"��������Ƥ�Ƴɵ�ս�ף���ǰ��һ��޴���������ƣ������ط���\n"
		"���͵Ĳ���һ˿��ë��������ֻ����ǰһ���ܿ��£�\n"
	);
	set( "unit", "��" );
	set( "weight", 180 );
	set( "type", "body" );
	set( "armor_class", 26 );
        set("material","leather");
	set( "defense_bonus", 4 );
	set( "value", ({ 175, "gold" }) );
}
