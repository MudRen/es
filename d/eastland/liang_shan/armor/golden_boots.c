#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("golden silk boots", "����Ĩ����ѥ");
        add( "id", ({ "boots" }) );
        set_short("golden silk boots", "����Ĩ����ѥ");
        set_long(
                "This is a pair of boots made of golden silk .\n",
                "�����ý��ߺ�˿�����ɵ�Ь�ӣ��������㲻���Ĵ�������·��\n"
        );
        set( "unit", "˫");
        set( "type", "feet" );
        set( "material", "leather");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 70 );
        set( "value", ({ 660, "silver" }) );
}
