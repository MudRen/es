#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("moon cloak", "Ԫ������");
        add( "id", ({ "cloak" }) );
        set_short( "Ԫ������");
        set_long(@C_LONG
����һ���Ĵ�Ķ��Ԫ�������Ƕ������ǧ�꺮��֮�¶��Ƴɵ�,��һ���֮��
ֻ������һ��, ��˵������ޱȡ���������ϻ����������ߵ���������,��������
ϵ��������ò�����һ�������ˡ�
C_LONG
        );
        set("unit","��");
        set( "type", "cloak" );
        set("material","cloth") ;
        set( "armor_class", 7 );
        set( "defense_bonus",6 );
        set("special_defense",(["cold":5]) );
        set( "weight", 50 );
        set( "value", ({ 110, "gold" }) );
}



