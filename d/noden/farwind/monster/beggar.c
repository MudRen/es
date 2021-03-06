#include <mudlib.h>

inherit MONSTER;

void create()
{
   object weapon;

        ::create();
        set_level(13);
        set_name( "beggar", "流浪的乞丐" );
        add( "id", ({ "beggar" }) );
        set_short( "流浪的乞丐" );
        set_long(
         "他是一位双目失明, 衣衫褴褛的老人, 从他紧锁的眉宇, \n"
         "你可以断定, 他一定经受过巨大的磨难!\n"
        );
        seteuid(getuid());
        set( "alignment", 0 );
        set_perm_stat("str",30);
        set_perm_stat("dex",30);
        set_skill("parry", 100);
        set_skill( "dodge", 60 );

        set( "race", "human" );
        set( "gender", "male" );
        set_natural_armor( 50, 30 );
        set( "pursuing", 1 );
        set( "moving", 1 );
        set( "speed", 30 );
        set( "exp_reward",100);
        set( "patrol", ({ "east", "east", "west", "west", 
                          "west", "west", "east", "east" } ));
        set("chat_output",({"乞丐哀求道: 哪位大爷施舍点钱给我啊...\n"}));
        set( "chat_chance", 40 );
//        wield_weapon( "/d/moorth/obj/shortsword" );

        set( "inquiry", ([
            "story" : "@@ask_story",
//            "reward" : "@@ask_reward",
//            "inform" : "@@ask_inform",
//            "army" : "我们的大军正准备进攻诺达尼亚城, 要命快闪吧!\n" 
          ]) );
}

void init()
{
       npc::init();
       add_action("do_give","give");
}

int do_give(string str)
{
     string s1,s2,s3,my_name;
     int num;
     object me;
     if(!str) return 0;
     if( sscanf(str,"%d %s %s %s",num,s2,s3,s1)<4 )
        return 0;
     if(query("name")!=s1 || s3!="to") 
        return 0;     
     if( s2!="gold" && s2!="silver" && s2!="copper") 
        return 0;

     me=this_player();
     my_name=lower_case(me->query("name"));
     
     if(num<=0 )
     {
         command("slap "+my_name);
         command("grin "+my_name);
         command("say 别以为我是瞎子就想蒙我, 没门.....");
         command("spit "+my_name);
         return 1;
      }
     if(!me->debit(s2,num))
        return notify_fail("你没那么多钱  \n");     
     if(s2!="gold")
     {
         command("say 谢谢了， 不过还是金灿灿的好看..");
         return 1;
     }
     if(num<50)
     {
          command("say 谢谢了!");
          return 1;
     }
       command("say 你可真是个好心人啊...");
       command("sigh "+my_name);
       tell_object(me,"老乞丐继续说道: 要不是经历了那些事(story), \n"
                      +"我也不会沦落到这种地步! \n");
       command("say 命苦啊...");
       command("cry "+my_name);
       me->set_temp("paid",num);
       return 1;
}

int ask_story(object who)
{
   if( (int)who->query_level()<5 ) {
     command("sigh "+who->query("name"));
     write( "然后说: 你还小, 帮不了我忙的!\n" );
     return 1;
   } else {
   tell_object( who, @LONG
    既然你这么好心, 我就告诉你吧...
    当年我是古梅镇有名的大财主, 好结交江湖上各方义士,
    江湖上人称柴大官人, 许多英雄豪杰都慕名投奔我
    xixixi 程序还没编好, .. :D
LONG
     );
     return 1;
   }
   return 1;
}

int accept_item(object who,object item)
{  
/*  
       command("say 你可真是个好心人啊...");
       command("sigh "+who->query("name"));
       tell_object(who,"老乞丐继续说道: 要不是经历了那些事(story), \n"
                      +"我也不会沦落到这种地步! \n");
       command("say 命苦啊...");
       command("cry "+who->query("name"));
       return 0;
  */  
}

void die()
{  
   object ob1,killer;
   
   killer = query("last_attacker");
   if( !killer ) {
     ::die();
     return;
   }
   if(!present(killer->query("name")) )
   {
      ::die();
      return;
   }
   if(killer->query_temp("paid")>=50)
   {
     tell_object( killer,
      "\n你趁周围人不注意偷偷从尸体里拿出酒袋!\n");

     ob1=new("/obj/wineskin");
     ob1->move(killer);
     killer->set_temp("paid",0);
   }
   ::die();   
}
