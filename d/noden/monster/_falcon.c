#include <mudlib.h>

void create(object ob)
{
    if ( !ob ) return ;
	ob->set_level(3);
	ob->set_name( "falcon", "��ӥ" );
   ob->set_short( "��ӥ" );
	ob->set_long(
		"��ֻ��ӥ�����ӵ����ض����㣬С�Ĳ�Ҫ��Ϊ�������\n"
	);
	ob->set_perm_stat( "str", 6 ); 
	ob->set_perm_stat( "dex", 5 );
	ob->set_perm_stat( "pie", 1 );

	ob->set( "unit", "ֻ" );
	ob->set( "alignment", 150 );
	ob->set( "natural_weapon_class1", 3 );
	ob->set( "natural_min_damage1", 3 );
	ob->set( "natural_max_damage1", 5 );
	ob->set_c_verbs( ({ "%s���¸��壬�������%s", "%s��צ����%sץ��" }) );
	ob->set_c_limbs( ({ "ͷ��", "����", "���" }) );
}
