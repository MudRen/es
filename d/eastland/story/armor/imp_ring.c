#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("rainbow ring","�߲�������");
        add( "id", ({ "ring" }) );
        set_short( "�߲�������");
        set_long(@C_LONG
һֻ��Ө��͸��ʱ���������������˸���߲ʹ�â�Ľ�ָ���߲��������ǡ�������
������  �������ʱ�Ĵ���ս������Ľ�ָ����������ǿ����ֻ������Ϊ֮��
̾��ϡ�����ߡ�
C_LONG
        );
        set( "unit","ֻ");
        set( "type", "finger" );
        set( "material","element");
        set( "defense_bonus", 6 );
        set( "weight", 10 );
        set( "value", ({ 7500, "silver" }) );
}



