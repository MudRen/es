
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "long blade", "����" );
        add( "id",({ "sword","blade" }) );
        set_short( "long blade", "����" );
        set_long(@AAA
����һ�Ѹո���Ϊ��ʿ�׼��ĵͼ���ʿ�ý�
AAA
        );
        set( "unit", "��");
        set( "weapon_class", 15 );
        set( "type", "longblade" );
//        set( "bleeding", 4 );
        set( "min_damage", 10 );
        set( "max_damage", 18 );
        set( "weight", 120 );
        set( "value", ({ 420, "silver" }) );
}
