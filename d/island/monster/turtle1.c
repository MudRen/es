#include "../island.h"

inherit IMON+"tattack.c";

void create()
{
        ::create();
        set_level(8);
        set_name( "turtle", "�Ϲ�" );
        set_short("�Ϲ�");
        set("unit","ֻ");
        set_long(@LONG
�����ز������ͺ��꣬������˵ɽ��Ҳ��
LONG
        );
        set_perm_stat("str", 9);
        set_perm_stat("dex", 9);
        set("max_hp",150);
        set("hit_points",150);
        set("wimpy",70);
        set("likefish",1);
        set ("natural_weapon_class1", 6);
        set ("natural_min_damage1", 5);
        set ("natural_max_damage1", 12);
        set_natural_armor( 25,6);
        set_c_verbs(({"%s������������%sײ��","%s������Ӳ����%s����"}));
        set_c_limbs(({"β��","��","�Ų�","ͷ��"}));      
}
