#include <mudlib.h>
inherit WEAPON;
void create()
{
        set_name("phoenix topknot", "��ͷ��");
        add( "id", ({ "topknot" }) );
        set_short("��ͷ��");
        set_long(
                "�������ϵ��͸�������Ķ���֮��, ������һֻ�ܾ��µķ�ˡ�\n"
        );
        set("unit","֧");
        set( "type", "dagger" );
        set( "weapon_class",35);
        set( "min_damage", 15);
        set( "max_damage",30);
        set( "weight", 30 );
        set( "value", ({ 450, "gold" }) );
}



