#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("wind helmet", "����ͷ��");
        add( "id", ({ "helmet" }) );
        set_short( "����ͷ��");
        set_long(@C_LONG
����ͷ��������˷���������Ȼ��˿���ƶ��ɵġ�����˷����İ���ͷ����
C_LONG
        );
        set("unit","��");
        set( "type", "head" );
        set("material","cloth") ;
        set( "armor_class", 7 );
        set( "defense_bonus", 1 );
        set( "weight", 40 );
        set( "value", ({ 200, "gold" }) );
}



