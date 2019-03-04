#include <mudlib.h>

void create(object ob)
{
    if ( !ob ) return ;
	ob->set_level(13);
	ob->set_name( "troll", "ɽ�����" );
	ob->set_short( "ɽ�����" );
	ob->set_long(
		"����ִ��ֱ��ľ��������������չ�·�ѡ�\n"
	);
	ob->set_perm_stat( "str", 28 );
	ob->set_perm_stat( "dex", 10 );
	ob->set_perm_stat( "int", 10 );
	ob->set_skill( "chain", 70 );

	ob->set( "natural_armor_class", 30 );
	ob->set( "natural_defense_bonus", 5 );
	ob->set( "time_to_heal", 2 );
	ob->set( "max_hp", 600 );
	ob->set( "hit_points", 600 );
	ob->set( "gender", "male" );
	ob->set( "alignment", -800 );
	ob->set( "wealth/silver", 400 );

	ob->set( "chat_chance", 15 );
	ob->set( "chat_output", ({
		"ɽ�����˵��: ������С�ӣ�\n",
		"ɽ�����˵��: ��Ǯ����������Ȼ�е����ܵġ�\n",
		"ɽ�����˵��: �Ҳ����ڿ���Ц���������ϵ�Ǯȫ����������\n"
	}) );

	ob->wield_weapon("/d/noden/item/morning_star");

	ob->equip_armor("/d/noden/item/wolf_hide");
}
