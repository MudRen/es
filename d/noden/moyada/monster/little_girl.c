#include "../moyada.h"

inherit MONSTER;

void create ()
{
	::create();
	set_level(1);
	set_name( "little girl", "小女孩" );
	add( "id", ({ "girl", }) );
	set_short( "小女孩" );
	set_long( @C_LONG
看起来十分可爱的小女孩，一直对著你微笑。
C_LONG
	);
	set_perm_stat( "dex", 5 );
	set_perm_stat( "str", 5 );
	set_perm_stat( "int", 5 );
	set_perm_stat( "con", 5 );
	set_perm_stat( "piety", 5);
	set_perm_stat( "karma", 5);
   set( "race", "human" );
	set ("gender", "female");
	set ("unit", "个" );
	set_natural_weapon( 10, 5, 10 );
	set_natural_armor( 10, 10 );
	set_skill("dodge",100);
    set("weight", 300);
    set("exp_reward",1);
    set("immortal" ,1);
}

void change( object what, object player )
{
    object ob;
    ob = new( MOYADA"monster/daemon" );
    ob->move( environment(what) );
    tell_object( player,@ALONG
     
小女孩大叫一声: 可恶! 竟被你识破了，只好现出我的真面目!
小女孩突然摇身一变成一只可怕的恶魔。
  恶魔大叫一声: 受死吧!

ALONG
      );       
    player->set_explore("noden#6");
    ob->kill_ob(player);
    player->kill_ob(ob);
    what->remove();
}
