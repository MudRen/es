#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_level(8);
	ob->set_name( "gnome crone", "�ؾ���̫��" );
	ob->add( "id", ({ "gnome", "crone" }) );
   ob->set_short( "�ؾ���̫��" );
	ob->set_long(
		"�㿴��һ����Ǭ�ֱ�ĵؾ���̫�ţ�������������ſ�ɹ�����⡣\n"
	);
	ob->set( "alignment", 850 );
	ob->set( "race", "gnome" );
	ob->set( "gender", "female" );
	ob->set_natural_armor( 25, 12 );
	ob->set_natural_weapon( 1, 4, 4 );
	ob->set_perm_stat( "int", 14 );
	ob->set_perm_stat( "pie", 14 );
	ob->set_skill( "dodge", 40 );
	ob->set_skill( "blunt", 20 );
	ob->set( "wealth/platinum", 1 );
	ob->wield_weapon( "/d/noden/item/quaterstaff" );
	ob->equip_armor( "/d/noden/item/hood" );
	ob->equip_armor( "/d/noden/item/sandal" );
}
