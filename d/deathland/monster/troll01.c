
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(15);
	set_name( "troll", "����" );
//	add ("id", ({ "troll", }) );
	set_short("����" );
	set_long(
//	"A aggressive troll \n",
    "һ������Ѱ��ʳ��ľ��ˡ�\n"
        );
    set("special_defense",(["monk":10]));
    set("aggressive",1);
    set("alignment",-700);
    set("time_to_heal",4);
    set( "gender", "male" );
    set( "race", "troll" );
    set( "unit", "��" );
    set("max_hp",650);
    set("hit_points",650);
	set_perm_stat( "str", 26 );
	set_perm_stat("int",9);
	set ("wealth", ([ "silver": 1]) );
	set_natural_weapon(20,12,18);
	set_natural_armor(74,0);
    set ("weight", 300);
    set ("chat_chance", 25);
    set ("chat_output",({
//         "Giant yell and try to catch you!!\n",
         "���˴�:ʳ��!!!!Ȼ������ȥץס�� !!\n"
        }) );
    set ("alignment",-400);
    set_skill("blunt",70);
	wield_weapon(Weapon"/club01");
  	set("alt_corpse",Object"/trollcorpse");	
}

