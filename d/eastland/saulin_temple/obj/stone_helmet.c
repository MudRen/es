#include "../saulin_temple.h"
inherit ARMOR;

void create()
{
        set_name("stone helmet", "���֮��");
        add( "id", ({ "helmet" }) );
        set_short("���֮��");
        set_long(@C_LONG
����һ����ʯͷ���ɵ�ͷ�����ഫ��Ұ������ΰ���սʿ����ʹ�õĻ��ߡ� 
�������˴�صľ��������Ժ��ص�Ҳ�м��ѵķ������� 
C_LONG
                   );
        set("unit","��");
        set( "type", "head" );
        set( "material", "stone");
        set( "armor_class", 8 );
        set( "defense_bonus", 1 );
        set( "special_defense",
               ([ "fire":3, "cold":-3, "electric":2 ]) );
        set( "weight", 120 );
        set( "value", ({ 80, "gold" }) );
}