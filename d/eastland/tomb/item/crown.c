#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "emperor crown", "�ʹ�" );
        add( "id", ({ "crown", }) );
        set_short( "�ʹ�");
        set_long( 
@C_LONG
һ���ʹڣ��Ƕ����ʵ������õġ�
C_LONG
        );
        set( "unit", "��" );
        set( "weight", 50 );
        set( "type", "head" );
        set( "material", "light_metal" );
        set( "armor_class", 8 );
        set( "defense_bonus", 3 );
        set( "no_sale", 1 );
        set( "prevent_insert", 1 );
        set( "value", ({ 1000, "gold" }) );
}
