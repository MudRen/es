#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name( "occult globe", "���黤��Բ��" );
    add( "id", ({ "globe", }) );
    set_short( "���黤��Բ��" );
    set_long(@LONG 
    һ����״�ķ�����,����һ�ֻ��ܲ�������
LONG      );
    set( "unit", "��" );
    set( "type", "globe" );
    set( "material", "element" );
    set( "defense_bonus", 10 );
    set( "weight", 100 );
    set( "value", ({ 200, "silver" }) );
}
