//#pragma save_binary
// _equalize.c
// This command is for healers to recover spells from hitpoints and experience
// by Echobomber@Eastern.Stories (2-5-94)
#include <mudlib.h>

inherit DAEMON;

void do_balance( object player, int bal_skill,int con_skill, int degree )
{
	int mana, maxhp, hp, cost_exp;
    if(!degree) {
	  //if( (int)player->query_exp_stock() < (int)player->query_level()*15 )
	  tell_object( player,"你的身体开始发抖不已.....\n");
      if( random(110) > bal_skill || random(100) > con_skill ) {
        tell_object(player,
          "你的身体无法承受平衡大法的压力,你失败了.\n"
        );
       	if( !wizardp( player ) ) {
       		player->set_temp("block_defense",0);
		    player->set_temp("block_command",0);
		    player->set_temp("block_message",0);
	    }
        player->receive_damage( random((int)player->query_level()*2) );
        call_out("re_balance", (int)player->query_level()*5 , player);
        return;
      } else
        call_out("do_balance",2,player,bal_skill,con_skill,1);
    } else {
      mana = (int)player->query("spell_points");
      hp = (int)player->query("hit_points");
      maxhp = (int)player->query("max_hp"); 
	  if( !wizardp( player ) ) {
	  	  player->set_temp("block_defense",0);
		  player->set_temp("block_command",0);
		  player->set_temp("block_message",0);
	  }
      player->set("hit_points",(hp+mana)/2>maxhp ? maxhp : (hp+mana)/2 );
      player->set("spell_points",(hp+mana)*2/5-(100-bal_skill)/10 );
      tell_object(player,"...一阵的痛苦中,你完成了平衡.\n");
      tell_room(environment(player),
         player->query("c_name")+"似乎从长长的思考中醒来.\n", player );
      cost_exp = ((int)this_player()->query_level()) * 10 +
	             bal_skill + con_skill;
	  cost_exp *= 10;
      player->gain_experience( -cost_exp );
      call_out("re_balance",(int)player->query_level()*8,player);
      return;
    }
}

void re_balance(object player)
{
     player->set_temp("balancing", 0);
     tell_object(player,"你的思考力再度集中,你现在又能够施展平衡大法了.\n");
}

int cmd_equalize()
{
	int bal_skill, con_skill,hp, dex, parry, block, dodge,cost_exp;

	bal_skill = (int)this_player()->query_skill("balance");
	con_skill = (int)this_player()->query_skill("concentrate");
	if( !bal_skill || !con_skill ) 
	   return notify_fail(
		"你不了解平衡的技巧，因此无法取得体力与法力的均衡点.....。\n");
	cost_exp = ((int)this_player()->query_level()) * 10 +
	           bal_skill + con_skill;
	cost_exp *= 10;
	if ( this_player()->query_temp("balancing") )
	  return notify_fail("你的精神尚未恢复,你必须等一会儿.\n");

	if( this_player()->query_exp_stock() < cost_exp ) 
	    return notify_fail(
		"平衡大法需要一些经验值辅助,而你缺乏它......。\n");
    
	write("你闭上眼睛，集中精神，开始施展平衡大法....。\n");
	tell_room( environment(this_player()),
		this_player()->query("c_name")+ "闭上了眼睛,然後专心於某件事上。\n",
		this_player() );
	this_player()->set_temp("balancing", 1);
    if( !wizardp( this_player() ) ) {
      this_player()->set_temp("block_defense", 1 );
	  this_player()->set_temp("block_command", 1 );
	  this_player()->set_temp("block_message", 1 );
	}
	call_out( "do_balance", 3, this_player(), bal_skill ,con_skill, 0);
	return 1;
}

int help()
{
    write(@HELP
Syntax: equalize

    平衡是给医生用来恢复精神力的主要方法，它会消耗一定的经验值和体力来和精神力
平衡。而且在你施展平衡大法後，将有一小段时间无法集中精神。这意味著你无法平衡，
针灸，和瞄准。而且，如果你的生命力太低，而你强要施展平衡大法的话，你有可能被黑
白无常请去作客。请千万注意。    
HELP
	);
    return 1;
}
