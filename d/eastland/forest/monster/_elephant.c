#include "../forest.h"

void create(object ob)
{
        if ( !ob ) return ;
        ob->set_level(5);
        ob->set_name( "elephant", "����" );
        ob->set_short("����");
        ob->set("unit","ͷ");
        ob->set_long(@C_LONG
�㿴��һֻ�޴�Ķ�����������ı��ӡ��޴�Ķ��䡢��������ɫ�ĳ�����
��ʱ������ɭ�������е���������
C_LONG
        );
        ob->set_perm_stat("str", 8);
        ob->set_perm_stat("dex", 3);
        ob->set_natural_weapon(6,6,12);
        ob->set_natural_armor(25,0);
        ob->set_c_verbs(({"%s�����ĳ�����%s����","%s�����ĳ���˦��%s"}));
        ob->set_c_limbs(({"����","����","����","�Ų�","ͷ��"}));
}
