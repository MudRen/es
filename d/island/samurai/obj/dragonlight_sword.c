
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "dragonlight sword","��������");
        add( "id",({ "dragonlight","sword" }) );
        set_short( "dragonlight sword","��������" );
        set_long(@AAA
����һ�������ı���������壬����ʿ���е�ٮٮ��Լ�˵�����
AAA
        );
        set( "unit", "��");
        set( "weapon_class", 30 );
        set( "type", "longblade" );
        set( "min_damage", 15 );
        set( "max_damage", 32 );
        set( "weight", 170 );
        set( "value", ({ 1030, "silver" }) );
}



