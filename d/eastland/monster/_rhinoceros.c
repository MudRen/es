#include <mudlib.h>

void create(object ob)
{
		if ( ! ob ) return ;
        ob->set_level(14);
        ob->set_name( "rhinoceros", "Ϭţ" );
        ob->set_short("Ϭţ" );
        ob->set_long(@C_LONG
��ֻ���￴�����ܴ�����, �ƺ�ûʲ�ṥ����....
��, ����, ���Ľ���մ����Ѫ��, ��������ɥ�����,
��û�����߾���!
C_LONG
        );
        ob->set("unit","ֻ");
        ob->set_perm_stat( "str", 22 );
        ob->set_perm_stat( "dex", 15 ); 
        ob->set_perm_stat( "int", 12 );
        ob->set_skill( "dodge", 80);
        ob->set("max_hp", 600);
        ob->set("hit_points",600);
        ob->set("special_defense", ([ "all":25, "none":10,"fire":5 ]) );
        ob->set("aim_difficulty",
                ([ "vascular":10, "weakest":20 ]) );
        
        ob->set( "alignment", 200 );
        ob->set_natural_weapon(40,15,25);
        ob->set_natural_armor(40,30);
        ob->set_c_verbs( ({ "%s���͵���%sһ��ҧȥ",
                        "%s�����Ľ�ȫ����%s����ȥ"  }) );
        ob->set_c_limbs( ({ "ͷ��", "����", "�Ų�"}) );
}
