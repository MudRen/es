#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_level(2);
	ob->set_name( "swamp crab", "�����з" );
	ob->set_short( "�����з" );
	ob->set_long(
		"����һ��ϡ�е��з����ס������ͺ���Ľ���ش���\n"
	);
	ob->set( "natural_armor_class", 20 );
	ob->set( "unit", "ֻ" );
	ob->set_c_verbs( ({ "%s�����Ĵ�����%sһ��" }) );
	ob->set_c_limbs( ({ "����", "Ӳ��" }) );
}
