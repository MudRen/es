#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("copper feet ring", "��ͭ�㻷");
        add( "id", ({ "ring","boots" }) );
        set_short( "��ͭ�㻷" );
        set_long(
@C_LONG
����һ���û�ͭ����ĽŻ����Ǻڰ��������еĲ�Ʒ�����ܽ��ܵ�
��ס������ף�����Ԥ���˺���
C_LONG
        );
        set( "unit", "��");
        set( "type", "feet" );
   set( "material", "light_metal" );
        set( "armor_class", 3 );
        set( "defense_bonus", 4 );
        set( "weight", 70 );
        set( "value", ({ 260, "silver" }) );
}
