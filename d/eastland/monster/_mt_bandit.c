#include <mudlib.h>

void create(object ob)
{
	if ( ! ob ) return ;
	ob->set_level(6);
	ob->set_name( "mountain thief", "ɽ��" );
	ob->add( "id", ({ "thief", "bandit" }) );
	ob->set_short( "ɽ��" );
	ob->set_long(
		"���ɽ��һ����ͷ���Ե����ӣ��˳ɸո���ʲ�ỵ�»�����\n"
	);
	ob->set( "race", "human" );
	ob->set( "gender", "male" );
	ob->set( "alignment", -700 );
	ob->set_perm_stat( "str", 13 );
	ob->set_perm_stat( "dex", 8 );
	ob->set_perm_stat( "kar", 2 );
	ob->set_skill( "longblade", 40 );
	ob->set_skill( "parry", 40 );
	ob->set_skill( "dodge", 20 );
	ob->set( "hit_points", 200 );
	ob->set( "max_hp", 200 );
	ob->set( "wealth/gold", 25 );
	ob->set( "special_defense", (["all": 10 ]) );
	ob->set( "killer", 1 );
	ob->set( "pursuing", 1 );
	ob->set( "wimpy", 20 );
	ob->set_natural_weapon( 4, 4, 4 );
	ob->set_natural_armor( 20, 8 );

	ob->wield_weapon( "/d/eastland/obj/steel_blade" );
}
