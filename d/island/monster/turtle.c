#include "../island.h"

inherit IMON+"tattack.c";

void create()
{
        ::create();
        set_level(6);
        set_name( "turtle", "�޹�" );
        set_short("�޹�");
        set("unit","ֻ");
        set_long(@LONG
�����ز������ͺ��꣬������˵ɽ��Ҳ��
LONG
        );
        set_perm_stat("str", 8);
        set_perm_stat("dex", 8);
        set("max_hp",100);
        set("hit_points",100);
        set("wimpy",50);
        set("pursuing",1);
        set ("natural_weapon_class1", 5);
        set ("natural_min_damage1", 3);
        set ("natural_max_damage1", 8);
        set ("natural_armor_class", 20);
        set ("likefish",1);
        set_c_verbs(({"%s������������%sײ��","%s������Ӳ����%s����"}));
        set_c_limbs(({"β��","��","�Ų�","ͷ��"}));      
}
