#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(5);
   set_name( "guey mother", "桂老妈" );
   add( "id", ({ "guey", "mother" }) );
   set_short( "桂老妈" );
	set_long(
        "你看到一位年约四十的中年妇人, 她不断地唉声叹气, 不知为何所苦.\n"
	);
   set( "gender", "female" );
	set( "race", "human" );
   set_perm_stat( "dex", 8 );
   set_skill( "dodge", 50 );
   set( "natural_weapon_class1", 15 );
   set( "natural_min_damage1", 12 );
   set( "natural_max_damage1", 25 );
   set( "wealth/copper", 10 );
   set( "chat_chance", 12 );
   set( "chat_output", ({
        "桂老妈叹道: 我可怜的女儿, 你怎麽狠心丢下老妈?\n",
        "桂老妈自语: 老爹(dad)又出去了!\n"
	}) );
   set( "inquiry", ([
        "sheaumei" : "唉..........\n",
        "daughter" : "唉..........\n",
        "dad" : "老爹大概又去女儿的坟前了.\n"
     ]) );
}
