#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("panther_fur pants", "��\Ƥ\��");
        add( "id", ({ "pants" }) );
        set_short("panther_fur pants", "��\Ƥ\��");
        set_long(
                "a pants made of fur of panther .\n",
                "�ñ�\Ƥ\�ƳɵĽ���㣬�����Լѣ�����̫͸����\n"
        );
        set( "unit", "��");
        set( "type", "legs" );
        set( "material", "leather");
        set( "armor_class", 8 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "cold":4, "fire":-5 ]) );
                       
        set( "weight", 160 );
        set( "value", ({ 150, "gold" }) );
}
