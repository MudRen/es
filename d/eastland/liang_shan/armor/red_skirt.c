#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("red skirt", "�ʺ�����ȹ");
        add( "id", ({ "skirt" }) );
        set_short("red skirt", "�ʺ�����ȹ");
        set_long(
                "a short skirt made of silk .\n",
                "����˿Ⱦɫ�Ƴɵ��ʺ�ɫȹ�ӣ�Ů���Ӵ�����һ���ܺÿ���\n"
        );
        set( "unit", "��");
        set( "type", "legs" );
        set( "material", "cloth");
        set( "armor_class", 5 );
        set( "defense_bonus", 4 );
        set( "special_defense",
               ([ "cold":-2, "fire":3 ]) );
                       
        set( "weight", 60 );
        set( "value", ({ 50, "gold" }) );
}
