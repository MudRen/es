#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "king-kong staff", "�����");
        add ("id",({ "staff"}) );
        set_short( "king-kong staff", "�����");
        set("unit", "��");
        set_long(
            "",@C_LONG
��ѽ����������û�й��󣬻�����һ�ɱ��˵ĺ�����������ʮ�����أ�
��˵����ǧ������������ɡ�
C_LONG
        );
        set( "weapon_class", 35);
        set( "type", "blunt");
        set( "min_damage", 25);
        set( "max_damage", 43);
        set( "no_sale", 1);
        set( "weight",180 );
        set( "value", ({ 180, "silver" }) );
}
