#include "mudlib.h"

void create(object ob)
{
        if ( !ob ) return ;
        ob->set_level(12);
        ob->set_name( "cheetah", "ӡ�ȱ�\ " );
        ob->set_short( "ӡ�ȱ�\ " );
        ob->set_long(@C_LONG
����һֻ����Ư��ëƤ���޳������Ķ�����Ķ����ǳ��ؿ죬
��һ�־���Σ���Ե���ʳ���
C_LONG
        );
        ob->set("unit","ͷ");
        ob->set_perm_stat( "str", 18 );
        ob->set_perm_stat( "dex", 20 );
        ob->set_perm_stat( "int", 10 );
        ob->set_perm_stat( "kar", 18 );
        ob->set_skill( "dodge", 80);
        ob->set("max_hp", 350);
        ob->set("hit_points", 350);
        ob->set("special_defense", ([ "all":30, "none":15, "fire":3 ]) );
        ob->set("aim_difficulty",
            ([ "weakest":40, "ganglion":30 ]) );
        
        ob->set( "killer", 1);
        ob->set( "c_kill_msg", "ͻȻ�䣬ӡ�ȱ�\���������������˹��� !!!!!" );
        ob->set( "alignment", -400 );
        ob->set_natural_weapon(35,13,23);
        ob->set_natural_armor(63,30);

        ob->set_c_verbs( ({ "%s��������צ��%sץȥ", "%sѸ�ٵ�����%s" }) );
        ob->set_c_limbs( ({ "ͷ��", "����", "�Ų�"}) );
}
