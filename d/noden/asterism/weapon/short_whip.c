
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("Short whip","�̱�");
        add ("id",({ "whip" }) );
        set_short("�̱�");
        set_long(
            "����һ��ѱ��ʦ�õĶ̱ޣ���Ϊ�����������Ӳ���ͬһ���հѣ�\n"
            "���Դ������ر�ʹ��"
        );
        set( "unit", "��");
        set( "weapon_class", 25 );
        set( "type", "whip" );
        set( "min_damage", 18);
        set( "max_damage", 25 );
        set( "weight", 80 );
        set( "value", ({ 840, "silver" }) );
}

