#include "../island.h"

inherit IMON+"tattack.c";

void create()
{
        ::create();
        set_level(11);
        set_name( "turtle", "׳���" );
        set_short("׳���");
        set("unit","ֻ");
        set_long(@LONG
�����ز������ͺ��꣬������˵ɽ��Ҳ�У���������ֵ׳�ꡣ
LONG
        );
        set_perm_stat("str", 14);
        set_perm_stat("dex", 14);
        set ("max_hp",200);
        set ("hit_points",200);
        set ("wimpy",100);
        set ("pursuing",1);
        set ("likefish",1);
        set ("natural_weapon_class1",11);
        set ("natural_min_damage1", 9);
        set ("natural_max_damage1", 17);
        set_natural_armor( 33,12);
        set_c_verbs(({"%s������������%sײ��","%s������Ӳ����%s����"}));
        set_c_limbs(({"β��","��","�Ų�","ͷ��"}));      
}
