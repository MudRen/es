#include <mudlib.h>
void create(object ob)
{
        if (!ob) return ;
        seteuid(getuid()) ;

	ob->set_level( 4 );
	ob->set_name( "boarman shaman", "Ұ������ҽ" );
	ob->add( "id", ({ "boarman", "shaman" }) );
        ob->set_short( "Ұ������ҽ" );
	ob->set_long(
		"��....��....������������û�д�Ļ�����λҰ�������Ǹ���Ů�ˣ���\n"
		"��Ƥ��������ͬ��ף�����ë�Ƚ��٣����ٲ����ϵ���ë�Ƚ϶�....��\n"
	);
	ob->set( "gender", "female" );
	ob->set_perm_stat( "str", 5 );
	ob->set_perm_stat( "dex", 7 );
	ob->set( "max_hp", 80 );
	ob->set( "hit_points", 80 );
	ob->set_skill( "blunt", 40 );
	ob->set_skill( "parry", 30 );
	ob->set( "natural_armor_class", 15 );

	ob->wield_weapon("/d/noden/recamp/obj/staff");
	ob->equip_armor("/d/noden/recamp/obj/cloak");
}
