
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "fish sword", "�������" );
        add( "id",({ "fish","sword" }) );
        set_short( "fish sword", "�������" );
        set_long(@ANGEL
����һ�������Ĺŵ����,�����ϻ�����һֻ���ͼ��
ANGEL
        );
        set( "unit", "��");
        set( "weapon_class", 26 );
        set( "type", "longblade" );
        set( "min_damage", 15 );
        set( "max_damage", 26 );
        set( "weight", 170 );
        set( "value", ({ 1120, "silver" }) );
}
