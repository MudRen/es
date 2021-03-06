#include <../mumar.h>
inherit "/d/eastland/mumar/monster/mob_special";
 
void create()
{
        object ob;
        ::create();
        set_level( 7 );
        set_name( "cooking master", "伙夫头" );
        add ("id", ({ "master" }) );
        set_short( "伙夫头" );
        set_long( "一个伙夫头，不知道正在烦些什麽事情，愁眉苦脸地坐在角落。\n"
        		);
        set( "gender", "male" );
        set( "race", "human" );
 
        set("hit_points", 200);
        set( "wealth/silver", 50 );
        set_natural_weapon( 10, 5, 14 );
        set_natural_armor( 35, 15 );
        set_c_verbs(({"%s用头撞向%s","%s用平底锅砸向%s","%s用脚踹向%s"}));
        wield_weapon( OBJS "pan" );
        set("special_attack",(["damage_type" : "none","main_damage" : 8,
                                "random_dam" : 4 , "hit_rate" : 10]));
        set( "tactic_func", "my_tactic" );
        set("c_enemy_msg",
            "伙夫头抓起一袋米往你头上用力砸下.\n\n");
        set("c_room_msg","那伙夫头随手抓起一袋米，砸向");
        set("c_room_msg2", "，你也觉得有点眼冒金星....\n");
 
        set( "chat_chance", 5 );
        set( "chat_output", ({
        "伙夫头自言自语地说道 : 我到底该怎麽办呢....\n",
        "伙夫头叹了口气。\n",
        }) );
 
        set( "inquiry", ([
             "mood" : ({ "唉...最近关里出现了一群老鼠(rat)，这儿的粮食被偷吃了不少....\n"
                         "我还不知道要怎麽向将军交代呢!!而且也不知道要到那儿去找这群该死的畜生..\n"
                         "你能帮我这个忙吗?把这群该死的家伙除掉....\n " }),
             "bag" : ({ "唉...我怎麽点，就是少一包米，老鼠怎麽可能偷米呢？一定是有贼！..\n" }),
             "rat" : ({ "唉...我也不知道这群畜生会躲在那里，我相信它们一定躲在关里....\n"
                         "上回一个老兵说看到一只比人还高的老鼠，不过我是不相信啦..\n"
                         "你一定要帮我这个忙，不然被将军知道了，我就惨了！\n" })
        ]) );
}
 
void relay_message(string class1, string msg)
{
      string who, str;
      object player;
 
      if( sscanf( msg, "%s(%s)走了过来。", str,who )==2 )  {
         if( !player = find_player(lower_case(who)) ) return;
//	if( hunt_check( this_object(),player ) ) return;
    if (!query(temp("done") && ((int)player->query_quest_level("mumar")) < 1 &&
                        player->query_temp("mumar/done") ) {
                        tell_object( player, @THANKS
伙夫头说说：谢谢你，帮我这个忙，愿神祝福你。
你获得 10000 点经验。
   [   你完成了牧马关伙房的任务。   ]
THANKS
);
                        player->gain_experience(10000);
                        player->finish_quest("mumar_cooker", 1);
                        set_temp("done",1);
                        set("chat_chance",0);
                        delete("inquiry");
                        return;
                 }
                   tell_room( environment(),
             "伙夫头抬起头来看了看你，然後又继续低头沉思...\n" );
       }
}
