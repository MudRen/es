#include <mudlib.h>

void create(object ob)
{

    if ( !ob ) return ;
	ob->set_level(2);
	ob->set_name( "halfling girl", "������СŮ��" );
	ob->add( "id", ({ "halfling", "girl" }) );
   ob->set_short("������СŮ��" );
	ob->set_long(
		"�����������ߺܰ�����ʹ�Ǹ����������˱ȣ�Ҳ���Ǹ����ӣ���\n"
		"�������۵����׺Ͷ���������ȷ�������ᳬ��ʮ�ꡣ\n"
	);
	ob->set_perm_stat( "dex", 4 );
	ob->set( "race", "halfling" );
	ob->set( "gender", "female" );
	ob->set( "alignment", 500 );
	ob->set( "wealth/silver", 10 );

	ob->wield_weapon("/d/noden/item/spear");

	ob->equip_armor("/d/noden/item/jerkin");
}
