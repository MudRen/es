#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "knout", "Ƥ��");
        add ("id",({ "knout"}) );
        set_short("Ƥ��");
        set("unit", "��");
        set_long(
            "����һ��Ƥ�ޣ�����Ѫ���߰ߣ���ش���ܶ��ˡ�\n"
        );
        set( "weapon_class", 10 );
        set( "type", "whip" );                        
        set( "min_damage", 10);
        set( "max_damage", 16);
        set( "weight", 45 );
        set( "value", ({ 350, "silver" }) );
        set_c_verbs(({"%s����%s","%s����%s","%s����%s"}));
}
