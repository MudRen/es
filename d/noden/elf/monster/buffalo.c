#include "../layuter.h"

inherit MONSTER;

void create()
{
        object boots,dagger,shield,legging,plate,cloak;

        ::create();
        set_level(4);
        set_name( "buffalo", "Ұţ" );
        set_short( "Ұţ" );
        set("unit","ͷ");
        set_long(
        "�㿴��һֻ׳˶�Ķ��������ֻ�����Ľǣ��������׶������\n"
        "�����羯���ĵ�����\n"  
        );
        set_perm_stat("str", 5);
        set("max_hp",60);
        set("hit_points",60);
        set ("natural_weapon_class1", 4);
        set ("natural_min_damage1", 2);
        set ("natural_max_damage1", 5);
        set ("natural_armor_class", 17);
        set_c_verbs(({"%s�����ĳ�����%s����","%s������������%s��ȥ"}));
        set_c_limbs(({"����","ͷ��","�Ų�","β��"}));      
}
