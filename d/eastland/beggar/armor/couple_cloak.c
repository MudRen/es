#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("cloak of couples", "������");
        add( "id", ({ "cloak" }) );
        set_short( "������");
        set_long(@C_LONG
������������ɽ���ϲɼ�ʮͷ���ܵ�Ƥ���Ƴɵġ� �ɶ���֮һ���ö��ĺ�������
��Ϳ��һ�㱡������ҩ�������±����¶�, ������Դ��������Ӵ!!
C_LONG
        );
        set("unit","��");
        set( "type", "cloak" );
        set("material","leather") ;
        set( "armor_class", 5 );
        set( "defense_bonus",2 );
        set("special_defense",
              (["poison":10]) );
        set( "weight", 90 );
        set( "value", ({ 100, "gold" }) );
}



