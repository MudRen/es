#include <mudlib.h>

inherit MONSTER;

void create ()
{
    ::create();
    set_level(11);
    set_name( "large bat", "大蝙蝠" );
    add ("id", ({ "bat"}) ); 
    set_short( "大蝙蝠" );
    set_long(@LONG
一只倒挂在壁上的大蝙蝠。        
LONG
    );
    set_natural_armor(55,2);
    set_natural_weapon( 19,10,20 );
    set ("weight", 50);
    set ("unit", "只");
    set_c_verbs( ({ "%s抓%s", "%s咬%s", }) );
    set_c_limbs( ({ "头", "翅膀", "身体" }) );
}
