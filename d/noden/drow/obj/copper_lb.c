#include <mudlib.h>

inherit WEAPON;
void create()
{
        set_name( "copper longsword","��ͭ����");
        add( "id",({ "sword","longsword" }) );
        set_short( "��ͭ����");
        set_long(
@CLONG
    ���ǰ��ø߼���ͭ������ĳ�����������������������ϸ���Ĳ���
    /ס/��ֻ�и߼��ĺڰ�������ʿ��ӵ�С�    
CLONG
                );
        set( "unit", "��" );
        set( "weapon_class", 20 );
        set( "type", "longblade" );
        set( "min_damage", 20 );
        set( "max_damage", 32 );
        set( "weight", 110 );
        set( "value", ({ 700, "silver" }) );
}
