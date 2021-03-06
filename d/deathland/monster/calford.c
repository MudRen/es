#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	seteuid(getuid());
	set_name( "calford", "卡尔服德" );
	add ("id", ({ "calford", "dwarf", }) );
	set_short( "矮人皇室侍卫长卡尔服德" );
	set_long(
	"矮人皇室侍卫长卡尔服德,被誉为莫拉德皇族史中最强大的战士.若是没有他,巨人族\n"
    "早就击溃莫拉德矮人王国了.\n"	
	);
    set("weapon_master",1);
    set("alignment",100);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "个" );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "con", 30 );
	set_perm_stat( "piety", 15);
	set_perm_stat( "karma", 30);
	set_skill("axe",100);
	set_skill("parry",100);
	set_skill("dodge",90);
        set("special_defense", (["all":30,"none":40,"monk":10,"scholar":10]) );
	set ("aim_difficulty",([ "vascular":35 , "weakest":20 ]) );
	set ("max_hp", 850);
	set ("hit_points", 850);
	set ("wealth", ([ "gold": 55 ]) );
	set_natural_weapon( 35, 15, 20 );
	set_natural_armor( 60, 55 );
    set ("weight", 400);
    set( "inquiry", ([
         "troll" : "@@ask_troll",
         "valor"  :"@@ask_valor",
           ]) );
    
    set ("chat_chance", 25);
	set ("chat_output", ({
    "卡尔服德说:要不是我必须保护皇宫的安全,我早就杀进巨人的巢穴了\n",
	    "卡尔服德说:假如你是来帮助我们的,先证明你是一个勇者(valor).\n"
	    }) ); 
	set ("att_chat_output", ({
	    "卡尔服德说:矮人的敌人,受死吧\n",
	    }) );
	
	wield_weapon(Weapon"/axe03");
	equip_armor(Armour"/plate04");
	set ("cutknife", 5);
}

void ask_troll( object who )
{
        tell_object( who, 
          "巨人,有很强的生命力,我们矮人族已经与它们作战数百年了\n"
          "如果你想知道更详尽的资料,或许巨人战术研究室的卡尔(Karl)将军\n"
          "能告诉你.\n");
      return ;        
}

void ask_valor(object who)
{
      object ob8;
      
      tell_object(who,
      "证明你是一个勇者的方法很容易,砍死一只巨人(troll),然後把它的耳朵割来给我.\n"
     );
     if( (int)(who->query_level())<15 ) {
         tell_object(who,"\n\n卡尔服德看著你说:提升你的等级後再来找我吧!\n");
         return ;
      }
      if( !query("cutknife") )
      	write("卡尔服德说: 已经没有割耳小刀了，下次看看吧。\n");
      else {
      	ob8=new(Weapon"/cutknife");
      	ob8->move(who);
      	add("cutknife",-1);
      	write("卡尔服德给你一把割耳小刀。\n");
      }
     return ;
}

int accept_item(object ob1,object ob2)
{
     object ob3;
     
     if (!ob2 || (int)(ob2->query("receive_trollear"))!=1) return 0;
     if ((int)(ob2->query("receive_trollear"))==1) {
        tell_object(ob1,
        "卡尔服德说:\n"
        "我想你已经证明你的勇气了.\或\许\你觉得有些困惑,为什麽我会要你去冒险\n"
        "与巨人战斗?因为一个更艰难的任务正等著你.\n"
        "在矿坑的\深处,有两个传说中的骸骨族黑武士( skeleton blackknight ),\n"
        "他们的出现曾经使得矮人国度陷入恐慌,甚至当时的国王莫拉德二世下令他\n"
        "的儿子阿莱特斯(Alaits),率领著一群精英战士带著老弱妇孺骑著狮鹫飞离\n"
        "死亡大地.而他则独自前去对抗黑武士.最後虽然莫拉德二世英勇的战死,但\n"
        "是两名黑武士再也没有出现了.\n"
        "经过了数百年,当时的黑武士似乎复活了. 但是幸好某次地震所造成的大深\n"
        "渊阻隔了他们.只不过我们矮人族的圣地却遭受了很大的威胁, 二皇子艾尔\n"
        "与宫廷魔法师齐格为了对抗巨人祭司哈特瑞德屈里的黑暗魔法而所\n"
        "做的研究可能因此泡汤.希望你能够帮助我们.\n"
        );
       if( (int)(ob1->query_level())<15 ) {
         tell_object(ob1,"\n\n卡尔服德看著你说:提升你的等级後再来找我吧!\n");
         return 1;
       }
       ob3=new(Object"/blackcard");
       ob3->set("someone_id",ob1->query("name"));
       ob3->move(ob1);
       tell_object(environment(),sprintf("卡尔服德给%s一张证明文件.\n",ob1->query("c_name")));
       tell_object(ob1,"拿著这个证明,把它给宏都拉瑟看(show),他将帮你越过深渊.\n"); 
       ob2->remove();
       ob1->set_explore("deathland#33"); 
       return 1;
     }
}
