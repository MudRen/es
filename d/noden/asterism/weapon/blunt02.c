
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("Brass huge hammer", "ª∆Õ≠æﬁÈ≥");
        add ("id",({ "hammer" }) );
        set_short("ª∆Õ≠æﬁÈ≥");
        set_long(
            "’‚ «“ª∞—ª∆Õ≠æﬁÈ≥°£\n"
        );
        set( "unit", "∞—");
        set( "weapon_class", 20 );
        set( "type", "blunt" );
        set( "nosecond",1);
        set( "min_damage", 11);
        set( "max_damage", 24);
        set( "weight", 240 );
        set( "value", ({ 790, "silver" }) );
}

