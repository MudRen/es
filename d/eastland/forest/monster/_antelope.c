#include "mudlib.h"

void create(object ob)
{
        if ( !ob ) return ;
        ob->set_level(4);
        ob->set_name( "antelope", "��¹" );
        ob->set_short( "��¹");
        ob->set("unit","ֻ");
        ob->set_long(@C_LONG
�㿴��һֻ���صĶ��ͷ�ϳ�����ֻ����Ľǣ�������ɫ��ëƤ��
��ʱ������ɭ�������е�������
C_LONG
        );
        ob->set_perm_stat("dex", 10);
        ob->set_perm_stat("kar", 8);
        ob->set("max_hp",180);
        ob->set("hit_points",180);
        ob->set_natural_weapon(7,4,9);
        ob->set_natural_armor(25,0);
        ob->set_c_verbs(({"%s�����Ľ���%s����","%s�����Ľ���%s��ȥ"}));
        ob->set_c_limbs(({"����","�Ų�"}));
}
