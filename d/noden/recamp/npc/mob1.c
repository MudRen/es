
#include <mudlib.h>
#include "../camp.h"
inherit MONSTER ;

void create ()
{
        ::create();
        set_level(10);
        set_name( "book fool", "书呆子" );
        add ("id",({ "book","fool","book fool" }));
        set_short( "书呆子");
        set("unit","位");
        set_long(
@C_LONG
世事如棋，乾坤莫测，笑尽英雄，百世经纶书呆子。
宇宙似幻，云波谲诡，哭遍侠客，寰宇武典心中剑。
学贯古今，上知天文，下知地理，一目十行，过目不忘。
书一页有张潇傻的脸庞，却透漏著寻找著什麽的眼神....
终日喃喃自语，疯疯癫癫的，比”三疯″还伤脑筋，所以被称为书呆子。
C_LONG
);
        set ("gender", "male");
        set ("race", "dwarf");
        set_natural_armor( 30, 20 );
	set_natural_weapon(25,5,15 );
	set("hit_points",300);
	set("max_hp",300);
	set( "wealth/silver",1000);
        set("aim_difficulty",
          (["critical":50,"vascular":50,"weakest":70,"ganglion":80])) ;
        set("weight",500) ;
        set_skill("dodge",60) ;
        set_skill("parry",70) ;

}

int accept_item(object who,object item)
{
  int code;

  if ( !item->query_inked() ) {
    tell_room( environment(), 
      "书呆子叹了口气: 大笨瓜，没用的东西也当宝贝？\n");
      command("give paper to "+who->query("name"));
      return 1; 
  }
  if ( (int)who->query_quest_level("lulu") >=1 ) code=1; else 
  if (who->query_temp("lulu_active")) code=2; else code=3 ;  

  if (code==3)
  write("书呆子说:嗯..这上面大概是这样说的.......\n"
        "远古时代, 草原上的半兽人部落, 出现一位英明的领袖嘎姆(Gammu),\n"
        "并有水、火、雷、电四位年轻将军辅佐她, 後来嘎姆临终时传位给她\n"
        "年轻的女儿露露(lulu), 四位争风吃醋的将军, 从此不断的发生冲突\n"
        ", 突然有一天闪电将军带领著一群神秘的东方杀手, 不分青红皂白的\n"
        "展开惨不忍赌的屠杀行动, 在众人的合力还击下, 终於击退敌军, 而\n"
        "负伤累累的闪电将军竟以自己生命做赌注, 施展可怕的黑魔法, 将全\n"
        "部的人都变成石头 .....措手不及的露露只得先将咒语及事件始末记\n"
        "录於石壁上... 咒语是: 伊搭释、瓦塔拉、乌阿达、飕飕库拉医际嬷\n"
        "壹而撒、仆类了、扑而噎恩街、股雷特佛力为....\n"
        "突然一阵耀眼的光芒照亮的让你几乎看不清楚眼前的东西......\n"
        "\n"
        "\n"
        "....\n"
        "\n") ;

  command("give paper to "+who->query("name"));

  write("咦？你不禁怀疑自己是不是眼花了...怎麽眼前多了个陌生的女子？\n") ;
  tell_room( environment(), 
     sprintf("露露向%s(%s)点头微笑，说道: 谢谢！\n",
     who->query("c_name"),who->query("name") ), who ) ;

  if (code>=2) 
    tell_object( who,"露露点头微笑，说道: 谢谢！请再为我寻找我的将军吧!!\n");

  if (code==3) { 
    who->set_temp("lulu_active",1);
/*
    tell_object( who, 
       "[你开始了 露露(lulu) 任务，得到 1000 点经验]\n"
       );
    who->gain_experience(1000);
*/
     if( who ) who->set_explore("noden#38");
  }

   if( present("lulu", environment(this_object())) )
   {   this_object()->remove();
       return 1;
   }

  set("alt_corpse",CAMPMOB"lulu") ;
  die() ;
  return 1;
}
void die()
{
   ::die(1) ;
   return;
}
