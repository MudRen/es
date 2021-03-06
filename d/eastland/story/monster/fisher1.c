#include "../story.h"
inherit MONSTER;

void create()
{
    ::create();
    set_level(16);
    set_name( "old fisher", "老钓者" );
    add ("id", ({ "fisher" }) );
    set_short( "老钓者");
    set_long(@LONG
你眼前所见的一位年逾半百的老人，头戴著一顶草帽，背披著一件蓑衣，赤著双足
，手持著一根四尺长的钓杆，除了身旁的渔篓以及些许钓饵之外，再无它物。不仔
细一看，你还不发现那老者的手臂似乎有著银制的东西，在蓑衣的遮盖下发出微微
的亮光。老钓者眼睛半睁半闭，态度从容有馀，好整以暇地凝视著钓杆前头，看他
神情，容光焕发，两只半眼□□有神，想必是个非常人。
LONG
            );
    set("unit","位");
    set("race","human");      
    set("age",70);
    set("gender","male" );
    set("alignment",500);
    set("weight",1000);
    set_perm_stat("str",30);
    set_perm_stat("int",25);
    set("hit_points",550);
    set("max_hp",550);
    set("max_fp",200);
    set_natural_armor(70,25);
    set_natural_weapon(15,10,20);
    set("tactic","assault");
    set_skill("blunt",60);
    set_skill("dodge",70);
    set_skill("parry",70);
    set("special_defense", ([ "all": 30,"none":30]) );
    wield_weapon(SWEA"fisher_staff");
    equip_armor(SARM"fisher_armband");
    set( "tactic_func", "my_tactic" );
    set("chat_chance",1);
    set("chat_output",({
       "老钓者喃喃自语地道：该怎麽出去(how_to_out)咩?\n"
    }) );
    set("inquiry", ([
       "how_to_out":"@@ask_help",
      "ghost_spell":"@@ask_spell"
    ]) );
}
void ask_spell(object asker)
{
   int i,max;
   object spell,*eq;
   if ( !asker->query_temp("wizelder") ) {
      tell_room(environment(),"老钓者说道：我不知道。\n");
      return ;
   }
   spell=new(SWITEM"spell1");
   spell->move(environment());
   write(@LONG
   
老钓者说道：唉，我就是巫真的师父，多年前因为犯错被天帝惩罚。多年来我
            一直想赎罪，好能返回天都，却不幸死在「妖□ 谷辰」手里，你
            现在跟我说话的是我临死前用一块石头变成的替身。希望我英灵
            佑你，令你顺利铲除谷辰.........


老钓者说完之後留下了一张「灭魔符」就变成一块石头滚到溪里去了。

　　   
LONG
   );   
   asker->delete_temp("wizelder");
   this_object()->move("/u/d/dony/home/workroom");
   eq=all_inventory(this_object());
   max=sizeof(eq);
   for ( i=0;i<max;i++ )
     eq[i]->remove();  
   this_object()->remove();
}
void ask_help(object asker)
{
   write(@LONG
老钓者说道：不久前来了一位术师名叫「神算小瓜」，因感太多人丧生在
　　　　　　这个溪谷，特地在此施了咒语，就如你刚才被一阵突如其来
　　　　　　的风吹起，那就是咒语之一。而飞起的咒语好像是叫做：「
　　　　　　神恩如海天威如岳系系矩忙罗」，我也不太清楚，你最好去
            问他本人吧。

老钓者说完便继续钓鱼。

LONG
   );
}
int my_tactic()
{
     object victim;
     
     if (!(victim= query_attacker())) return 0;
     if ( random(30)>8) return 0;
     victim->receive_damage(15+random(10));
     tell_room(environment(this_object()),
           "\n\n老钓者把钓杆转成一个大圆，钓线如长舌吐信一般向敌人扫去！\n\n");
     return 1;
}                  