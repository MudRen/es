
#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("iceworm cloth","������");
        add("id",({"cloth"}) );
         set_short("������");
        set_long(@C_LONG
����һ���ñ�������˿���ɵ��·��������б���˿ǿ�͵ĵ����⣬��
�ܹ���ħ�ļӳ֣���������ͬС�ɡ�
C_LONG
        );
        set( "unit", "��" );
        set( "weight", 150 );
        set( "type", "body" );
        set( "material", "cloth" );
        set( "armor_class", 25 );
	set( "defense_bonus", 6 );
        set( "special_defense", ([ "ice" :8, "divine":-10 ]) );
        set( "value", ({ 318, "gold" }) );
}
