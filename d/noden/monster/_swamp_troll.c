#include <mudlib.h>

void create(object ob)
{
    if ( !ob ) return ;
	ob->set_level(16);
	ob->set_name( "swamp troll", "�������" );
	ob->add( "id", ({ "troll" }) );
   ob->set_short( "�������" );
	ob->set_long(
		"������ͷ������������������͸����Ƥ���ϸ�����һ������ɫ���Һ��\n"
	);
	ob->set_perm_stat( "str", 30 );
	ob->set_perm_stat( "dex", 12 );
	ob->set_perm_stat( "int", 12 );
	ob->set_skill( "blunt", 60 );

	ob->set_natural_armor( 60, 20 );
	ob->set_natural_weapon( 10, 10, 10 );
	ob->set( "time_to_heal", 2 );

	ob->set( "max_hp", 900 );
	ob->set( "hit_points", 900 );

	ob->set( "gender", "male" );
	ob->set( "alignment", -1600 );
	ob->set( "wealth/gold", 100 );

	ob->wield_weapon("/d/noden/item/club");
}
