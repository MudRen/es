#include "../island.h"        
#include <mudlib.h>
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level( 10 );
       set_skill( "unarmed" , 20 );
       set( "likefish" , 1 ) ;
       set_name( "salmon","ӣ��������" );
       set ( "id", ({ "salmon","fish" }) );
       set_short( "ӣ��������" );
       set( "unit" , "��" );
       set( "alignment" , 500 );
       set_natural_weapon( 22,11,19 );
       set_natural_weapon2( 15,8,18 );
       set_long(@LONG
���ǹ����㡺ӣ�������١�����ֻ���ڼ��������õ�ˮ�л��
���ù���Ҫ�úñ�������
LONG
                        );
       set_c_verbs(({"%s������������%sײȥ","%s������β����%sɨȥ"}));
       set_c_limbs(({"����","β��","ͷ��"}));
}
