#include "../takeda.h"
#include "/include/move.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Silver Dragon","银甲神龙" );
	add ("id", ({ "dragon" }) );
	set_short( "dragon","银甲神龙");
	set("unit","尾");
	set_long(@C_LONG
这是一条有著美丽银色鳞甲的巨龙，背上有著巨大且锐利的背甲
在传说中它是具有不可思议力量的善良灵兽，任何武器只要浸入它的鲜血
就可以提升武器力量数倍。据说很久以前有个叫雷思的武士曾得到它的血
而制成龙血枪。
C_LONG	   
	);
	set( "likefish",1);
	set( "unbleeding",1);
	set("alignment",2700);
	set("max_hp",800);
	set ("time_to_heal", 1);
	set("hit_points",800);
	set_perm_stat("str", 30 );
	set_perm_stat("dex", 23 );
	set_perm_stat("kar", 25 );
	set_skill("dodge",100);
	set_natural_weapon( 80, 45, 72 );
	set_natural_armor( 130,60 );
	set ("gender", "male");
	set ("race", "monster");
	set_c_limbs(({"坚硬的背部","前颈","粗大的长尾","头部"}));
	set_c_verbs( ({"%s挥舞龙爪抓向%s","%s龙吟一声，龙尾狂扫向%s",
	"%s张嘴，一道火□喷向%s"}));
        set ("tactic_func","special_attack");
        set( "inquiry", ([
              "laice" : "@@ask_laice",
              "blood" : "@@ask_blood",
              "dragon" : "@@ask_dragon",
              "snake" : "@@ask_snake",
              "help" : "@@ask_help",
              "chiyu" : "@@ask_chiyu",
              "蚩尤" : "@@ask_chiyu",
              ]));
}
void ask_laice()
{
write (
      "银甲战龙突然很生气的样子，骂道: 那个该死的家伙，说好要帮助我的，\n"
      "当我用自己的血(blood)强化他的武器後，他就不知所踪了?\n");
      return ;
}

void ask_blood()
{
      write (
      "银甲战龙说道: 自从上次被雷思骗过之後，我再也不帮助任何人了！\n"
      "想要我的血，除非把我杀了，你要有兴趣就来吧....\n"
      "说完，银甲战龙用鼻子向你脸上吹气。\n");
      return ;
}
void ask_dragon()
{
      write (
      "银甲战龙说道: 龙是这世界最强大的生物....我的祖先就是传说中的应龙...\n"
      "它曾帮助黄帝打败蚩尤...\n" );
      return ;
}
void ask_snake()
{
      write (
      "银甲战龙说道: 你见过那条烂蛇吗? 他是传说中蚩尤的手下九婴的後代。\n");
      return ;
}

void ask_help()
{
      write("我该相信你吗? 银甲战龙怀疑的看著你......\n");
      call_out("ask_help2",10,this_player());
      return ;
}
void ask_help2()
{
      if ( this_player()->query("alignment") > 0 ) {
      write(@C_LONG
银甲战龙说道: 好吧，看你也不像个坏人，我就姑且相信你吧...
传说中蚩尤(chiyu)在屯鹿战死之後，他的手下九婴逃到这个山洞，
秘密进行让蚩尤复活的阴谋，而被我祖应龙发现了，於是它也进入这
个山洞并在这儿布下结界以暗地进行破坏的任务，并将这个任务传承
给它的子孙们。
C_LONG
            );
            call_out("ask_help3",10,this_player());
            return ;
            }
      write("你是坏人，一定是那只烂蛇的手下....快滚开.....\n"
            "说完作势欲扑.....\n");
            return ;
}
void ask_help3()
{
       write(@C_LONG
这麽多年来，由於我的祖先们的努力，那些邪恶的东西始终没能找到
使蚩尤复活的关键物－[ 蚩尤的遗骸 ]，但最近我无意中得知，目前九婴      
的後代具有极强的黑魔法能力，而它目前正在开发强力的定位搜寻魔法。
若是被它开发成功，不只我们这里有危险，更可能被它先发现蚩尤的遗骸
到时若蚩尤复活，这世界就完了....
C_LONG
       );
             call_out("ask_help4",10,this_player());
             return ;
}
void ask_help4()
{
        write(@C_LONG
目前的当务之急是，在它们开发出定位搜寻魔法前，先找到蚩尤的遗骸
并且带到我这里来，如果你能作到这件事，我将会尽我所能的回报你
千万不要试著挑战那只大蛇，如果你把它消灭掉，这个洞可能会发生危险
而这会使我失去了追踪它们的线索....
你听了它的话，心里有点想帮助它，但又不知是否适当
不管怎麽说，先回去报告公孙先生你的发现似乎比较恰当...
C_LONG
              );
        this_player()->set_temp("find_something",1);
        return ;
}              
void ask_chiyu()
{
write("蚩尤是上古时的大魔头，为了争夺天下的霸权，与黄帝大战於屯鹿之野。\n"
      "而这附近就是古时候的屯鹿....\n");
      return ;
}
void die()
{  
   object ob1,killer;
   
   killer = query("last_attacker");
   ob1 = killer->query("weapon1");
   if( !killer ) {
     ::die();
     return;
   }
   if( !ob1 ) {
     ::die();
     return;
   }
   tell_room(environment(this_object()),
      killer->query("c_name")+"一声大吼，将手中的"+ob1->query("c_name")+"向银甲战龙用力插去...\n"+
      "\n银甲战龙狂吼不已，隆隆之声不绝於耳，转头对"+killer->query("c_name")+"发出它临终一击 ！\n\n\n");
      killer->set("hit_points",10);
      "/d/magic/magic"->report( this_object(), killer );
   tell_room(environment(this_object()),
      "尽力一击後，战龙终於不支，吐血倒地而亡....\n"+
      killer->query("c_name")+"将插在战龙□体上的"+ob1->query("c_name")+
      "拔出，顺手把上面的血迹擦拭乾净。\n"      
      );
   ob1->add( "min_damage",5 );
   ob1->add( "max_damage",5 );
   ::die();   
}
void announce( string msg, string c_msg )
{
	object *usr;
	int i;

	usr = users();
	for( i=0; i<sizeof(usr); i++ ) {
		if( !environment(usr[i]) ) continue;
		tell_object( usr[i], can_read_chinese(usr[i])? c_msg: msg );
	}
}
       
       
int special_attack()
{// 10% use it! damage 30-50.
    object env,*inv,*victim;
    int i;
    env=environment(this_object());
    inv=all_inventory(env);
    if(random(10)<8) return 0;
    tell_room( environment( this_object() ), 
      "\n\n [1;41m 银龙喷出一团炙热炼火，烧得所有人如处於炼狱般． [0;40m \n\n\n" ,
      this_object()
    );
    this_object()->receive_healing(10);
    i = sizeof(inv);
    while(i--) {
      if (inv[i]!=this_object()) 
        {
           inv[i]->receive_special_damage("fire",random(20)+30);
           "/d/magic/magic"->report( this_object(), inv[i] );
        }
    }
    return 1;
}

