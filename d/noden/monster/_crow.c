#include <mudlib.h>

void create(object ob)
{
	if (!ob ) return ;
	ob->set_level(1);
	ob->add( "id", ({ "crow" }) );
	ob->set_name( "black crow", "��ѻ" );
    ob->set_short( "��ѻ" );
	ob->set_long(
		"��ֻ��ѻ�ǳ�����������һ�ɰ���һ�������ĳ嶯����\n"
	);
	ob->set_perm_stat( "dex", 3 );

	ob->set( "unit", "ֻ" );
	ob->set( "natural_weapon_class1", 3 );
	ob->set( "natural_min_damage1", 3 );
	ob->set( "natural_max_damage1", 5 );
	ob->set_c_verbs( ({ "%s���¸��壬�������%s", "%s��צ����%sץ��" }) );
	ob->set_c_limbs( ({ "ͷ��", "����", "���" }) );
}
