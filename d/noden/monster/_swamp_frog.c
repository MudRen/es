#include <mudlib.h>

void create(object ob)
{
    if ( !ob ) return ;
	ob->set_level(6);
	ob->set_name( "swamp frog", "������" );
	ob->add( "id", ({ "frog" }) );
   ob->set_short( "������" );
	ob->set_long(
		"һֻ�ִ�������ɫ��������һ��Ҳ������ſ������������\n"
	);
	ob->set( "unit", "ֻ" );
	ob->set( "alignment", 500 );
	ob->set_skill( "anatomlogy", 30 );
	ob->set_temp( "aiming_loc", "ganglion" );
	ob->set_c_limbs( ({ "����", "ͷ��", "����" }) );
	ob->set_c_verbs( ({ "%s������%sһҧ", "%s��������ͷ��%sһ��" }) );
	ob->set_natural_armor( 10, 15 );
	ob->set_natural_weapon( 10, 8, 11 );
}
