#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu cloth", "����ս��");
        add( "id", ({ "cloth","clothes" }) );
        set_short("tanyu cap", "����ս��");
        set_long(@AAA
�������������е�ս��װ���в���ķ�����
AAA
        );
        set( "unit", "��"); 
        set( "type", "body" );
        set( "armor_class", 25 );
        set( "defense_bonus", 4 );
        set("material","light_metal");
        set( "weight", 130 );
        set( "value", ({ 700, "silver" }) );
}
