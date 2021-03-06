#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
        set_name( "lan-hwa lun", "莲华法轮");
        add( "id", ({ "shield","lun" }) );
        set_short("莲华法轮");
        set_long(@C_LONG
法轮是一种佛法的具相, 具有防御及攻击双重的效果, 莲华法轮是
莲华部观世音座下之法器, 平时可当做盾牌使用, 降魔消障。        
C_LONG
		);
        set( "unit", "座"); 
        set( "type", "shield" );
        set( "material", "monk" );
        set( "armor_class", 8 );
        set( "defense_bonus", 4 );
        set( "weight", 110 );
        set( "value", ({ 120, "gold" }) );
}
