#include "../forest.h"

void create (object ob)
{
		if ( !ob ) return ;
       ob->set_level(1);
       ob->set_name( "rabbit", "����" );
       ob->set_short("����");
       ob->set("unit","ֻ");
       ob->set_long(@C_LONG
�㿴��һֻ�ɰ��Ķ�����ڲ�ԭ��������Ծ����������һ˫
�����Ķ��估��ֻͻ�����������˿����������㣬�޹��ı��������
��Ƥ�ľ��������������ְ���
C_LONG
                        );
       ob->set_perm_stat("dex", 3);
       ob->set_natural_weapon(3,0,0);
       ob->set_natural_armor(5,0);
       ob->set_c_verbs(({"%s������������%s��ȥ"}));
       ob->set_c_limbs(({"����","����","�Ų�","ͷ��"}));
}
