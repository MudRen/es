#include "../layuter.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(3);
       set_name( "marmot", "������" );
        set_short( "������" );
       set("unit","ֻ");
        set_long(
       "�㿴��һֻ�ɰ��Ķ�����ӵض���͵͵�������㣬�����߹�ȥ��\n"       
      " ������ʱ�����ɿ�Ķ��붴�һ�����ߵ�ģ��\n"
                        );
       set_perm_stat("dex", 2);
       set ("natural_weapon_class1", 4);
       set ("natural_min_damage1",8);
       set ("natural_max_damage1", 11);
       set ("natural_armor_class", 15);
       set_c_verbs(({"%s������ǰצ��%sץȥ","%s������������%sҧȥ"}));
       set_c_limbs(({"����","�Ų�","ͷ��"}));
}

