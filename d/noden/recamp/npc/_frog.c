
#include <mudlib.h>
void create(object ob)
{
        if (!ob) return ;
        seteuid(getuid()) ;
	ob->set_level(1);
	ob->set_name( "stone frog", "ʯͷ��" );
	ob->add( "id", ({ "frog" }) );
	ob->set_short( "ʯͷ��" );
	ob->set_long(
	 "�㿴��һֻ�Һ�ɫ�����ܣ���������ʯͷ����·��Ƥ���������ϵ�
�������������ĵ��������\n"
	);
	ob->set( "unit", "ֻ" );
	ob->set( "alignment", 500 );
	ob->set( "unbleeding", 1 );
	ob->set_perm_stat("str", 5);
	ob->set_c_verbs( ({ "%s��������%sһ��" }) );
	ob->set_c_limbs( ({ "ͷ��", "����", "�Ȳ�" }) );
}
