#include <mudlib.h>

inherit WEAPON;
void create()
{
        set_name( "copper sword","ͭ��");
        add( "id",({ "sword" }) );
        set_short( "ͭ��");
        set_long(
@CLONG
���ǰ��ɴ�ͭ������ĳ������ձ���������ɫ��ͭ���ڡ�
CLONG
                );
        set( "unit", "��" );
        set( "weapon_class", 18 );
        set( "type", "longblade" );
        set( "min_damage", 17 );
        set( "max_damage", 23 );
        set( "weight", 110 );
        set( "value", ({ 300, "silver" }) );
}
