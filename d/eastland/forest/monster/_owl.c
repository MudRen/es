#include "../forest.h"

void create(object ob)
{
	if ( ! ob ) return ;
        ob->set_level(3);
        ob->set_name( "owl", "èͷӥ" );
        ob->set_short( "èͷӥ" );
        ob->set_long(
                "����һ�����ҹ�����񣬽����ǳ�������������Ϊ����������硣\n"
        );
        ob->set("unit","ֻ");
        ob->set( "alignment", -100 );
        ob->set_perm_stat( "dex", 5 );
        ob->set_natural_weapon(4,3,6);
        ob->set_natural_armor(9,0);
        ob->set_c_verbs( ({ "%s���¸��壬�������%s", "%s��צ����%sץ��" }) );
        ob->set_c_limbs( ({ "ͷ��", "����", "���" }) );
}
