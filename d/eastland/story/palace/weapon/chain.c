#include <mudlib.h>
inherit WEAPON;

void create()
{
    set_name("Wolf chain","������");
    add("id", ({ "chain" }) );
    set_short("������");
    set_long(@C_LONG
һ���ɳ���������ǰ�˿���һ������������ͷ��������צ���ɲ��Ѽ���
C_LONG
    );
    set( "unit", "��" );
    setup_weapon("chain", 30,15,23);
    set( "weight",100);
    set( "value", ({ 1500, "silver" }) );
}

