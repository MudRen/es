#include <mudlib.h>

void create(object ob)
{
    if ( !ob ) return ;
	ob->set_level(1);
	ob->set_name( "green spider", "��֩��" );
	ob->add( "id", ({ "spider" }) );
   ob->set_short( "��֩��" );
	ob->set_long(
		"�㿴��һֻ��ɫ�Ĵ�֩�룬����֩�벢���������������ר�����ٵ��ж�\n"
		"��ǿ������֫�岶ʳС�����ֻ֩��������Ĵ���������������ˡ�\n"
	);
   ob->set( "race", "insect" );
	ob->set_perm_stat( "dex", 2 );
	ob->set( "alignment", -300 );
	ob->set( "aggressive", 1 );

	ob->set( "unit", "ֻ" );
	ob->set_c_verbs( ({ "%s������ֻ��������%sҧ��", "%s��ë���׵�ǰ֫��%sһ��" }) );
	ob->set_c_limbs( ({ "ͷ��", "����", "�Ȳ�" }) );
}
