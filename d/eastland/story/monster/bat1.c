#include <mudlib.h>

inherit MONSTER;

void create ()
{
    ::create();
    set_level(6);
    set_name( "small bat", "小蝙蝠" );
    add ("id", ({ "bat"}) ); 
    set_short( "小蝙蝠" );
    set_long(@LONG
一只倒挂在壁上的小蝙蝠。        
LONG
    );
    set_natural_armor(30,2);
    set_natural_weapon( 9,3,5 );
    set ("weight", 50);
    set ("unit", "只");
    set_c_verbs( ({ "%s抓%s", "%s咬%s", }) );
    set_c_limbs( ({ "头", "翅膀", "身体" }) );
}
