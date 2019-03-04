#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(13);
	set_name( "soothsayer", "卜筮者" );
	set_short( "卜筮者" );
	set_long(@C_LONG
一位白发苍苍的老太婆，她正眯著眼睛注视著胸前的水晶玻璃球，神情极是悠闲。   
C_LONG
        );
	set( "gender", "female" );
        set( "unit","位");
        set( "wealth/silver",100);
        set_natural_armor(65,0); 
        set_natural_weapon( 23,9,23 );
        set( "inquiry", ([
            "crystal_glass":"@@ask_crystal",
        ]) );
}
void ask_crystal(object asker)
{
    tell_room(environment(),@LONG
                            
卜筮者怒道：小孩子没事问我的水晶玻璃球干嘛？
                                      　　
LONG
   );
}
