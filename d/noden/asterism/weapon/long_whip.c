
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("long whip","����");
        add ("id",({ "whip" }) );
        set_short("����");
        set_long(
            "����һ���ܳ��ı��ӡ���ϸһ��, ����ʲ�Ứ�ƶ�û�С�\n"
        );
        set( "unit", "��");
        set( "weapon_class", 20 );
        set( "type", "whip" );
        set( "min_damage", 17);
        set( "max_damage", 19 );
        set( "weight", 110 );
        set( "value", ({ 840, "silver" }) );
}

