#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_level(2);
	ob->set_name( "hyaena", "����" );
	ob->set_short( "����" );
	ob->set_long(
		"�㿴��һֻ�׶�����ǣ������㷢�������ء��ĵͺ�\n"
	);
	ob->set_perm_stat( "str", 4 );
	ob->set_skill( "dodge", 20 );

	ob->set( "unit", "ֻ" );
	ob->set_natural_weapon( 5, 3, 6 );
	ob->set( "killer", 1 );
	ob->set( "aggressive", 1 );

	ob->set_c_verbs( ({ "%s��ǰצ����%s", "%s�ſ��������ݵ��죬��%sҧȥ" }) );
	ob->set_c_limbs( ({ "ͷ��", "����", "β��", "�Ȳ�" }) );
}
