#include <mudlib.h>

void create(object ob)
{

    if ( !ob ) return ;
	ob->set_level(1);
	ob->set_name( "fat farmer", "��ũ��" );
	ob->add( "id", ({ "farmer" }) );
   ob->set_short( "��ũ��" );
	ob->set_long(
		"��λũ�򳤵����ֵģ��������ʵ��\n"
	);
	ob->set( "max_hp", 40 );
	ob->set( "hit_points", 40 );
	ob->set( "race", "human" );
	ob->set( "gender", "male" );
	ob->set( "alignment", 200 );
	ob->set( "wealth/silver", 15 );

	ob->wield_weapon("/d/noden/item/fork");

	ob->equip_armor("/d/noden/item/hat");
}
