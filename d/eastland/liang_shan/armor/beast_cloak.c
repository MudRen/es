#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("beast cloak", "ϼ�ɹ���筺���");
        add( "id", ({ "cloak","cape" }) );
        set_short("beast cloak","ϼ�ɹ���筺���");
        set_long(
                "һ������ëƤ���磬������һ���޴������ͼ����\n"
        );
        set("unit","��");
        set( "type", "cloak" );
        set( "material", "leather" );
        set( "armor_class", 7 );
        set( "defense_bonus", 4 );
        set( "special_defense",(["none":3,"magic":4,"fire":-2 ]) );
        set( "weight", 90 );
        set( "value", ({ 1300, "silver" }) );
}