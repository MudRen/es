#include <mudlib.h>
#include <conditions.h>
#include "/u/s/smore/hawk.h"
inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "hawkman elder", "鸟人长老" );
        add ("id", ({ "hawkman", "elder" }) );
        set_short( "hawkman elder","鸟人长老");
        set("unit","位");
        set("alignment",1500);
        set("class","adventurer");
        set_long(@LONG
身为鸟人族的长老，鸟人长老自也是一名骁勇善战的战士，不过和鸟人族依
武斗会所推选出来的领袖不一样的是，鸟人长老同时也精通某些法术，更由
多年的战斗经验，学到了一些特殊的战斗技巧，和他作战，大概可以说是你
这一生最大的错误之一。由於他的丰富战斗经验和人生阅历，使得他在鸟人
族中讲话极有份量。
LONG
        );
        set_perm_stat("str", 24);
        set_perm_stat("int", 30);
        set_perm_stat("dex", 21);
        set_natural_weapon( 45, 20, 30 );
        set_natural_armor( 45, 30 );
        set ("gender", "male");
        set ("race", "hawkman");
        set("tactic_func","sp_tactic");
        set("aiming_loc","weakest");
        set("max_hp",1400);
        set("hit_points",1400);
        set("special_defense",
                (["all":60,"monk":20,"scholar":20,"none":40,"electric":90]));
        set("aim_difficulty",
                (["critical":100,"weakest":30,"vascular":10,"ganglion":50 ])) ;
        set_skill( "whip",100 );
        set_skill( "parry",100 );
        set_skill( "dodge",70 );
        set_skill( "block",40 );
        set_skill( "anatomlogy",80);
        wield_weapon("/u/s/smore/weapon/whip1.c");
        equip_armor(ARMOR"shield2.c");
        equip_armor(ARMOR"god_1.c");
//	equip_armor(ARMOR"platemail.c");
        equip_armor(ARMOR"glove1.c");
//	equip_armor(ARMOR"helmet1.c");
//	equip_armor(ARMOR"armbands1.c");
        equip_armor(ARMOR"boots1.c");

}

void report(object holder, object victim )
{
   seteuid(getuid());
   tell_object( victim,
   sprintf("( 你%s )\n","/adm/daemons/statsd"->status_string(victim)));
}

void init()
{
        add_action("do_report","report");
}

int sp_tactic()
{
        object magics,caster;
        int dam,choice,kar,con,pie,dex,str,aa;
        choice = random(5);
        switch(choice)
        {
        case 0: return 0;

                break;
        case 1:
                if ( !(magics=query_attacker())
                        || (random(20)>random(5)) ) return 0;
                tell_room(environment(),
                        "鸟人长老从口中吐出一团黑雾，把你团团罩住。\n"
                        "....等黑雾散去，你发现身上多了不少黑色斑点....\n",
                this_object() );
                con = magics->query_perm_stat("con") ;
                pie = magics->query_perm_stat("pie") ;
                dam = con * 3 - pie * 2  + random(20);
                magics->receive_special_damage("poison",dam);
                (CONDITION_PREFIX + "simple_poison")->apply_effect( magics,
15, 3 );
                return 1;
                break;
        case 2:
                if ( !(magics=query_attacker()) || (random(10)>2)) return 0;
                dex = magics->query_perm_stat("dex") ;
                if ( random(dex) > 17)
                {
                        tell_object(magics,
                                 "鸟人长老眼中射出两道高热的光芒，不过你身手敏"
                                +"捷的往旁边一跳....\n一个漂亮的後空翻，你躲开"
                                +"了这次的攻击。\n\n" );
                        tell_room(environment(),
                                 (string)magics->query("c_name")
                                +"一个漂亮的转体两周後空翻，躲开了鸟人长老"
                                +"眼中放出的两道红色光芒。\n\n",this_object() );
                        return 1;
                }
                tell_room(environment(),
                        "鸟人长老的双眼射出两道红光，照的你全身发热。\n",
                               this_object() );
                tell_object(this_player(),
"鸟人长老眼中射出两道炙热的红光，你觉得全身血液似乎快要沸腾了。\n"
                );
                dam = 30 + random(10);
                magics->receive_special_damage("energy",dam);
                report(magics,magics);
                return 1;
                break;
        case 3:
                if ( !(magics=query_attacker()) || (random(10)>2))
                        return 0;
                aa = (int)this_player()->query_temp("be_hang");
                if (aa) return 0;
                str = magics->query_perm_stat("str") ;
                if (random(str) > 17) return 0;
                tell_room(environment(),set_color(
"鸟人长老忽然用手中的长鞭紧紧的绞在敌人的脖子上。\n","HIR"),
                this_object() );
                dam = 15 + random(10);
                magics->receive_damage(dam);
                magics->block_attack(6);
                magics->set_temp("msg_stop_attack",
                        "( 你被长鞭紧紧的勒住，失去一次行动的机会 )\n");
                magics->set_temp("be_hang",1);
                call_out("over_hang",10,magics);
                return 1;
                break;
        case 4:
                caster = present("elder");
                aa = (int)caster->query_temp("no_way_out");
                if (random(10) > 4) return 0;
                if (aa) return 0;
                tell_room(environment(),set_color(
"鸟人长老狂啸一声，双翅鼓动，四周卷起千堆雪，让你分不清东南西北。\n","HIB")
                ,this_object() );
                caster->set_temp("no_way_out",1);
                call_out("let_go",10,magics);
                return 1;
                break;
                }
        return 1;
}

int over_hang()
{
        object magics;
        magics = query_attacker();
        magics -> set_temp("be_hang",0);
        return 0;
}

int let_go()
{
        object caster;
        tell_room(environment(),@LONG

大雪终於停止，你又看得到四周的环境了。

LONG
                ,this_object() );

        caster = present("elder");
        caster -> set_temp("no_way_out",0);
        return 1;
}

void die()
{
        object killer;
        killer = query("last_attacker");
        killer->set_temp("smore_armor/elder",1);
die(1);
}

int do_report()
{
        if (this_player()->query_temp("smore_box") == 5)
        {
                tell_object(this_player(),@LONG
长老说：你已经跟我说过了，我们大家都很感谢你。
LONG
                );
        }

        if (present("s_potion",this_object() ) &&
                this_player()->query_temp("smore_box") == 4)
        {
                tell_object(this_player(),@LONG
长老接过你的药瓶，仔细的看了许久，然後叹了一口气，对你说道:

谢谢你告诉我这个天大的秘密!!当年我早就怀疑阿道夫的实力能赢的了维多，只是
比赛的结果就是如此，我也不能说什麽。这些年来我们受制於阿道夫的淫威之下，
都是敢怒不敢言，幸亏有你这麽一位侠肝义胆的侠士才算解了当年之谜! 太好了，
我马上召开鸟人族大会，揭穿阿道夫的假面具，让他以後无法在鸟人族中作人！

长老转过头去，向身後的护卫吩咐了几句话，护卫点点头，就向外离去了。

接著鸟人长老带著你，穿过了重重地道，进入了鸟人族的禁地。

LONG
                );
                this_player()->set_temp("block_command",1);
                call_out("meeting_a",5,this_player() );
        }
        else if (!present("s_potion",this_object()) &&
                this_player()->query_temp("smore_box") == 4)
        {
                tell_object(this_player(),"长老说：『哦？那药水在哪啊？』\n\n" );
                return 1;
        }
        else if (this_player()->query_temp("smore_box") != 4)
                return 0;

        return 1;
}

void meeting_a()
{
    tell_object(this_player(),@LONG

你发现自己走进了一间非常古老的大厅，四周的墙都是由茅草所建。鸟人一群
群的走了进来，间歇著带有一阵阵谈论的声音。

鸟人长老清清喉咙..." 安静! 安静 "!

LONG
);
    call_out("meeting_0",5,this_player() );
}

void meeting_0()
{
    tell_object(this_player(),@LONG

四周都安静下来了.....

鸟人长老缓缓的将你所发现的药瓶展示给大家看，说" 这就是当年阿道夫所偷
用的禁药，就是用这个药物才打败了维多! 今天，我们就是要还维多一个公道
的! 阿道夫! 你还有什麽话好说!"

LONG
);
    call_out("meeting_1",10,this_player());
}

void meeting_1()
{
    tell_object(this_player(),@LONG
阿道夫脸上划过一抹的惊讶，但随即消逝，冷冷地笑笑，缓缓说道:
" 哼! 就拿一个小破烂瓶子，就要诬赖我是吗? 别以为你是长老我就怕你了! "
阿道夫指著你 "这! 这是谁啊? 不是鸟人族的人也来我们的禁地多管闲事? 找死!"

阿道夫说完就拔剑往你身上砍来!

正当千均一发之际，鸟人长老双手一伸，轻轻一拨就把阿道夫的剑挡下来!
鸟人长老目光炯炯的望著阿道夫说道:
" 阿道夫! 你这样作莫非是作贼心虚，杀人灭口吗? 有我在一切不可乱来 !"

LONG
);
    call_out("meeting_2",8,this_player());
}

void meeting_2()
{
    tell_object(this_player(),@LONG
柏尼丝也娇声说:
" 阿道夫，我很希望你是清白的，只是这些年来我始终无法了解你是怎麽打败维多
的，也许今天在这里，你可以当大家的面把事情澄清，现在出现了这瓶禁药，而且
刚刚族人也相继的发现裘拉根和雷多都不见了? 这些疑点未免太过蹊跷了吧? "

柏尼丝转过身来望著你 "对了，朋友，你还知道什麽有利的证据吗? "

LONG
);
    call_out("meeting_3",5,this_player());

}

void meeting_3()
{
    tell_object(this_player(),@LONG
你站了出来，当著全鸟人族的面前朗声说道 :
" 各位亲爱的鸟人族朋友们! 阿道夫的走狗--雷多，跟裘拉根他们三人当年联合串
通好，让阿道夫服用了增强肌力及抗力的药物，打败了维多，然而这药却是你们鸟
人族的禁药，因为，他会让鸟人的翅膀硬化，飞不起来，也就是说....

    阿～道～夫～他～～他～现～在～根本就～～不～会～飞!!!  "

你话一说完，鸟人们开始蛊噪起来，纷纷的用不屑的眼神看著阿道夫!

LONG
);
    call_out("meeting_4",10,this_player());
}

void meeting_4()
{
    	tell_object(this_player(),@LONG

阿道夫眼睛充满鲜红杀气，大叫" 说谎! 说谎! 不要相信他!!"

鸟人长老拿起火炬往地上一扔，火势沿著稻草顺势就烧了起来!
鸟人长老看了看阿道夫说:
" 现在，就是给你证明的机会了! "

鸟人长老把你一把抱起来，拍拍翅膀，你觉得身体有种奇怪的感觉，双脚竟离
开了地面..... 慢慢的，其他的鸟人也跟著飞到了空中，真是奇妙的感受!
只见阿道夫在那间审判室中惨叫，原来他真的飞不动了，看他被火焚烧的可怜
样子，在场却没有任何一位鸟人愿意下去解救他，可见他真的是作恶多端啊!

你听到火焰中传来一阵阵凄厉的惨叫声：『对不起～～～我错了～～～』，不
由得於心不忍，说到：『算了，放过他吧，你们还需要他的力量来抵御外族人
的侵掠呢。』
LONG
        );
    call_out("meeting_5",5,this_player() );
}

void meeting_5()
{
        tell_object(this_player(),@LONG

鸟人长老略一迟疑，点点头，说到：『在下次比武大会之前，还是让阿道夫先
暂代领袖职务吧，首恶裘拉根已经受到了应有的处罚，那就够了。』

长老手一挥，一阵大雨将熊熊大火浇熄，留下被烈火烧的奄奄一息的阿道夫，
两个守卫飞过去把阿道夫抱了起来带回城内。

鸟人长老带著你回到了村落。... ....

LONG
        );

        this_player()->move_player("/u/s/smore/hawk/room3-2","SNEAK");
        this_player()->set_temp("block_command",0);
        this_player()->set_temp("smore_box",5);
	call_out("ending",5,this_player() );
}

void ending()
{
	tell_object(this_player(),@LONG
长老对你说：感谢你为我们做了那麽多，听你说你找到了维多的坟墓，那麻
烦你再到维多的墓前，告诉他他的冤辱已经被你洗刷了。
LONG
	);
}

