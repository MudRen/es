#include <mudlib.h>

void create(object ob)
{
        if ( !ob ) return ;
	ob->set_level(4);
	ob->set_name("bandit", "ǿ��");
	ob->set_short("ǿ��");
	ob->set_long(
		"������������⣬һ�������ɷ�����ӣ�����㲻���ܵĻ�\n"
		"�������Զһ�㡣\n"
	);
	ob->set( "unit", "��" );
	ob->set_perm_stat("str",6);
	ob->set_perm_stat("con",8);
	ob->set_skill("shortblade", 50 );
	ob->set( "race", "orc" );
	ob->set( "gender", "male" );
	ob->set( "wealth/silver", 10 );
	ob->set( "natural_armor_class", 30 );
	ob->set( "alignment", -500 );

	ob->set( "chat_chance", 5 );
	ob->set( "chat_output", ({
		"ǿ��˵��: ��·���ҿ������������ԣ�Ҫ��Ӵ˹���������·�ƣ�\n",
		"ǿ�����ְ����������˼�����\n",
		"ǿ����¶��Ц������˵: �����е�Ǯ����������Ȼ���Ӹ��㲱�ӣ�\n"
	}) );
	ob->set( "att_chat_output", ({
		"ǿ����д��������ô����ӵ��۾���\n",
		"ǿ�����: С�ӣ�����Ĳ�Ҫ������\n",
		"ǿ��������ǰ����Ҫ��ס��Ĳ��ӡ�\n"
	}) );

	ob->wield_weapon("/d/noden/item/short_sword");
	ob->equip_armor("/d/noden/item/wooden_shield");
}
