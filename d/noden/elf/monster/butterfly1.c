#include "../layuter.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(2);
       set_name( "butterfly", "���ɵ�" );
        set_short( "���ɵ�" );
       set("unit","ֻ");
        set_long(
       "����һֻ�����ķ��ɵ����˿������Ĵ������ķ������������֮���ߡ�\n"
                        );
       set("moving",1);
       set("speed",25);                  
       set_perm_stat("dex", 4);
       set ("natural_weapon_class1", 6);
       set ("natural_min_damage1",2);
       set ("natural_max_damage1", 4);
       set ("natural_armor_class", 5);
		setenv( "C_MIN", "һֻ$N����ķ��˹�����");
        setenv( "C_MOUT", "$N�������$D�߷�ȥ��");
       set_c_verbs(({"%s�����ĳ����%s�˻�"}));
       set_c_limbs(({"����","ͷ��"}));
}
