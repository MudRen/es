#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
        set_name("liu-li bracers", "��������");
        add( "id", ({"bracers","bracer" }) );
        set_short("��������");
        set_long(@C_LONG
һ˫���߲�����ʯ���ɵ�����, ������ս����ɢ����ҫ����Ŀ�Ĺ�â
�ഫ������ĸ��������Ů�񴩴�������
C_LONG
       	);
        set( "unit", "��");
        set( "type", "hands" );
        set( "armor_class", 5 );
        set("material","stone");
        set( "defense_bonus", 3 );
        set( "weight", 50 );
        set( "value", ({ 1800, "silver" }) );
}
