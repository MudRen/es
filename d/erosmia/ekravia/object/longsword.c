#include "../ekravia.h"

inherit WEAPON;

void create()
{
        set_name( "longsword", "����" );
        add( "id",({ "sword", "longsword" }) );
        set_short( "����" );
        set_long( @CLONG
һ����ͨ�ĳ���, ����ÿ���ط����������������������
CLONG
        );
        set( "unit", "��");
        set( "weapon_class", 25 );
        set( "type", "longblade" );
        set( "min_damage", 12 );
        set( "max_damage", 24 );
        set( "nosecond",1);
        set( "weight", 160 );
        set( "value", ({ 600, "silver" }) );
}
