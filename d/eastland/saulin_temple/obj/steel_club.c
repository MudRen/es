#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "steel club", "������");
        add ("id",({ "club"}) );
        set_short("������");
        set("unit", "��");
        set_long(@C_LONG
����һ���ɻ���������İ��ӣ���������������ӡ�
C_LONG
        );
        set( "weapon_class", 16);
        set( "type", "bo");                        
        set( "min_damage", 10);
        set( "max_damage", 18);
        set( "weight", 160);
        set( "value", ({ 380, "silver" }) );
}
