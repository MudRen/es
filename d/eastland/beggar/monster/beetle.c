#include "../dony.h"      
        
inherit DMONSTER"limit";

void create ()
{               
       ::create();
       set("lvlimit",10);
       set_level(5);
       set_name( "beetle", "�׳�" );
       add( "id",({"beelte",""}) );
       set_short( "�׳�" );
       set("unit","ֻ");
       set_long(
       "����һֻСС������,������Ϣ�����ϡ�\n"
                        );
       set_perm_stat("dex", 4);
       set_perm_stat("str", 4);
       set_natural_weapon(7,4,8);
       set_natural_armor(25,1); 
       set_c_verbs(({"%s�����ľ޽���%sһ��"}));
       set_c_limbs(({"����","ͷ��","��"}));
}
