#include "../dony.h"

inherit ARMOR;
 
void create()
{
        set_name( "saddle", "����" );
        add( "id", ({ "saddle" }) );
        set_short( "����" );
        set_long(@C_LONG
һ���������õ���, ����ú�������������������װ�������� ?        
C_LONG
        );
        set( "type", "saddle" );
        set( "material", "leather" );
        set( "armor_class", 3 );
        set( "defense_bonus", 5 );
        set( "weight", 100 );
        set( "value", ({ 100, "silver" }) );
}
