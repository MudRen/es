#include "../layuter.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(5);
        set_name( "elephant", "����" );
        set_short( "����" );
        set("unit","ͷ");
        set_long(
        "�㿴��һֻ�޴�Ķ�����������ı��ӡ��޴�Ķ��䡢��������ɫ�ĳ�����\n"
        "��ʱ�����ڲ�ԭ�����е�������\n"  
        );
        set_perm_stat("str", 8);
        set_perm_stat("dex", 3);
        set("max_hp",100);
        set("hit_points",100);
        set ("natural_weapon_class1", 3);
        set ("natural_min_damage1", 5);
        set ("natural_max_damage1", 10);
        set ("natural_armor_class", 25);
        set_c_verbs(({"%s�����ĳ�����%s����","%s�����ĳ���˦��%s"}));
        set_c_limbs(({"����","����","����","�Ų�","ͷ��"}));      
}
