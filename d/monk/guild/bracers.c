#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "dragon bracers", "��������" );
        add( "id", ({ "bracers" }) );
        set_short( "��������" );
        set_long(@C_LONG
����ɱ���ŵ�����֮�����ഫ���ܹ�����һ���˵Ļ����ڹ�������
������������ĳ����˿���ɵģ���������һ����ɫ������
C_LONG
        );
        set( "unit", "˫" );
        set( "type", "hands" );
        set( "no_sale", 1 );
        set( "armor_class", 1 );
     set( "extra_skills", (["strength":5]) );
        set("material","cloth");
        set( "weight", 1 );
        set( "value", ({ 10000000, "gold" }) );
}

