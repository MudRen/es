#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
        set_name("black bracers", "�ڡ�����");
        add( "id", ({"bracers","bracer" }) );
        set_short("�ڡ�����");
        set_long(
"һ˫�ɺڡ��ҵ�ʯͷ�����ɵ��ֻ�, ���԰�������ս���ж��ʤ����\n"
        );
        set( "unit", "˫");
        set( "type", "hands" );
        set("material","stone");
        set( "armor_class", 3 );
        set( "defense_bonus", 4 );
        set( "weight", 60 );
        set( "value", ({ 1500, "silver" }) );
}
