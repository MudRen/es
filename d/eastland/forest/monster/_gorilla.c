#include "../forest.h"

void create(object ob)
{
        if ( !ob ) return ;
        ob->set_level(8);
        ob->set_name( "gorilla", "��Գ" );
        ob->set_short("��Գ");
        ob->set("unit","ֻ");
        ob->set_long(@C_LONG
������ǰ����һֻ���͵Ķ���н�ȫ��˫��˫�ţ�����ȫ��ë���׵ġ�
���ƺ��������Ķ������һЩ����۵�ģ�����˲����ɱ����
C_LONG
        );
        ob->set_perm_stat( "str", 12 );
        ob->set_perm_stat( "dex", 18 );
        ob->set_perm_stat( "int", 18 );
        ob->set_perm_stat( "kar", 15);
        ob->set("wimpy",50);
        ob->set_skill("dodge",100);
        ob->set("max_hp", 300);
        ob->set("hit_points", 300);
        ob->set("special_defense", ([ "all":40, "none":20, ]) );
        ob->set("aim_difficulty",
        	([ "critical":45, "vascular":80, "weakest":30, "ganglion":60 ]) );
        
        ob->set( "alignment",500 );
        ob->set_natural_weapon(17,12,20);
        ob->set_natural_armor(50,30);
        ob->set_c_verbs(({"%s������ȭͷ��%s����","%s�����Ľ���%s��ȥ",
                      "%s������ͷ��%s���ҵ�ײȥ"}));
        ob->set_c_limbs(({"����","�Ų�","ͷ��","�ֲ�"}));
}
