#include "../forest.h"

inherit WEAPON;

void create()
{
        set_name( "sharp blade", "��" );
        add( "id",({ "blade", "sharp blade" }) );
        set_short( "�����Ĵ�" );
        set_long( @CLONG
����һ���൱�����Ĵ�, �׻λε���������, ���˸��ܵ�һ��һ��
�ʾ����Ѫ�İ�����
CLONG
        );
        set( "unit", "��");
        set( "weapon_class", 18 );
        set( "type", "longblade" );
        set( "min_damage", 8 );
        set( "max_damage", 18 );
        set( "nosecond",1);
        set( "weight", 141 );
        set( "value", ({ 350, "silver" }) );
}
