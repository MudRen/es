#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("twilight amulet", "���������");
        add( "id", ({ "amulet" }) );
        set_short("twilight amulet", "���������");
        set_long(
                "����һ������ҹ���˲��ܶ��漰а���ֺ��Ļ����\n"
        );
        set( "unit", "��");
        set( "type", "misc" );
        set( "material", "cloth");
        set( "armor_class", 0);
        set( "defense_bonus", 5 );
        set( "special_defense",
             ([ "evil":10, "poison":10 ]) );
        set( "weight", 30 );
        set( "value", ({ 570, "silver" }) );
}
