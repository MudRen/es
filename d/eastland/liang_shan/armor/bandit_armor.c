
#include "mudlib.h"

#define AC ({ 7,4,4,7,7,7 })
#define DB ({ 1,0,0,1,2,1 })
#define TYPES ({"head","arms","hands","legs","cloak","feet" })
#define UNITS ({"顶","个","双","双","片","双" })
#define ADD_CNAME ({"山贼战斗头盔","山贼战斗护肘","山贼战斗护手","山贼战斗胫甲","山贼战斗背甲","山贼战斗靴" })
#define EXTRA_ID ({"helmet","sleeves","bracers","leggings","backarmor","shoes" })
inherit ARMOR;

void create()
{
        int i;
        i = random(6);
        set_name("bandit "+EXTRA_ID[i], ADD_CNAME[i]);
        add( "id", ({ EXTRA_ID[i] }) );
        set_short(ADD_CNAME[i]);
        set_long(
                "这是梁山泊的山贼们所使用的"+ADD_CNAME[i]+"\n"
                "虽然看来不是很美观，但是却相当实用..\n"
        );
        set("unit",UNITS[i]);
        set( "type", TYPES[i] );
        set( "material", "heavy_metal");
        set( "armor_class", AC[i] );
        set( "defense_bonus", DB[i] );
        set( "weight", 250 );
        set( "value", ({ 230, "silver" }) );
}



