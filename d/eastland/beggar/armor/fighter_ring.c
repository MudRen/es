#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("fighter's ring","������֮��");
        add( "id", ({ "ring" }) );
        set_short( "������֮��");
        set_long(@C_LONG
���ǰ������Ĵ���ս��ʱ������Ľ�ָ����˵���ָ�����й�ǿ���ħ��������һ
�������޵�����ף��,����Ǽ���а����˴�����,���кܺõķ�����
C_LONG
        );
        set("unit","ֻ");
        set( "type", "finger" );
        set("material","cloth");
        set( "armor_class", 0 );
        set( "defense_bonus", 5 );
        set( "weight", 10 );
        set( "value", ({ 300, "gold" }) );
        set("special_defense",
                     (["evil":5]) );
                     
}



