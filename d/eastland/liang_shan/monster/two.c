#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(11);
	set_name( "Zhuan Shiao Er", "阮小二" );
	add("id",({"zhuan","shiao","er"}));
	set_short( "阮小二" );
	set_long(
		"阮小五外号立地太岁，小五，小七是他弟弟，本以打鱼维生，兄\n"
		"弟三人随吴用落草，现俱为水军头领．他现在似乎急著在找什麽东西。\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -200 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 21 );
	set_perm_stat( "kar", 11 );
	set_skill( "shortblade", 50 );
	set_skill( "parry", 15 );
	set_skill( "dodge", 50 );
        set( "inquiry" ,([
        "shell" : "@@ask_shell"]));
	set( "wealth/gold", 20 );
	set( "special_defense", (["all": 17 ]) );
	set_natural_weapon( 8, 8, 8 );
	set_natural_armor( 25, 8 );

	wield_weapon( TWEAPON"fishman_dagger" );
        equip_armor( TARMOR"hat");
        equip_armor( TARMOR"fish_skin");
}
void ask_shell()
{
write(
"阮小二叫道: 就是它，湖边渔民传说中的千年大河蚌，竟然真的存在，我已经和它缠斗\n"
"一天了，但它似乎还是没伤到要害?? 你能帮我解决掉他吗??\n");
return 0;
}