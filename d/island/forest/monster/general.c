#include "../tsunami.h"
#include <stats.h>

inherit MONSTER;

void create()
{
    ::create();
    set_level(17);
    set_name("General Kagado","神武将军 神我人");
    add("id",({"general","kagado"}) );
    set_short("神我人将军");
    set_long(@LONG
神武将军神我人是目前总领魔族军备的指挥官，直接听命於天皇行事。端详此人，
身材高大魁武，大小伤痕无数，想必是已经经历过大小战争无数次了。这人对王家还
算忠诚，只是也有一个非常要不得的缺点，就是爱财如命，凡事只要有钱，他都肯帮
忙，比如说：泄露皇城的通行密码呀.....等等之类的；当然，叛国例外！
LONG
            );
    set("unit","位");
    set("gender","male");
    set("race","daemon");
    set("alignment",-1000);
    set("time_to_heal",5);
    set_natural_armor(30,30);
    set_natural_weapon(5,15,17);
    set_perm_stat("str",20);
    set_perm_stat("dex",20);
    set("max_hp",800);
    set("hit_points",800);
    set_skill("parry",80);
    set_skill("longblade",100);
    set_skill("block",80);
    set("wealth/gold",200);
    set("special_defense",(["all":30,"none":20]) );
    set("aim_difficulty",(["critical":80,"vascular":10,"ganglion":40]) );
    set("exp_reward",15000);
    set("inquiry",([
         "password":"@@ask_passwd"]) );    
    wield_weapon(TWEP"sword1");
    equip_armor(TOBJ"shield2");
    equip_armor(TOBJ"helmet1");
    equip_armor(TOBJ"boot1");
    equip_armor(TOBJ"chainmail");
}

void init()
{
    add_action("do_pay","pay");
}

int do_pay(string str)
{
    string who, type;
    int num;
    if( !str || str=="" || sscanf(str, "%s %d %s",who, num, type) !=3)
    return notify_fail("付谁?多少钱？\n");
    
    if(!id(who)) return 0;
    
    if(type != "copper") {
    tell_object(this_player(),
    "神我人将军以不屑的口吻说：你们都只知道用金的，银的....我偏偏就要铜的啦！\n");
    return 1;
    }
    
    if( !this_player()->debit(type, num)){
      write(
      "神我人将军怒道：钱不够还敢来？来人，把这家伙轰出去！\n");
      tell_room( environment(this_player()),
      "将军突然喝来左右，将"+this_player()->query("c_name")+"轰了出去！\n"
      ,this_player() );
      this_player()->move_player(CITY"sway3","SNEAK");
      tell_room( environment(this_player()),
      "哇～～！突然前方一团黑影落下，哦～～！原来是"+this_player()->query("c_name")+"被人扔了出来啦！\n"
      ,this_player() );
      return 1;
    }
    if(num < 500){
    write("神我人将军瞪大著眼儿看著你的钱袋：小鬼，不够哦！！\n");
    return 1;
    }
    if(num >= 500){
    write(@BLONG
神我人将军笑咪咪的说：小子，你有前途，不错哦！！
                      听仔细了，只说一次............
                      很久很久以前有一个老公公和一个老婆婆........

你伸长著脖子仔细的听著............
BLONG
               );
    this_player()->set_temp("block_command",1);  
    call_out("leave",5,this_player());
    return 1;
    }           
}    
    
int leave()
{
   write(@CLONG
神我人将军突然有气无力的说：我累了，你退下吧！！
CLONG
        );
   this_player()->set_temp("block_command",0);
   this_player()->set_explore("island#3");
   return 1;     
}   

int ask_passwd()
{
    write(@CLONG
神我人将军说：问通行密码？当然没问题呀........
说著说著把脸转向窗外，偌大的手掌摊在你面前晃呀晃的，你知道该怎麽做了.......
CLONG
         );
    return 1;
}          
