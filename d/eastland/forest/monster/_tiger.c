#include "../forest.h"

void create(object ob)
{
        if ( !ob ) return ;
        ob->set_level(14);
        ob->set_name( "tiger", "�ϻ�" );
        ob->set_short( "�ϻ�" );
        ob->set_long(@C_LONG
��ֻ����������е���è�ģ�������ȴ��ܶࡣ������צ�Ӻ������
������ʳ����Ҫ���ߡ���һ�ַǳ�Σ�յ���ʳ�Զ��
C_LONG
        );
        ob->set("unit","ֻ");
        ob->set_perm_stat( "str", 18 );
        ob->set_perm_stat( "dex", 20 ); 
        ob->set_perm_stat( "int", 12 );
        ob->set_perm_stat( "kar", 18 );
        ob->set_skill( "dodge", 90);
        ob->set("max_hp", 450);
        ob->set("hit_points",450);
        ob->set("special_defense", ([ "all":25, "none":10,"fire":5 ]) );
        ob->set("aim_difficulty",
                ([ "vascular":10, "weakest":20 ]) );
        
        ob->set( "killer", 1);
        ob->set( "c_killer_msg", "ͻȻ�䣬�㿴���ϻ���������������㼱���˹���!!!");
        ob->set( "pursuing",1);
        ob->set( "alignment", -500 );
        ob->set_natural_weapon(40,17,27);
        ob->set_natural_armor(73,28);

        ob->set_c_verbs( ({ "%s���͵���%sһ��ҧȥ", "%sѸ�ٵ�����%s",
                        "%s��������צ��%s������ץȥ"  }) );
        ob->set_c_limbs( ({ "ͷ��", "����", "�Ų�"}) );
}
