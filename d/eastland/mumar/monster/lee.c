#include <../mumar.h>
inherit MONSTER;
 
void create ()
{
        ::create();
        set_level(19);
        set_name( "General Lee", "牧马节度使 李□" );
        add ("id", ({ "general", "lee", }) );
        set_short( "牧马节度使 李□" );
        set_long( @C_LONG
牧马关节度使李□，是当今皇上身边某宠臣的女婿，靠著裙带关系，平步青云，现
在已经做到节度使的职位了。不过，听说他曾是少林的俗家子弟，功\夫可能还不差。
C_LONG
        );
    set( "alignment", 0 );
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "个" );
    set_perm_stat( "dex", 29 );
    set_perm_stat( "str", 20 );
    set_perm_stat( "int", 15 );
    set_perm_stat( "con", 15 );
    set_perm_stat( "karma", 25 );
    set ("max_hp", 800);
    set ("hit_points", 800);
    set ("wealth", ([ "gold": 400 ]) );
    set_natural_weapon( 35, 10, 17 );
    set_natural_armor( 52, 33 );
    set ("unbleeding", 1);
    set ("aim_difficulty", ([ "critical":55, "weakest":35, "ganglion":85,"vascular":65]));
    set ("special_defense", ([ "all":60 ]) );
    set ("weight", 400);
    set ("exp_reward",30500 );
    set_experience(1000000);
    set_skill("longblade",100);
    set_skill("parry",100);
    set_skill("concentrate",100);
    set("c_death_msg","%s 还心有不甘地说道：「你...你是不是服用类固醇...！」然後就挂了...\n");
    set( "inquiry", ([
         "plates" : ({ "不要乱动我的收藏品喔...但是若你有空，可以帮我擦(polish)一下。\n" }),
         "mirror" : ({ "喔..那面破镜子啊..上次一个笨手笨脚的传令打破了那面古董镜。\n"
                     "反正我也不是很喜欢那面镜子，破了就算了吧..如果你要找碎片，应该在垃圾堆里吧。\n" }),
         "button" : ({ "唉..我最喜欢穿的那件上衣掉了一颗金扣子..如果你能找到，\n"
                    "请你还给我！我会重赏你的..\n" })
           ]) );
 
    wield_weapon(OBJS"king_sword");
    equip_armor(OBJS"gloves01");
    equip_armor(OBJS"cloth01");
    equip_armor(OBJS"amulet01");
}
 
int accept_item(object me,object item)
{
    string name;
    name=(string)item->query("name");
     if ( !name || (name!="golden button") ) return 1;
     else {
     tell_object(me,
@MISSION
将军几乎是用哭地对你说：「谢谢你帮我找回这个扣子......。」
将军说：「为了答谢您的恩情，我的收藏室可以让您进去参观 。」
MISSION
        );
                item->remove();
        this_player()->set_temp("give_button",1);
        return 1;
        }
}
 
void die()
{
 // 抄龙剑的....
   int i ;
   object *sword,*tmp, empire_sword;
 
   tmp = children("/d/eastland/mumar/objs/king_sword");
   sword = ({ }) ;
   for(i=0 ; i<sizeof(tmp);i++ )
    {
       if(!environment(tmp[i])) continue ;
       else sword=sword+({tmp[i]}) ;
     }
 
 // 改成clone 出来的 sword 大於二就 remove
 
   if( sizeof(sword)>1 ){
     empire_sword = present( "empire sword", this_object() );
     tell_room(environment(this_object()),
  " 李□挣扎的说：真剑已经被夺.....这把仿造品不能给别人看到！\n\n李□硬是把剑吞了下去.....你看得目瞪口呆...\n\n",this_object() );
   empire_sword->remove();
   }
 ::die();
 }
