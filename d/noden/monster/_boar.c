#include <mudlib.h>

void create(object ob)
{
    if (!ob ) return ;
	ob->set_level(3);
	ob->set_name( "fat boar", "Ұ��" );
	ob->add( "id", ({ "boar" }) );
   ob->set_short( "Ұ��" );
	ob->set_long(
		"��ͷҰ��ʵ�ں��֣��ֵ��㼸����������Ϊ������������\n"
	);
	ob->set_perm_stat( "str", 5 );
	ob->set_perm_stat( "dex", 2 );
   ob->set( "race", "beast" );
	ob->set( "unit", "ͷ" );
	ob->set( "natural_weapon_class1", 7 );
	ob->set( "natural_min_damage1", 3 );
	ob->set( "natural_max_damage1", 8 );
	ob->set_c_verbs( ({ "%s��ͷ�ͳ壬ײ��%s", "%s�ڵ���һ������������%s��ȥ" }) );
	ob->set_c_limbs( ({ "ͷ��", "����", "�Ȳ�", "ƨ��" }) );
}
