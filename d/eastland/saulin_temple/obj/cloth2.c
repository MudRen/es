#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("gold pallium","���޼���");
    add("id",({ "cloth", "pallium" }) );
    set_short("���޼���");
	set_long(@C_LONG
����һ�����ϲ�˿��֯�ɲ����Ͻ�ߵļ��ģ��ǵ��궫���۹������ʵ۴͸�
һʮ��λ�й�춵۹�������ҵ���ֲ�Ը�볯Ϊ�ٵ���ɮ֮��
C_LONG
	);
	set( "unit", "��" );
	set( "weight", 90 );
	set( "type", "body" );
        set("material","monk");
	set( "armor_class", 35 );
	set( "defense_bonus", 5 );
	set( "value", ({ 190, "gold" }) );
}
