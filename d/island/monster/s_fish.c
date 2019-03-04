#include "../island.h"        
#include <mudlib.h>
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level( 5 );
       set( "likefish" , 1 ) ;
       set_name( "small fish","小鱼" );
       set ( "id", ({ "fish" }) );
       set_short( "小鱼" );
       set( "unit" , "条" );
       set( "alignment" , 30 );
       set_natural_weapon( 12,5,9 );
       set_skill( "unarmed" , 15 );
       set_natural_armor( 25,8 );
       set_long(@LONG
这是一条极普通的小鱼，请不要欺负它，谢谢！
LONG
                        );
       set_c_verbs(({"%s用它的身体向%s撞去"}));
       set_c_limbs(({"鱼鳍","尾巴","头部"}));
}
