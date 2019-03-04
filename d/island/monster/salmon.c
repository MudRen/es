#include "../island.h"        
#include <mudlib.h>
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level( 10 );
       set_skill( "unarmed" , 20 );
       set( "likefish" , 1 ) ;
       set_name( "salmon","樱花钩吻鲑" );
       set ( "id", ({ "salmon","fish" }) );
       set_short( "樱花钩吻鲑" );
       set( "unit" , "条" );
       set( "alignment" , 500 );
       set_natural_weapon( 22,11,19 );
       set_natural_weapon2( 15,8,18 );
       set_long(@LONG
这是国宝鱼『樱花钩吻鲑』，它只能在极清洁和良好的水中活存
，好国民要好好保护它。
LONG
                        );
       set_c_verbs(({"%s用它的身体向%s撞去","%s用它的尾巴向%s扫去"}));
       set_c_limbs(({"鱼鳍","尾巴","头部"}));
}
