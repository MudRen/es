#include "../legend.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "host", "男主人");
        set_short("男主人" );
	set_long(@C_LONG
男主人是一位俊美挺拔，风度翩翩的中年人，他的四肢百骇散发出一股仙气，全身
上下似乎被笼罩在一团暮霭里，这样的一位仙风道骨，使你不禁地想亲近他。在三
十多年前，男主人原本是一位江湖中颇负盛名的剑客，却在到达巅峰之际急流涌退
，一时令许多人错愕，并且佩服他的勇气。他现在处於隐居状态，但手上工夫依然
不弱哟，你可以跟他请教剑法，相信他会很乐意教你的。
C_LONG
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment",100 );
	set( "time_to_heal", 7 );
	set_natural_armor( 70 , 35 );
	set_natural_weapon( 34 , 13 , 13);
	set("max_hp",700);
	set("hit_points",700);
        set("max_fp",500);  
	set("force_points",500);
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex",25 );
	set_skill( "parry",80 );
	set_skill( "longblade",100);
	set("spouse","Hostress");
	set( "wealth/silver",200);
	set( "special_defense", ([ "all": 45, "none":30 ]) );
	set( "aim_difficulty",(["critical":70,"vascular":60,"weakest":50]) );
	set("couple",1);
        equip_armor(LARMOR"sun_ring");
        equip_armor(LARMOR"sun_amulet");
        wield_weapon(LWEAPON"phenix1");                                              
        set( "tactic_func", "my_attack" );
        set("inquiry", ([
                 "sword":"@@ask_sword",
                  "剑法":"@@ask_sword",
                 "first":"@@ask_first",
                 "second":"@@ask_second",
                 "third":"@@ask_third",
        ]) );
        set("scholar_gonfu/couples_sword",30);
        set("scholar_gonfu/han",30);
} 
void init()
{
   ::init();
   add_action("do_say","报告");
}
void ask_sword(object asker)
{
write(@C_LONG
男主人道：嗯，我夫妇两纵横江湖二十年，打败高手无数，惟恨遍访无人能传我毕
　　　　　身绝学，如果你想做为我夫妇的徙弟，那你必须完成我给你的三件事。
         ( first second & third)
C_LONG
      );
}
void ask_first(object asker)
{
write(@C_LONG
男主人道：第一件事：
　　　　　我以前的朋友「丐帮帮主　震八方」寄了封信给我希望我夫妇前去助他
　　　　　一臂之力，但因久未涉江湖，不知如何是好，既然你有心要成为我们的
　　　　　徒弟，那你就替我们帮他解决困扰，这样算是完成第一件工作。
C_LONG
      );
}
void ask_second(object asker)
{
write(@C_LONG
男主人道：第二件事：
          在此前去东五十里有个渔村，渔村里有需要帮助的人，你快去帮助他，
          他是我以前的恩人。喔，忘了告诉你，他是渔村的村长，而这是第二件
          工作。
C_LONG
      );
}
void ask_third(object asker)
{
write(@C_LONG
男主人道：第三件事：
          问我夫人吧。如果你完成了三件事，向我「报告 男主人」就可以了。
C_LONG
      );
}
int do_say(string arg)
{
   object me;
   if ( !arg || arg!="男主人" )
      return notify_fail("你要向谁报告?\n");
   me=this_player();
//      if( me->query_quest_level("couples") ) {
   if ( me->query("couples") ) {
      tell_object( me,"男主人说道：乖徒弟，你找为师的有什麽重要的事情吗？\n");
      return 1;
   }
//   if ( !( (me->query_quest_level("dony1"))&&
   if( !( (me->query("finish_dony")) &&
          (me->query_temp("second")) &&
          (me->query_temp("third") )    ) )  {
       tell_object( me,"男主人说道：再加把劲吧！\n");      
      return 1;             
   }          
//   me->finish_quest("couples", 1);
    me->delete_temp("second");
    me->delete_temp("third");
    me->set("couples",1);
    me->gain_experience(8000);
    tell_object( me,@C_LONG 
男主人道：好孩子，你终於不负所望完成我交待给你的三件工作。好，我就收你
　　　　　为徒吧！
         
      
      [你获得男主人的赏赐得到 8000 点经验]\n\n");

C_LONG
    ); 
     me->delete("blind");
     me->set("medication_resistance",0);
     if ( me->query("class")!="scholar" ) {
        tell_object( me,@C_LONG
男主人继道：唉，本来为师想传你一套剑法，但因你骨骼不佳，资质不够。也就作
　　　　　　罢了。
无论你百般地哀恳，男主人就是不传你剑法，你不禁伤心地叹了一口气。     
C_LONG             
     ); 
     return 1;
     }
     tell_object( me,@C_LONG
男主人摸了摸你全身的骨骼．．
男主人很满意地道：不错，你资质奇佳，足以学我夫妇俩纵横江湖十多年的剑法。

只见男主人杂七杂八地说了几句话，你却一点也不懂他在讲什麽．．．．
男主人看见你充满疑问的表情，愤怒地道：什麽，你连一句话也都没有记得，回公
　　　会好好想想(ponder)清楚吧！
C_LONG
     );
     return 1;
}
int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couple") ) return 1;
       return 0;
}
int my_attack()
{ 
   object *couples,victim;
   int i;

   if( !victim =query_attacker() ) return 0;
                        
   if( query("force_points") < 50 ) set("force_points",500);
   couples = filter_array( all_inventory(environment(this_object())),
           "can_help", this_object() );
   for( i=0; i<sizeof(couples); i++ ) {
      tell_room( environment(this_object()), sprintf(
          "%s怒道:我们岂是那麽好欺负的,给我下地狱去吧!!\n",couples[i]->query("c_name")),
          couples[i]);
      couples[i]->kill_ob(victim);
   }
   if ( !present("hostress",environment(this_object())) ) {
        set("attack_skill","scholar/han");                                    
        delete_temp("extra_db");
   }
   else set("attack_skill","scholar/couples_sword");
   return 0;
}
