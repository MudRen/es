#include "../island.h"

inherit IMON+"tattack.c";

void create()
{
        ::create();
        set_level(3);
        set_name( "turtle", "С��" );
        set_short("С��");
        set("unit","ֻ");
        set_long(@LONG
�����ز������ͺ��꣬������˵ɽ��Ҳ�У��������᲻Ҫ�۸�����
LONG
        );
        set_perm_stat("str", 4);
        set_perm_stat("dex", 4);
        set("max_hp",65);
        set("hit_points",65);
        set("wimpy",30);
        set("pursuing",1);
        set("likefish",1);
        set ("natural_weapon_class1", 4);
        set ("natural_min_damage1", 2);
        set ("natural_max_damage1", 6);
        set ("natural_armor_class", 15);
        set_c_verbs(({"%s������������%sײ��","%s������Ӳ����%s����"}));
        set_c_limbs(({"β��","��","�Ų�","ͷ��"}));      
}
