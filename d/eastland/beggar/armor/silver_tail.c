#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "silver tail", "����β��" );
        add( "id", ({ "tail" }) );
        set_short( "����β��" );
        set_long(@C_LONG
һ���������������β�ס��񹤾�ϸ���������൱����
C_LONG
        );
        set( "unit", "��");
        set( "type", "tail" );
        set( "material", "heavy_metal");
        set( "armor_class",3 );
        set( "defense_bonus", 1 );
        set( "weight", 80 );
        set( "value", ({ 350, "gold" }) );
}
