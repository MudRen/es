#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("golden cloak", "���޽���˿����");
        add( "id", ({ "cloak","cape" }) );
        set_short("golden cloak","���޽���˿����");
        set_long(
                "This is a golden beautiful cloak.\n",
                "һ���ý�˿���޲����ɵ����磬�ǳ����ö�Ŀ��\n"
        );
        set("unit","��");
        set( "type", "cloak" );
        set( "material", "heavy_metal" );
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 100 );
        set( "value", ({ 1120, "silver" }) );
}