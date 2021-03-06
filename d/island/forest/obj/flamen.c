#include "../tsunami.h"
#include "/include/move.h"
#include <daemons.h>

inherit MONSTER;
inherit DAEMON;

int times;

void create()
{
        ::create();
        seteuid(getuid()); 
        set_level(17);
        set_name("Archwizard Washu","大魔导士");
        add( "id", ({"daemon","arch","archwizard","washu"}) );
        set_short("大魔导士鹫羽");
        set_long(@LONG
鹫羽是魔族中魔法知识最丰富的大魔导士，同时也是魔族中知识最丰富的长老
，她年轻时曾四处闯荡，因此阅历非常丰富，应该就是别人所谓的活字典了；她
最喜欢对别人说有关三位守护灵和三把主钥的故事(story) 了，你有兴趣听吗？
如果你是乖小孩的话，说不定她还会送你奖品哦！
LONG
                );
        set( "unit", "位" );
        set( "race", "daemon" );
        set( "gender", "female" );
        set( "alignment",-500 );
        set( "hit_points", 550 );
        set( "max_hp", 550 );
        set( "spell_points",1000);
        set( "max_sp",1000);
        
        set_perm_stat("int",25);
        set_perm_stat("str",15);
        set_perm_stat("dex",25);
        set_perm_stat("kar",25);
        set_perm_stat("pie",25);
        
        set_natural_armor(35,30);
        set_natural_weapon(30,10,30);
        
        set( "special_defense", ([ "all":25,"none":10 ]) );
        set("aim_difficulty",
        ([ "critical":100,"vascular":20,"weakest":60,"ganglion":20 ]) );
        
        set( "wealth/silver",1000 );
        set( "tactic_func", "cast_spell" );
        set( "weight",350 );
        set( "times",0 );  
        set_skill("dagger",80 );
        set_skill("dodge",80);
        set_skill("parry",60);
        set_skill("anatomlogy",80);
        set_skill("elemental",80);
        set_skill("target",100);
        set_skill("concentrate",100);
        
        set("aiming_loc","weakest"); 
        set("magic_delay",2);
        set("spells/fireball",4);
        set("spells/sleet",4);
        set("inquiry",([
             "story":"@@ask_story",
             "canteen":"@@ask_canteen"]) );
        
        wield_weapon(TWEP"dagger1");
        equip_armor(TOBJ"hat");
        equip_armor(TOBJ"robe");
}

int cast_spell()
{
        object victim;
        string name;
        if( !(victim=query_attacker()) ) return 0;
        name = victim->query("name");
        
        if( random(15)<2 ) {
        command("cast sleet on "+name);
               return 1;
        }
        else if( random(15)<3 ) {        
        command("cast fireball on "+name);
               return 1;
       }
        else return 0;
}   

int ask_story()
{
    string str;
    
    str = @ALONG
    好吧！孩子，我就告诉你吧！
当年魔族为了王位继承的问题，分成不同意见的两派；一派主张王位继承者以长子为优先
，另一派则主张以魔族纯正血统为优先考虑；当时皇后为魔族血统，皇妃为人类血统，但
是皇妃却比皇后早生下王子。皇后虽然後来也生下王子，但终究是次子；当时宫中便有大
臣向当时的皇帝斐恩贝拉五世建议及早订定王位继承人人选，以免日後发生手足相残的悲
剧；但是皇帝认为来日方长，不须如此急迫的进行此事，因此这份建议就被如此搁下。岁
月匆匆，转瞬间两位王子已达行成人礼的年龄，斐恩贝拉五世原本要在行礼的当日宣布王
位继承的人选，但是，不幸却由此发生，皇帝在大礼前夕以３９岁英年突然暴毙，又没有
留下任何诏书指示继承人选，继承问题立刻浮现台面，成为大臣们争权夺利的政争工具；
拥有人类血统皇妃『船穗』不忍心看到自己的孩子沦为政争下的牺牲品，遂使用陪嫁的三
把主钥『津名魅』、『龙皇』还有『船穗』，恳求守护灵召唤出三艘飞船，带著王子、贴
身侍卫及一些家丁，当然还有我，趁著黑夜离开帝国国都。後来只听说帝国发生内战，所
为为何，自不在话下。

    当时我们只能漫无目的的四处漂流，虽然我不断的使用探知魔法，希望能找到一个非
常隐密的居所，过著与世无争的日子，但却一直无法如愿。过了好长一段日子，王妃病倒
了，依我们的魔法水准仍无法使她恢复健康，王妃知道是天年已尽，大限将至，临终前交
代：创立一个依东方体制为基础的王朝，只要保卫自己的居所就行了，不用在意以往那辉
煌的历史，之後就过世了。一切就像是王妃在指引似的，不久後，我们在这个小岛中发现
了非常隐密的森林，於是便决定在此生根了；但是，一切并不如我们想像的完美，就在准
备降落的同时，突然吹起了罕见的龙卷风，彷佛在捍卫这个小岛似的。经过一番搏斗，我
们终於突破暴风圈，降落在这森林中，可是『龙皇』在降落时却撞到山壁........。当时
王子决定遵从母亲遗训，在此落地生根，因此便在降落後把由主钥控制的三把主锁移植在
陆地上，这三把主锁也就变成了三株神木，但是龙皇由於损毁过重，移植不久後就枯\萎了
。

    过了三十年，当我们一切发展都近乎完备的时候，岛上原住民蜥蜴人的新兴势力，及
外来的武士团，为了扩张彼此的势力，逐渐往这个山谷发展，我们为了维护当年王妃的遗
训，遂起而与之抗争，数十个年头下来，三方都付出相当大的代价，直到有一天，蜥蜴人
派出了号称『最终兵器』的战士，企图一举歼灭我们魔族，在不得以的情况下，我们集合
了三位守护灵的灵力，好不容易终於镇压住这只怪物，但是它的魔力太强，三位守护灵逼
不得以均使用自己主钥的能力，终於将此怪物封印在『破邪镇』之中。战争发展至此，一
直保持沈默的武士团准备大举屠杀，让我们及蜥蜴人都从这个岛上消失，就在他们发动攻
势的前夕，岛上发生变动，岛中央的山丘突然流出四道水流将岛分成四个部份，接著天上
传出洪亮的神谕：『停止吧 .....！我们是创造这岛的神仙，如果不听劝告，我们将决议
收回这个岛屿.....』 翌日，三族便在中央的山丘上签订合约，并立下碑文，在上面宣示
：『和平与此碑共存』。

    孩子，这就是我们发展的经过，你睡著了吗？？？
ALONG
       ;
      this_player()->more(explode(str,"\n"), 0,1);   
  return 1;
}

int ask_canteen()
{
    object obj;
    obj = new(TOBJ"canteen");
        
    if(8 (int)this_player()->query("alignment") < -5000 ){
       tell_object(this_player(),
       "鹫羽说：要东西？可以啊，不过我不给坏小孩礼物，你要乖乖的才行！\n"
        );   
       tell_room( environment(this_player()),
       "由於"+this_player()->query("c_name")+"不乖，所以鹫羽不给他礼物.....:P\n"
       ,this_player() );
       return 1;
    }
    
    if( this_object()->query("times") >= 3 ){
       tell_object(this_player(),
       "鹫羽说：孩子，真不巧，水壶刚刚都被拿完了耶...\n"); 
       return 1;
    }
    
    if ( !this_player()->query_temp("get_canteen") ){
    write(@LONG
鹫羽带著和蔼的笑容，拍拍你的头说：
    好孩子，要水壶是吧，我只能给你一个，你要小心爱护它哦！
说著顺手递了个可爱的乖乖壶给你。
LONG
         );
    obj->move( this_player() );
    this_object()->add("times",1);
    this_player()->set_temp("get_canteen",1);
    return 1;
    }
    else{
    write("鹫羽很不高兴的说：你不听话哦？小心出门被雷神公公劈哦！\n");
    this_player()->add("alignment",-2000);
    return 1;
    }
}
