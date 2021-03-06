#include "../../story.h"
#include "../../magic.c"
inherit MONSTER ;
void create ()
{
	::create();
        set_level(19);
        set_name( "The King Huang", "黄帝" );
        add ("id", ({"king","huang","Huang"}) );
        set_short( "中央天帝 黄帝 [骑在一只[1;32m□[1;36m□[0;37m[1;32m□[1;36ms[m上]");
	set_long(@CLONG
黄帝生得身材修长，双手过膝，粉面朱□，细眉凤目，两耳垂珠，鼻似琼瑶，一身
穿著极为乾净，远望极具威仪，细看是一彬彬文生，分别给人不同的感觉。黄帝是
天界众神的管理者，具有无上权威，他在馀暇常常喜欢在後花园里游玩。  　　
CLONG
	);
	set("exp_reward", 55555 );
	set("race","god");
	set("gender","male");
	set_perm_stat("str", 30 );
        set_perm_stat("dex", 30 );
        set_perm_stat("kar", 30 );
        set_perm_stat("int", 30 );
	set_temp("detect_hide",1);
	set( "alignment", 3000 );
	set( "hit_points", 3000 );
	set( "max_hp", 3000 );
        set( "max_fp",500);
	set_natural_weapon( 28, 25, 37 );
	set_natural_armor( 83, 49 );
        set("aim_difficulty",([ 
    	  "critical":70,"vascular":70,"weakest":50 ]) );
        set("wealth/gold",400);
        set("stun_difficulty",100);
        set("conditions/_heal_hp",({ 3 , 1 }) ) ;
        set_skill("two-weapon",100);
        set_skill("longblade",100);
        set_skill("block",100);
        set_skill("parry",100);
        set_skill("longblade",100);
        set("tactic_func","my_tactic");
        wield_weapon(SPWEA"dragonsword");
        equip_armor(SPARM"god_shield");
        equip_armor(SPARM"god_gloves");
        equip_armor(SPARM"god_amulet");
        equip_armor(SPARM"god_helmet");
        equip_armor(SPARM"god_cloth");
        equip_armor(SPARM"god_ring");
        set("tactic","assault");
        set("Hking",1);
        set("special_defense",(["all":50,"none":50]));
}
int can_help( object ob )
{
   if ( !living(ob) ) return 0;
   if ( ob->query("servant") ) return 1;
      return 0;
}
         
int stop_attack()
{
   int i,max;
   object *tmp, env, *atk;
   
   this_player()->set_temp("kill_huang",1);              
   env=environment();
   atk=filter_array(all_inventory(env),"can_help",this_object());
   max=sizeof(atk);
   for ( i=0;i<max;i++ ) {
        tell_room( env,sprintf("%s冲到黄帝面前，开始保护他!!\n"
          ,atk[i]->query("c_name")) );
        tmp = query_temp( "protectors" );
        if( !tmp || member_array( atk[i], tmp )==-1 ) {
            add_temp( "protectors", ({ atk[i] }) );
            atk[i]->add_temp( "protectees", ({ this_object() }) );
        }
        atk[i]->kill_ob(this_player());
   }
   return 0;
}
void king_hurt_all(object env)
{
   int i,max;
   object *itk;
   itk=all_inventory(env);
   max=sizeof(itk);
   for (i=0;i<max;i++)
      if ( living(itk[i]) && !itk[i]->query("Hking") )
         itk[i]->receive_damage(80);
}
void king()
{
   object inv,temp1;
   temp1=find_object_or_load(SPALACE"garden5");
   inv=environment(this_object());
   tell_object(inv,"\n黄帝大吼一声震得你魂飞魄散！！\n\n\n");
   tell_object(temp1,"忽然从凉亭处传来一阵嘶吼！\n");
   king_hurt_all(inv);
   king_hurt_all(temp1);
}
int my_tactic()
{
    int i;
    object victim;
    
    if ( !victim=query_attacker() ) return 0;
    switch( random(25) ) {
    case 0    : 
                tell_object(victim,"\n黄帝大喊：邪灵附身邪灵附身！\n\n");
                damn_player(victim);
                return 1;
    case 1..4 : king();
                return 1;
    default :   return 0;          
    }
}
void die()
{
    object dragon;
    dragon=new(SPMOB"dragon1");
    dragon->move(environment());
    ::die();
}
