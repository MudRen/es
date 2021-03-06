#include "/d/eastland/beggar/dony.h"
inherit MONSTER;

object ob1;

void create()
{
        ::create();
        set_level(17);
        set_name( "blackmaster Lu", "陆阿巧" );
        add("id",({"blackmaster","lu"}));
        set_short( "巧匠 陆阿巧");
        set("unit","位");
        set_long( @LONG
陆阿巧原本是『铸剑门』的门人并且从师门处学得一身好手艺。 多年行走江湖并
广为人铸剑,所有的兵器只要经过他的手那怕是朽木也能断金。近年来因受到师门
叛徒的迫害而稳居到『薪胆村』来,他最大的希望就是有一天能够铲除所有的师门
败类。
LONG
        );
        set("weight",750);
        set_perm_stat("str",30 );
        set_perm_stat("dex",24 );
        set_natural_weapon(50, 18, 38);
        set_natural_armor( 83, 29 );
        set_skill("parry",80);
        set_skill("block",80);
        set("max_hp",620);
        set("hit_points",620);
        set("gender", "male");
        set("race", "human");
        set("war_score",50000);
        set("alignment",1500);
        set("special_defense", ([ "all": 40,"none":30]) );
        set("aim_difficulty",
          ([ "critical":65, "vascular":60, "ganglion":80, "weakest":65 ]) );
        set( "inquiry", ([
               "master":"@@ask_master",
            ]) );
        wield_weapon(DWEAPON"sky_sword.c");
        equip_armor(DARMOR"orb_shield.c");
        equip_armor(DARMOR"fire_armband.c");
}
void ask_master(object asker)
{
     
//     if( (int)asker->query_quest_level("dony1") ) 
     if ( !asker->query("finish_dony") )
        tell_object( asker , "陆阿巧说道:请帮帮我的朋友震八方吧,他似乎遇到麻烦了。\n");  
     else {
        if ( ( asker->query("class") ) == "scholar" ){
           if ( present("spell",asker) ) 
              tell_object( asker , "陆阿巧说道:咦,你不是已经有了聚剑术吗?\n");
           else {
              tell_object( asker, 
                "陆阿巧说道:是震八方叫你来问有关於聚剑术?\n"
                "陆阿巧说道:好吧,本来聚剑术是不随便传授给人的,既然你帮过我的朋友,那我就教你吧!\n"
                "忽然陆阿巧喃喃自语\n");
              call_out("recover1",2,asker);                     
           }     
        } else tell_object( asker , "陆阿巧说道:谢谢你的帮助我的朋友\n");
     }   
}

void recover1(object asker)
{
     tell_object( asker,
         "\n\n接著陆阿巧的眼睛暴出一道金光围绕著你,你看不见所有的东西!!\n\n\n");
     asker->set_temp("block_command",1);
     call_out("recover2",10,asker);
}
void recover2(object asker)
{
   asker->set_temp("block_command",0);
   tell_object(asker,
       "那道围绕著你身旁的金光久久才散去,并且在你的身上留下一样东西。\n"
       "陆阿巧叫醒你说道:孩子不要睡了,快起来吧,我已经传授给你聚剑术了。\n"
       "你看看自己,哇!聚剑术!!你高兴地向陆阿巧说谢谢。\n"
       "陆阿巧向你微笑。^_^\n");
   ob1 = new( DITEM"spell" );
   ob1->move(asker);
}
void die()
{
   object killer;
   string str,name;
   if ( killer=query("last_attacker") ) {
     if ( killer->query("org_name") ) name=killer->query("org_name");
     else name=killer->query("name");
   }
   str="\n  "+ctime(time())+" 陆阿巧 killed at "+
    file_name(environment(this_player()))+" by "+name+"\n";
   write_file("/open/dony/deathlist",str);
   ::die();
 }