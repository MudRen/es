#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
        set_name("king-kong bracers", "��ջ�");
        add( "id", ({"bracers","bracer" }) );
        set_short("��ջ�");
        set_long(@C_LONG
һ˫�����ֽ�� (�ı��������) �ӳֹ���ʯ�ֻ�,
�ӳ��Լ���֮�﷨���԰������һ�е������ϡ�
C_LONG
                );
        set( "unit", "˫");
        set( "type", "hands" );
        set("material","stone");
        set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "weight", 70 );
        set( "value", ({ 1500, "silver" }) );
}
