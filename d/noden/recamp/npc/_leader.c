#include <mudlib.h>
void create(object ob)
{
        if (!ob) return ;
        seteuid(getuid()) ;

	ob->set_level( 5 );
	ob->set_name( "boarman leader", "Ұ��������" );
	ob->add( "id", ({ "boarman", "leader" }) );
        ob->set_short( "Ұ��������" );
	ob->set_long(
		"���Ұ���˳��úܡ����͡����������⣬�̶������۾�ȴ���������\n"
		"���������������֮�͡�\n"
	);
	ob->set( "gender", "male" );
	ob->set_perm_stat( "str", 8 );
	ob->set_perm_stat( "con", 8 );
	ob->set( "max_hp", 100 );
	ob->set( "hit_points", 100 );
	ob->set_skill( "axe", 50 );
	ob->set_skill( "parry", 30 );
	ob->set( "natural_armor_class", 20 );
	ob->wield_weapon("/d/noden/recamp/obj/axe");
	ob->equip_armor("/d/noden/recamp/obj/chainmail");
}
