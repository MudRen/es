#include "../dony.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(4);
       set_name( "grass hopper", "����" );
       add( "id",({"grass","hopper"}) );
       set_short( "����" );
       set("unit","ֻ");
       set_long(
       "����һֻСС������,����������ȥ�ġ�\n"
                        );
       set_perm_stat("dex", 3);
       set_natural_weapon(5,2,4);
       set_natural_armor(5,1); 
//       set( "moving", 1 );
//       set( "speed", 30 );
//       set ("pursuing", 1) ;
//       setenv( "C_MIN", "һֻ$N���˹�����");
//       setenv( "C_MOUT", "$N��$D�����˹�ȥ��");
       set_c_verbs(({"%s����������%s��ȥ"}));
       set_c_limbs(({"����","ͷ��","��"}));
}
