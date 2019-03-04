
#include <../zeus.h>

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(19);
        set_name( "Master", "段老大" );
        add ("id",({ "master"}));
        set_short( "a master of mine","矿坑主人－段老大");
        set("unit","位");
        set_long(@C_LONG
他就是有当今天下第一铸剑师的剑庐主人段铁的大哥，他主掌著段家铸剑
业的命脉**矿坑**由於他精深的\功\夫\，以及过人的头脑才得以将这片人人
眼红的矿区保存下来．
C_LONG
);
        set ("gender", "male");
        set ("race", "dwarf");
        set_natural_armor( 70, 20 );
        set_natural_weapon( 40, 20, 40 );
        set_perm_stat( "str", 30 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "int", 30 );
        set_perm_stat( "dex", 30 );
        set_skill( "axe", 90 );
        set_skill( "parry", 80 );
        set( "tactic","berserk");
        set( "hit_points", 1200 );
        set( "max_hp", 1200 );
        set( "special_defense", ([ "cold": 40 ]) );
	set( "wealth/gold",100);
	wield_weapon(ZOBJ"/tang_axe");
	equip_armor(ZOBJ"/black_armband");
	equip_armor(ZOBJ"/black_boots");
	equip_armor(ZOBJ"/king_robe");
	equip_armor(ZOBJ"/diamond_ring");
	set("inquiry",([
	"magic magnetite":"@@ask_magic_metal",
	"troll" :
"唉！钢铁巨人原本是我请来保护魔法磁铁矿，可是他见宝物\n"
"就起了歹心现在将铁矿霸占住不让任何人拿走，只要你能把它取到手就可\n"
"以交给段铁帮你铸出一把绝世武器！\n" 
]));
}
void ask_magic_metal()
{ 
    tell_object(this_player(),
@ASK

天下奇宝，有德者居之．只要你能打败我，就有希望杀死巨人取得宝物！
如果你打不赢我就不要去巨人那里送死！来吧！

ASK
);
     kill_ob(this_player());
     this_player()->set_temp("ask#metal",1);
}
     
void die()
{      object ob,who;
      who=query_current_attacker();
  if(who->query_temp("ask#metal")){ 
tell_room(environment(this_object()),
"\n不错！你赢了！希望你能找到巨人的弱点，并且杀死他他拿到魔法磁铁矿，\n"
"做出一把天下无敌的神兵利器．这些装备留给你希望对你有所帮助，我必须\n"
"去闭关疗伤了．把拉杆拉动就可以消掉矿坑内的机关了．\n\n",
this_object()  );
 set("alt_corpse",ZMOB"/mine_master");
  ob=present("master");
   ob->remove();
::die(1);
}else{
::die(1);
}
}