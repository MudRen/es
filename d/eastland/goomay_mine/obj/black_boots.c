#include "../zeus.h"
inherit ARMOR;

void create()
{
        set_name("daemonic boots", "��ɫ��Ь");
        add( "id", ({ "boots" }) );
        set_short("daemonic boots", "��ɫ��Ь");
        set_long(@CLONG
����һ˫��ɫ�Ĺ�Ь����������ʲ�����ɵģ������ƺ�������һ��
Ī��������
CLONG
        );
        set( "unit", "˫");
        set( "type", "feet" );
        set( "material", "heavy_metal");
        set( "armor_class", 6 );
        set( "special_defense",
               (["acid":2 ]) );
        set( "weight", 80 );
        set( "value", ({ 440, "silver" }) );
}