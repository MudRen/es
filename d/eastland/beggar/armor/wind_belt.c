#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name( "wind belt", "��������" );
        add( "id", ({ "wind","belt" }) );
        set_short( "��������" );
        set_long(@C_LONG
��������������Ȼ��˿��֯���ɵ�,��������һ��Ƭ������֮������Ϊ����������
��������������˷���ȥ�������Ƴɸ�����, �������Ե���޼�֮��,��Ȼ����ʶ
�������ʽ�,������˷�����Ҳ���ϸ��       
C_LONG
        );
        set( "unit", "��");
        set( "type", "legs" );
        set( "material", "cloth");
        set( "armor_class", 7 );
        set( "defense_bonus", 3 );
        set( "weight", 50 );
        set( "value", ({ 150, "gold" }) );
}
