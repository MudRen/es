#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_level(3);
	ob->set_name( "peacock", "��ȸ" );
	ob->set_short( "��ȸ" );
	ob->set_long(
		"����һֻ�ǳ�Ư������\n"
	);
	ob->set_perm_stat( "str", 4 );
	ob->set_skill( "dodge", 10 );

	ob->set( "unit", "ֻ" );
	ob->set_natural_weapon( 2, 2, 4 );
	ob->set_c_verbs( ({ "%s��ǰצץ��%s", "%s����������%s��ȥ" }) );
	ob->set_c_limbs( ({ "ͷ��", "β��", "�Ȳ�" }) );
}
