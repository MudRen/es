#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("sun helmet", "����ͷ��");
        add( "id", ({ "helmet" }) );
        set_short( "����ͷ��");
        set_long(@C_LONG
����ͷ������һ������Ĳ���,Ȼ�ᾭ����������ġ������ɵ�, �ƳɵĻ��ʿ�˵
��ǧ��֮һ������֮��,�����������߻���Ԫ������, ������������ϵ��������
�ò�����һ�������ˡ�
C_LONG
        );
        set("unit","��");
        set( "type", "head" );
        set("material","cloth") ;
        set( "armor_class",7 );
        set( "defense_bonus", 5 );
        set( "weight", 40 );
        set( "value", ({ 60, "gold" }) );
        set("special_defense",
                     (["fire":5]) );
}



