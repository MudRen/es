#include "../almuhara.h"
inherit ARMOR;

void create()
{
        set_name( "fire leggings", "�����ּ�");
        add( "id", ({ "leggings" }) );
        set_short( "�����ּ�");
        set_long(
                "���ǻ�֮�����������ּף��й�����ɫ�Ĺ�â��\n"
        );
        set( "unit", "��");
        set( "type", "legs" );
        set( "material", "leather" );
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "fire":5, "cold":-10 ]) );
        set( "extra_stats",(["con":-1]) );       
        set( "extra_skills", (["block": 15]) );
        set( "weight", 50 );
        set( "value", ({ 180, "gold" }) );
}
