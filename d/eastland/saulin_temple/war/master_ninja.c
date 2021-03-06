#include <saulin_war.h>

inherit War;

void create()
{
        ::create();
        set_level(19);
        set_name( "Ninja master", "狂风小次郎" );
	add( "id", ({ "master","ninja", }) );
        set_short( "狂风小次郎" );
        set_long(@C_LONG
你看到一个全副武装的忍者头目，他就是迎风一刀流的门主－狂风小次郎
，这个生性贪婪狂妄的忍术高手向来觊觎少林寺武功\以久，一有机会就想
上山浑水摸鱼。
C_LONG
                );
	set( "unit", "名" );
        set( "race", "human" );
        set( "gender", "male" );
        set( "alignment", -2000 );
        set_natural_armor(50,30);
        set_natural_weapon(15,12,15);
        set( "natural_weapon_class2", 8 );
        set( "natural_min_damage2", 5 );
        set( "natural_max_damage2", 10 );
        set( "wealth/silver", 400 );
        set( "hit_points", 650 );
        set( "max_hp", 650 );
        set( "special_defense", ([ "all": 40,"none":20 ]) );
        set( "aim_difficulty",
        ([ "critical":20, "vascular":20, "weakest":30, "ganglion":15 ]));

        set( "pursuing", 1 );
        set( "killer", 1 );
        set( "monk_value", 100 );
        set_perm_stat( "str", 28 );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "int", 25 );
        set_skill( "longblade", 100 );
        set_skill( "two-weapon", 100 );
        set_skill( "parry", 100 );
        set_skill( "defend", 100 );
        set( "chat_chance", 20 );
	set( "att_chat_output", ({
	"狂风小次郎冷笑道: 快把武功\宝典献出来，否则要格杀勿论的斯！\n",
	"狂风小次郎狂笑道: 就凭你这点能耐，我小次郎会告诉你忍者的武术才是大大的好。\n",
	"狂风小次郎说道: 就凭我这迎风一刀流忍术，就是东方第一的啦！\n",
	}) );

        wield_weapon2(Obj"evil_katana");
        wield_weapon(Obj"bloody_claw" );
	equip_armor(Obj"ninja_cape");
        equip_armor("/d/noden/bluesand/item/yoroi");
        equip_armor("/d/noden/bluesand/item/kabuto");
        equip_armor(Obj"ninja_gloves");
}
