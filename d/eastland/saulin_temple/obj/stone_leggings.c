#include "../saulin_temple.h"
inherit ARMOR;

void create()
{
        set_name("stone leggings", "��ʯ��ϥ");
        add( "id", ({ "leggings" }) );
        set_short("��ʯ��ϥ");
        set_long(
              "����Ұ����սʿר�õĻ�ϥ�����ǳ����أ����������ܵı�����ĽŲ�\n"
        );
        set( "unit", "��");
        set( "type", "legs" );
        set( "material", "stone");
        set( "armor_class", 8 );
        set( "defense_bonus", 0 );
        set( "special_defense",
               ([ "fire":4, "cold":-3, "divine":-1 ]) );
                       
        set( "weight", 130 );
        set( "value", ({ 90, "gold" }) );
}
