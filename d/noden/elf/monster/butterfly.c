#include "../layuter.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(1);
       set_name( "butterfly", "����" );
        set_short( "����" );
       set("unit","ֻ");
        set_long(
       "����һֻ���������棬�˿����ڻ��������ķ�����\n"
                        );
       set_perm_stat("dex", 3);
       set ("natural_weapon_class1", 5);
       set ("natural_min_damage1",1);
       set ("natural_max_damage1", 3);
       set ("natural_armor_class", 5);
       set_c_verbs(({"%s�����ĳ����%s�˻�"}));
       set_c_limbs(({"����","ͷ��"}));
}
