#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("cloak of king", "��������");
        add( "id", ({ "cloak" }) );
        set_short( "��������");
        set_long(@C_LONG
����һ���������ߵ�λ�����磬����ӡ��һ���ʹ�ͼ�Ρ�  
C_LONG
        );
        set("unit","��");
        set("type", "cloak" );
        set("material","heavy_metal") ;
        set("armor_class",7);
        set( "defense_bonus",3);
        set("weight", 100 );
        set("value", ({ 310, "gold" }) );
}



