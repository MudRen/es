#include "../forest.h"

void create(object ob)
{
		if ( ! ob ) return ;
        ob->set_level(2);
        ob->set_name( "squirrel", "����" );
        ob->set_short( "����" );
        ob->set_long(
                "�㿴��һֻ��������β�ͣ������۾���С������֦ͷ��������ȥ��\n"
        );
        ob->set( "unit", "ֻ" );
        ob->set_perm_stat("kar", 3 );
        ob->set_perm_stat("dex", 5 );
        ob->set_natural_weapon(4,2,3);
        ob->set_natural_armor(7,0);
        ob->set_c_verbs( ({ "%s��צ����%sץȥ" }) );
        ob->set_c_limbs( ({ "ͷ��", "����", "�Ȳ�", "β��" }) );
}
