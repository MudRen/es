#include "../island.h"        
#include <mudlib.h>
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level( 5 );
       set( "likefish" , 1 ) ;
       set_name( "small fish","С��" );
       set ( "id", ({ "fish" }) );
       set_short( "С��" );
       set( "unit" , "��" );
       set( "alignment" , 30 );
       set_natural_weapon( 12,5,9 );
       set_skill( "unarmed" , 15 );
       set_natural_armor( 25,8 );
       set_long(@LONG
����һ������ͨ��С�㣬�벻Ҫ�۸�����лл��
LONG
                        );
       set_c_verbs(({"%s������������%sײȥ"}));
       set_c_limbs(({"����","β��","ͷ��"}));
}
