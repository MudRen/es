#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name( "altar key", "��ħ��Կ��" );
        add( "id", ({ "key" }) );
        set_short( "an altar key", "��ħ��Կ��" );
        set_long(
                "A long iron key.\n",
                "������������ͨ����ħ��ͼ��ݵ�Կ�ס�\n"
        );
        set( "unit", "��" );
        set( "to_lock", "1" );
        set( "weight", 3 );
        set( "value", ({ 0, "silver" }) );
        set( "no_sale", 1 );
}
