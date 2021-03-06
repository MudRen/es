#include "../legend.h"

string *cast_msg1=
     ({ "%s开始凝聚空气中的风因子在他的周围形成巨大的暴风！\n",
        "%s口中开始冒出阵阵的白烟，喷出些微火星!\n",
        "%s喃喃自语，空气中的光因子不断地聚集!\n" }),
       *cast_msg2=
     ({ "%s身旁的暴风急速地往众人面前刮过，你感到一阵火辣辣的刺痛！\n\n",
        "\n%s口中大喊「三昧真火」，□天烈焰往你身上浇去，使你炙痛难当!\n\n",
        "%s周围一道强大的光量笼罩著整个房间!\n\n\n\n" }) ;
inherit MONSTER;
void create()
{
	::create();
	set_level(18);
	set_name( "fisher captain","村长" );
	add ("id", ({"captain"}) );
	set_short("渔村 村长");
	set_long(@C_LONG
村长年约四、五十岁，一副绅士的样子，看起来蛮友善的，可是，他一发起脾气来
是非常恐怖的；他的臂力，据说可以打死九头牛；他的吼声，震死六只大象都绰绰
有馀；所以，你最好不要招惹他哟。村长同时是村里最具有权威的人，平时掌管渔
村里头大大小小的事务，可说是非常忙碌。村长最近在跟老渔翁学习一些东西，当
然，如果能因此改改他的脾气，那是再好不过的。村长现在愁眉沈锁，似乎遇到了
什麽麻烦了。
C_LONG
	);
	set( "unit", "名" );
	set_perm_stat( "str", 27 );
	set_perm_stat( "dex", 24 );
	set_perm_stat( "kar", 30 );
        set("weight",900);
        set_skill( "unarmed-parry", 80);
	set_skill( "dodge", 80 );
	set("max_sp",2700);
        set("spell_points",2700);
	set_temp("be_joke",100);
	set("hime_to_heal",4);
	set( "special_defense", ([ "all": 50,"none":50,
	"monk":40,"scholar":20]) );
	set( "stun_difficulty",50);                                              
	set("aim_difficulty", 
	   ([ "critical":100, "vascular":60, "ganglion":70, "weakest":30 ]) );
	set( "gender", "male" );
	set( "race", "human" );
	set("max_hp", 900);
	set("hit_points",900);
	set_natural_armor( 60,35 );
	set_natural_weapon( 72,29,55);
        set_temp("detect_hide",1);
        set_temp("detect_invi",1);
        equip_armor(LARMOR"fish_cloth");
//	set( "tactic_func", "my_tactic" );
        set( "inquiry", ([
             "trouble":"@@ask_trouble",
                "麻烦":"@@ask_trouble" 
        ]) );
}
void ask_trouble(object asker)
{
   if ( asker->query_temp("second") ) {
      tell_object(asker,"村长很伤心地哭著。\n");   
      return ;   
   }
   if ( asker->query_temp("captain_asked") ) {
      tell_object(asker,"村长道：拜托你了。\n");
      return ;
   } 
   asker->set_temp("captain_asked",1);
write(@C_LONG
村长道叹了一口气道：唉，我本有个青梅竹马的女友，己经到了论及婚嫁的程度，活
　　　　　在爱情的滋味里是那麽地美好，我深信，当时的我应该是我一生中最快乐
　　　　　的时光。不幸地，有一天，当她一个人信步地走在海堤上，猛地，一个大
　　　　　浪把她给卷到了海里去，事後，我派过无数不乏精通水性的人去寻找她的
　　　　　纵迹，却一直音讯全无，至今不知是生亦或者是死。唉！二十多年以来，
　　　　　我茶不思饭不想，无时不刻不念及她，现在，我愿奉献我所有的一切，只
　　　　　为能换得她一丝的容颜。少侠，你能帮我去找寻她吗？唉．．．

村长喃喃自语道：「小渔，小渔，你知道我是多麽地想念你吗．．．
C_LONG
     );
} 
int my_tactic()
{
    object victim,env;
    string mob_name,msg1,msg2,type;
    int damage;
    if ( !victim=query_attacker() ) return 0;
    env=environment(this_object());
    mob_name=query("c_name");
    switch( random(50) ) {
    case 1..5:
       msg1=set_color(cast_msg1[0],"HIB");
       tell_room(env,sprintf(msg1,mob_name));
       msg2=set_color(cast_msg2[0],"HIB");    
       type="energy";
       damage=55+random(10);
       call_out("cast_run",3,type,msg2,mob_name,damage);
       break;
    case 6..10:
       msg1=set_color(cast_msg1[1],"HIR");
       tell_room(env,sprintf(msg1,mob_name));
       msg2=set_color(cast_msg2[1],"HIR");
       type="fire";
       damage=80+random(25);
       call_out("cast_run",5,type,msg2,mob_name,damage);
       break;
    case 11..15:
       msg1=set_color(cast_msg1[2],"HIY");
       tell_room(env,sprintf(msg1,mob_name));
       msg2=set_color(cast_msg2[2],"HIY");
       type="electric";
       damage=65+random(20);
       call_out("cast_run",4,type,msg2,mob_name,damage);
       break;
    }
    return 0;              
}
void cast_run(string type,string msg,string mob_name,int damage)
{
   object env,*all;
   int i;
   env=environment(this_object());
   all=all_inventory(env);
   tell_room(env,sprintf(msg,mob_name));
   for (i=0;i<sizeof(all);i++)
      if ( all[i]!=this_object() ) 
         all[i]->receive_special_damage(type,damage);      
}
void relay_message(string class, string msg)
{

     string who, str;
     object player;

     ::relay_message(class, msg);
     if( sscanf( msg, "%s(%s)走了进来。", str,who )==2 ) {
     if( !player = find_player(lower_case(who)) ) return;
     if( !player->query_temp("wife_asked") ) return ;
     player->delete_temp("wife_asked");
     player->delete_temp("captain_asked");
     player->set_temp("second",1);
     tell_object(player,@C_LONG
村长看见你带来给他「少女小渔」已死的讯息不由得痛哭了一场，了了不能自己．．

你看他哭成这样子，不忍心去打扰他。你不禁感叹，唉！真是造化弄人，倘若可使有
情人终成眷属，也许，世上会少了一半伤心的人了。　

C_LONG
     );                                                               
     }
}