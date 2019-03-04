
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("sad dagger", "悲伤匕首");
        add ("id",({ "dagger" }) );
        set_short("悲伤匕首");
        set_long(
            "这是一把很锋利的匕首,上面有一些密密麻麻的文字,似乎是古老的\n"
            "半身人文字,但是你并无法确定.\n"
        );
        set( "unit", "把");
        set( "weapon_class", 20 );
        set( "type", "dagger" );
        set( "min_damage", 13);
        set( "max_damage", 21 );
        set( "weight", 110 );
        set( "value", ({ 820, "silver" }) );
}

//void init()
//{
//   add_action("to_read","read");
//}

//int to_read(string str)
//{
//    if (!str||str!="writing") return 0;
//    else { 
//       return 1;
//      }
//}
