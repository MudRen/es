#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "fencing clothes", "�������� ");
        add( "id", ({ "cloth","clothes" }) );
        set_short("fencing clothes", "��������");
        set_long(@AAA
һ���������������ĵ��������ú��鲼��֯�ɣ�ӵ�в���ķ�����
AAA
        );
        set( "unit", "��"); 
        set( "type", "body" );
        set( "armor_class", 20 );
        set( "defense_bonus", 2 );
        set("material","cloth");
        set( "weight", 130 );
        set( "value", ({ 600, "silver
        " }) );
}
