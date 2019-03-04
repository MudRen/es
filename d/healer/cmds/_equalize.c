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
	  tell_object( player,"������忪ʼ��������.....\n");
      if( random(110) > bal_skill || random(100) > con_skill ) {
        tell_object(player,
          "��������޷�����ƽ��󷨵�ѹ��,��ʧ����.\n"
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
      tell_object(player,"...һ���ʹ����,�������ƽ��.\n");
      tell_room(environment(player),
         player->query("c_name")+"�ƺ��ӳ�����˼��������.\n", player );
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
     tell_object(player,"���˼�����ٶȼ���,���������ܹ�ʩչƽ�����.\n");
}

int cmd_equalize()
{
	int bal_skill, con_skill,hp, dex, parry, block, dodge,cost_exp;

	bal_skill = (int)this_player()->query_skill("balance");
	con_skill = (int)this_player()->query_skill("concentrate");
	if( !bal_skill || !con_skill ) 
	   return notify_fail(
		"�㲻�˽�ƽ��ļ��ɣ�����޷�ȡ�������뷨���ľ����.....��\n");
	cost_exp = ((int)this_player()->query_level()) * 10 +
	           bal_skill + con_skill;
	cost_exp *= 10;
	if ( this_player()->query_temp("balancing") )
	  return notify_fail("��ľ�����δ�ָ�,������һ���.\n");

	if( this_player()->query_exp_stock() < cost_exp ) 
	    return notify_fail(
		"ƽ�����ҪһЩ����ֵ����,����ȱ����......��\n");
    
	write("������۾������о��񣬿�ʼʩչƽ���....��\n");
	tell_room( environment(this_player()),
		this_player()->query("c_name")+ "�������۾�,Ȼ��ר���ĳ�����ϡ�\n",
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

    ƽ���Ǹ�ҽ�������ָ�����������Ҫ��������������һ���ľ���ֵ���������;�����
ƽ�⡣��������ʩչƽ����ᣬ����һС��ʱ���޷����о�������ζ�����޷�ƽ�⣬
��ģ�����׼�����ң�������������̫�ͣ�����ǿҪʩչƽ��󷨵Ļ������п��ܱ���
���޳���ȥ���͡���ǧ��ע�⡣    
HELP
	);
    return 1;
}
