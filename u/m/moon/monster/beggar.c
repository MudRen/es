#include <mudlib.h>

inherit MONSTER;

void create()
{
   object weapon;

        ::create();
        set_level(13);
        set_name( "beggar", "���˵���ؤ" );
        add( "id", ({ "beggar" }) );
        set_short( "���˵���ؤ" );
        set_long(
         "����һλ˫Ŀʧ��, �������ڵ�����, ����������ü��, \n"
         "����Զ϶�, ��һ�����ܹ��޴��ĥ��!\n"
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
        set("chat_output",({"��ؤ�����: ��λ��үʩ���Ǯ���Ұ�...\n"}));
        set( "chat_chance", 40 );
//        wield_weapon( "/d/moorth/obj/shortsword" );

        set( "inquiry", ([
            "story" : "@@ask_story",
//            "reward" : "@@ask_reward",
//            "inform" : "@@ask_inform",
//            "army" : "���ǵĴ����׼������ŵ�����ǳ�, Ҫ��������!\n" 
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
         command("say ����Ϊ����Ϲ�Ӿ�������, û��.....");
         command("spit "+my_name);
         return 1;
      }
     if(!me->debit(s2,num))
        return notify_fail("��û��ô��Ǯ  \n");     
     if(s2!="gold")
     {
         command("say лл�ˣ� �������ǽ�Ӳӵĺÿ�..");
         return 1;
     }
     if(num<50)
     {
          command("say лл��!");
          return 1;
     }
       command("say ������Ǹ������˰�...");
       command("sigh "+my_name);
       tell_object(me,"����ؤ����˵��: Ҫ���Ǿ�������Щ��(story), \n"
                      +"��Ҳ�������䵽���ֵز�! \n");
       command("say ���డ...");
       command("cry "+my_name);
       me->set_temp("paid",num);
       return 1;
}

int ask_story(object who)
{
   if( (int)who->query_level()<5 ) {
     command("sigh "+who->query("name"));
     write( "Ȼ��˵: �㻹С, �ﲻ����æ��!\n" );
     return 1;
   } else {
   tell_object( who, @LONG
    ��Ȼ����ô����, �Ҿ͸������...
    �������ǹ�÷�������Ĵ����, �ýύ�����ϸ�����ʿ,
    �������˳Ʋ�����, ���Ӣ�ۺ��ܶ�Ľ��Ͷ����
    xixixi ����û���, .. :D
LONG
     );
     return 1;
   }
   return 1;
}

int accept_item(object who,object item)
{  
/*  
       command("say ������Ǹ������˰�...");
       command("sigh "+who->query("name"));
       tell_object(who,"����ؤ����˵��: Ҫ���Ǿ�������Щ��(story), \n"
                      +"��Ҳ�������䵽���ֵز�! \n");
       command("say ���డ...");
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
      "\n�����Χ�˲�ע��͵͵��ʬ�����ó��ƴ�!\n");

     ob1=new("/obj/wineskin");
     ob1->move(killer);
     killer->set_temp("paid",0);
   }
   ::die();   
}
