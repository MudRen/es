#include "../../story.h"

inherit MONSTER;
int atk=0;
void create()
{
	::create();
	set_level(18);
	set_name( "The captain of policeman Sha","夏侯忍" );
	add( "id", ({ "captain","sha"}) );
	set_short( "京城四大名捕 夏侯忍" );
	set_long(@C_LONG
这是统领著「巫咸城」城内所有捕快的头领。他身材魁武，皮肤拗黑，脸长著鹰勾
鼻、阔嘴和一对鹰眼，其目光锐利已极，外表冷酷无比。夏侯忍是天下四大名捕之
一，他为人老练，功夫高强，智慧深沈，极富谋略，是个相当可怕的对手，现在正
在客栈里小憩饮酒吃些东西，手中武器仍不离身。
C_LONG
        );
	set( "gender", "male" );
	set("unit","位");
	set( "alignment", 400 );
        set_perm_stat( "str", 28 );
        set_perm_stat( "dex", 28 );
        set_perm_stat( "int", 28 );
        set_skill( "parry", 90 );
        set_skill( "thrusting", 90 );
        set_skill( "dodge", 90 );
        set("wealth/silver",1000);
        set("max_hp", 750);
        set("hit_points",750);
        set("max_fp",400);
        set("weight",900);
        set("special_defense", ([ "all":100,"none":5,"evil":50]) );
        set("aim_difficulty",
            (["critical":60,"vascular":30,"weakest":30]) );
        set_natural_armor(58,28);
        set_natural_weapon(3,5,1);
        wield_weapon(SWWEA"captain_hook1");
        equip_armor(SWARM"captain_hat1");
        equip_armor(SWARM"captain_cloth1");
        set("tactic_func","my_tactic");  
        set("chat_chance",1);
        set("chat_output",({
            "夏侯忍自语道：要不是我要负责这个城的安全，我早就杀往「妖□ 谷辰」(great_vampire)那里去了。\n"
        }) );
        set("att_chat_output",({
          "夏侯忍狂笑：哼，你就代替「妖□ 谷辰」(great_vampire)受死吧！\n"
        }) );
        set( "inquiry", ([
          "great_vampire":"@@ask_vampire",
          "special_things":"@@ask_things"
        ]) );
}
void ask_vampire(object asker)
{
     tell_room(environment(),@LONG

夏侯忍双目含著眼泪道：在我小的时候，一家原本高高兴兴地前往外公家拜年，
　　　　　　　　　　　那知途中突起刮起一阵阵的阴风，旋即绷出一个古里古
　　　　　　　　　　　怪的僵□，只一刹那，全家横遭惨死，只留下我一个被
　　　　　　　　　　　世外高人所救，指点原来那是个万年僵□，名叫「谷辰
　　　　　　　　　　　」。直到现在，我仍然忘不了那段血海深仇。日前听人
　　　　　　　　　　　谈起城外远远南岭外有类似僵□出没，那僵□的样子有
　　　　　　　　　　　点像「谷辰」，唉，无奈我有事无法分身前去。   

LONG 
   );
}
void ask_things(object asker)
{
    tell_room(environment(),"夏侯忍说道：特别的东西？我的武器就很特别啊。\n");    
}
int my_tactic()
{
    object victim;
    int i,k;
    
    if( (!victim=query_attacker())||atk||(random(20)>1) ) return 0;
    tell_room(environment(),set_color(sprintf(
       "夏侯忍奋起神威愈发抖擞精神地对著敌人发出连续攻击！\n"),"HIW"));
    atk=1;
    k=2+random(2);
    for (i=0;i<k;i++)
      this_player()->continue_attack();
    atk=0;
    return 1;
}
