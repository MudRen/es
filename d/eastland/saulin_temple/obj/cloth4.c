#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("silver pallium","���Ҳ���");
    add("id",({"cloth","pallium"}) );
    set_short("���Ҳ���");
	set_long(@C_LONG
����һ���������µĲ���, �ûҲ�֯�ɵĲ���������, ֻ�м�λ��
���ߵĺ������ʸ���, �����������б�ʹ��, ��������һ���Ϻ�
��޹��ζ !
C_LONG
	);
	set( "unit", "��" );
	set( "weight", 90 );
        set("material","monk");
	set( "type", "body" );
	set( "armor_class", 19 );
	set( "defense_bonus", 4 );
	set( "value", ({ 1691, "silver" }) );
}
