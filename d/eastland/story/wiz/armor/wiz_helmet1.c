#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("crown","�ʹ�");
        add( "id", ({ "helmet" }) );
        set_short( set_color("�ʹ�","HIY"));
        set_long(@C_LONG
һ���������Ľ��ɫ�ʹڣ���������������解���˸����ⱦ����
C_LONG
        );
        set( "unit","��");
        set( "type", "head" );
        set( "material","heavy_metal");
        set( "armor_class",7 );
        set( "defense_bonus",1);
        set( "weight", 100 );
        set( "value", ({ 3500, "silver" }) );
}



