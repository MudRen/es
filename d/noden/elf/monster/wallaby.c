#include "../layuter.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(1);
        set_name( "wallaby", "С����" );
        set_short( "С����" );
        set("unit","ֻ");
        set_long(
        "�㿴��һֻ�ɰ��Ķ����ڲ�ԭ�ϱı�������������\n"  
        );
        set_perm_stat("str", 3);
        set_perm_stat("dex", 3);
        set ("natural_weapon_class1", 3);
        set ("natural_min_damage1", 2);
        set ("natural_max_damage1", 3);
        set ("natural_armor_class", 5);
        set_c_verbs(({"%s������������%s��ȥ","%s������ȭͷ��%s����"}));
        set_c_limbs(({"����","����","�Ų�","ͷ��"}));      
}
