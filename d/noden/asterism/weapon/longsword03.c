
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("Silver longsword", "����");
        add ("id",({ "sword" }) );
        set_short("����");
        set_long(
            "�������ƵĽ����ԹŴ�������Ʒ����������ʥ��������\n"
        );
        set( "unit", "��");
        set( "weapon_class", 27 );
        set( "type", "longblade" );
        set( "min_damage", 20);
        set( "max_damage", 29 );
        set( "weight", 160 );
        set( "value", ({ 2500, "silver" }) );
}

