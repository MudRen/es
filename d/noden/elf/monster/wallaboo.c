#include "../layuter.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(4);
        set_name( "wallaboo", "����" );
        set_short( "����" );
        set("unit","ֻ");
        set_long(
        "�㿴��һֻ�ı������Ķ����ڲ�ԭ����������\n"  
        );
        set_perm_stat("str", 8);
        set_perm_stat("dex", 8);
        set ("natural_weapon_class1", 5);
        set ("natural_min_damage1", 3);
        set ("natural_max_damage1", 8);
        set ("natural_armor_class", 20);
        set_c_verbs(({"%s������������%s��ȥ","%s������ȭͷ��%s����"}));
        set_c_limbs(({"����","����","�Ų�","ͷ��"}));      
}
