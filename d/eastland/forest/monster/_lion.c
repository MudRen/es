#include "../forest.h"

void create(object ob)
{
		if ( !ob ) return ;
        ob->set_level(17);
        ob->set_name( "lion", "ʨ��" );
        ob->set_short( "ʨ��" );
        ob->set_long(@C_LONG
����һֻ���ϳ�����ë�Ķ��������������ƺ�û��ʲ��Σ���ԡ�
����ɭ���еĶ����ƺ������ҿ�����������С��һ��ĺá�
C_LONG
        );
        ob->set("unit","ֻ");
        ob->set_perm_stat( "str", 23 );
        ob->set_perm_stat( "dex", 25 );
        ob->set_perm_stat( "int", 13 );
        ob->set_perm_stat( "kar", 20 );
        ob->set_skill( "dodge", 100 );
        ob->set("max_hp", 550);
        ob->set("hit_points", 550);
        ob->set("special_defense", ([ "all":50, "none":25,"fire":5 ]) );
        ob->set("aim_difficulty",
            ([ "vascular":10,"weakest":30 ]));
        
        ob->set( "aggressive", 1 );
        ob->set( "c_killer_msg","��ͻȻ����ʨ�����ſ����Ĵ�����㱳�����˹���....");
        ob->set( "alignment", -500 );
        ob->set_natural_weapon(50,22,30);
        ob->set_natural_armor(70,30);

        ob->set_c_verbs( ({ "%s�ſ����Ĵ�ڣ�һ����%sҧȥ", "%sѸ�ٵ���%s��ȥ" }) );
        ob->set_c_limbs( ({ "ͷ��", "����", "�Ų�" }) );
}
