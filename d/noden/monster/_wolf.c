#include <mudlib.h>

void create(object ob)
{
    if ( !ob ) return ;
	ob->set_level(2);
	ob->set_name( "wild wolf", "Ұ��" );
	ob->add( "id", ({ "wolf" }) );
   ob->set_short( "Ұ��" );
	ob->set_long(
		"һͷ������ë���������ݵ�Ұ�ǡ�\n"
	);
	ob->set_perm_stat( "str", 4 );
	ob->set_skill( "dodge", 20 );
   ob->set( "race", "beast" );
	ob->set( "unit", "ֻ" );
	ob->set( "natural_weapon_class1", 5 );
	ob->set( "natural_min_damage1", 3 );
	ob->set( "natural_max_damage1", 6 );
	ob->set( "killer", 1 );
	ob->set( "aggressive", 1 );

	ob->set_c_verbs( ({ "%s��ǰצ����%s", "%s�ſ��������ݵ��죬��%sҧȥ" }) );
	ob->set_c_limbs( ({ "ͷ��", "����", "β��", "�Ȳ�" }) );
}
