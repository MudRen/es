#include <mudlib.h>

void create(object ob)
{
        if ( !ob ) return ;
	ob->set_level(4);
	ob->set_name("bandit", "强盗");
	ob->set_short("强盗");
	ob->set_long(
		"这个人满脸横肉，一副凶神恶煞的样子，如果你不想打架的话\n"
		"最好离他远一点。\n"
	);
	ob->set( "unit", "名" );
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
		"强盗说道: 此路是我开，此树是我栽，要想从此过，留下买路财！\n",
		"强盗伸手把你向後推了几步。\n",
		"强盗脸露狞笑，大声说: 把所有的钱留下来，不然老子割你脖子！\n"
	}) );
	ob->set( "att_chat_output", ({
		"强盗大叫大跳，气得吹胡子瞪眼睛。\n",
		"强盗大喝: 小子！你真的不要命了吗？\n",
		"强盗欺身上前，想要掐住你的脖子。\n"
	}) );

	ob->wield_weapon("/d/noden/item/short_sword");
	ob->equip_armor("/d/noden/item/wooden_shield");
}
