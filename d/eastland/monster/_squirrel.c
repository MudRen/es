#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_level(1);
	ob->set_name( "squirrel", "����" );
	ob->set_short( "����" );
	ob->set_long(
		"�㿴��һֻС������֦ͷ��������ȥ��\n"
	);
	ob->set( "unit", "ֻ" );
	ob->set_perm_stat("kar", 3 );
	ob->set_perm_stat("dex", 4 );
	ob->set_c_verbs( ({ "%s��צ����%sץȥ" }) );
	ob->set_c_limbs( ({ "ͷ��", "����", "�Ȳ�", "β��" }) );
}
