#include <mudlib.h>

void create(object ob)
{
	if (!ob ) return ;
	ob->set_level(1);
	ob->set_name( "beetle", "�׳�" );
   ob->set_short( "�׳�" );
	ob->set_long(
		"һֻ����Ӳ�ǵĳ��Ǽ׳棬��������Сʱ�� ....��\n"
	);
	ob->set_perm_stat( "str", 3 );
   ob->set( "race", "insect" );
	ob->set( "unit", "ֻ" );
	ob->set( "alignment", -150 );
	ob->set( "natural_weapon_class1", 3 );
	ob->set( "natural_min_damage1", 2 );
	ob->set( "natural_max_damage1", 4 );
	ob->set_c_verbs( ({ "%s�ý���%sһ��", "%s�ſ���������%sҧȥ" }) );
	ob->set_c_limbs( ({ "ͷ��", "����", "�Ų�", "�׿�" }) );
}
