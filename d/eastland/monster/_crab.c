#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return;
	ob->set_level(1);
	ob->set_name( "little crab", "С�з" );
	ob->set_short( "С�з" );
	ob->set_long(
		"��ֻ�з��Ȼ��С���������ɳ̲Ҳ���㹻�������еĵط���\n"
	);
	ob->set( "natural_armor_class", 10 );
	ob->set( "unit", "ֻ" );
	ob->set_c_verbs( ({ "%s�����Ĵ����%sһ��" }) );
	ob->set_c_limbs( ({ "����", "Ӳ��" }) );
}
