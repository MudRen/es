#include "../asterism.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(3);
       set_name( "monkey", "����" );
       set_short( "monkey","����");
       set("unit","ֻ");
       set_long("",
       "��ֻ���ӵ������ϻΰ��Σ�����ʱתͷ��������ж���\n"       
       "�㿴�����ֵ�����¶¶�Ĵ����������ˡ�\n"
                        );
       set_perm_stat("dex", 2);
       set ("natural_weapon_class1", 4);
       set ("natural_min_damage1",5);
       set ("natural_max_damage1", 8);
       set ("natural_armor_class", 13);
       set_c_verbs(({"%s����������%sץȥ","%s������������%sҧȥ"}));
       set_c_limbs(({"����","�Ų�","ͷ��"}));
}

