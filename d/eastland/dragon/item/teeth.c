
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Chilin teeth", "������" );
        add( "id",({ "teeth", "shortsword" }) );
        set_short( "������" );
        set_long("�������뾭����ǧ��ʱ���ݻ����ĳ�������\n");
        set( "unit", "��");
        set( "weapon_class", 44 );
        set( "type", "longblade" );
        set( "min_damage", 20 );
        set( "max_damage", 33 );
        set( "weight", 180 );
        set( "value", ({ 400, "gold" }) );
}

