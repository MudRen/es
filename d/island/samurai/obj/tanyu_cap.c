#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu cap", "����ͷ��");
        add( "id", ({ "cap" }) );
        set_short("tanyu cap", "����ͷ��");
        set_long(@AAA
�������������е�ͷ��
AAA
        );
        set( "unit", "��"); 
        set( "type", "head" );
        set( "armor_class", 7 );
        set( "defense_bonus", 3 );
        set("material","cloth");
        set( "weight", 30 );
        set( "value", ({ 600, "silver" }) );
}
