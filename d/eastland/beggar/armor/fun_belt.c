#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "eight belt", "����������" );
        add( "id", ({ "belt" }) );
        set_short( "����������" );
        set_long(@C_LONG
һ����������ͼ�ε�������
C_LONG
        );
        set( "unit", "��");
        set( "type", "legs" );
        set( "material", "cloth");
        set( "armor_class", 3 );
        set( "defense_bonus", 1 );
        set( "weight", 50 );
        set("special_defense",(["magic":15,"evil":-20]) );
        set( "value", ({ 150, "gold" }) );
}
