#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("green cloak", "�и��̡�˿ս��");
        add( "id", ({ "cloak","cape" }) );
        set_short("green cloak","�и��̡�˿ս��");
        set_long(
                "This is a green cloak with some floral mark.\n",
                "һ��˫����̵����磬������\�������Ļ��ƣ�\n"
        );
        set("unit","��");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "weight", 100 );
        set( "value", ({ 1100, "silver" }) );
}