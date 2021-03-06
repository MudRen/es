#include "../iigima.h"
#include <stats.h>
#include <conditions.h>
// Created by Iigima , modified by Smore@Eastern.Stories in 8/20/1996
inherit MONSTER ;

void create ()
{
        ::create();
        set_level(15);
        set_name( "Salin","神官萨林" );
        add ("id", ({ "drow","salin" }) );
        set_short( "Salin","神官萨林" );
        set("unit","位");
        set("alignment",1100);
        set("weight",800);
        set("wealth/copper",4000);
        set( "weight", 600 );
        set( "tactic_func", "my_tactic" );
        set_long(
@C_LONG
这位老妇人是黑暗精灵的领导者，看她的外表好像已有数百岁了，戴
著一顶高高的帽子，想必她也曾是一位祭司吧，温和的眼光中流露著
智者的风范，最近黑暗精灵村要将女祭司送往祭神 (god)，萨林正在
为此忙碌著。
C_LONG
        );
        set_perm_stat("int", 25);
        set_perm_stat("dex", 16);
        set_perm_stat("str",18);
        set("max_hp",550);
        set("hit_points",550);
        set_natural_weapon( 10, 10, 20 );
        set_natural_armor( 25, 20 );
        set( "special_defense", ([
                "all":30,"fire":-10,"cold":-10,
                "evil":80,"divine":-50,"none":20
                        ]) );
        set ("race", "drow");
        set ("gender", "female");
        set_c_limbs(({"身体","头部","脚部"}));
        set( "chat_chance", 14 );
        set( "chat_output", ({
           "神官一脸难色，好像有很多困扰。\n",
           "萨林说：好烦喔，祭祀不能荒废，可是村人又不谅解.....\n",
           "神官喃喃的说：如果拿到蛇窝草(snake herb)，一切就好办了...\n"
                          }));
        set( "inquiry", ([
        "god" : ({
"哎...祭神是我们黑暗精灵的传统，每年都要献上一位女祭司给司娜可女神。\n"
                }),
        "teeder" : ({
"蒂德吗？我也知道她是潘恩的心上人啦，但是她是祭司，我又能如何呢？\n"
               }),
        "snake herb" : ({
"蛇窝草？你有蛇窝草吗？那是我制药(drug)的关键耶！\n"
              }),
        "drug" : ({
"嗯，我正在制造一种能防止禁断之地的蛇类(snake)进入我们村落的药粉\n"
"但是就是独缺这蛇窝草，所以作不出药来，真糟糕！\n"
                 }),
        "snake" : ({
"你能帮我拿到蛇窝草吗？但是禁断之地是不能进去的，那里很危险\n"
"嗯...听说有个冒险家(adventurer)..好像曾经去过禁断之地......\n"
                 }),
        "adventurer" : ({
"好像叫奇什麽的，你去找找吧，我也不认识这个人耶。\n"
                 })
            ]) );
   wield_weapon( OBJ"wand" );
   equip_armor( ARM"robe" );
   equip_armor( ARM"lucky_cloak" );
   equip_armor( ARM"lucky_shoes" );
   equip_armor( ARM"lucky_ring" );
}
int accept_item(object me, object item)
{
   string name;
   object ob;
   int i;

   name=(string)item->query("name");
   if (!name || (name!="snake herb"))
     return 1;
write("萨林说道：太好了！我就是要这蛇窝草，谢谢你帮助我们村落\n");
write("萨林在她的长袍里摸摸找找，好像要拿出什麽东西......\n");
   if (!this_object()->query("key")){
     write("萨林说道：嗯，这钥匙给你吧，多拿些蛇窝草给我喔！！\n");
     ob = new( OBJ"key" );
     ob->move(this_player());
     set("key",1);
   }
   else
write("神官萨林缓缓说道：看来有人捷足先登了，钥匙已经没有了。\n");
   return 1;
}
int my_tactic()
{
   object *victim,env;
   int i,n;
   env=environment(this_object());
   if ( !victim = query_attackers() ) return 0 ;
   if( random(20)>4 ) return 0;
    else {
    tell_room( environment(this_object()),
    "萨林缓缓吟诵黑魔法中恐黑术的咒文: 沙美翁，奈斯特罗.....\n"
            "你发现一阵黑雾笼罩在你身上，你的意识渐渐模糊...\n\n",
     this_object() );
      for( i=0; i<sizeof(victim); i++ ) {
      n = i + 1;
      if( n == sizeof(victim) ) n = 0;
      (CONDITION_PREFIX + "confused")->apply_effect( victim[i], 15, 5);
  if( sizeof(victim) == 1 ) {
      tell_room( env,
      victim[i]->query("c_name")+
      "突然开始攻击"+victim[n]->query("c_name")+"。\n",
          victim[i]);
      victim[i]->cease_all_attacks();
      victim[i]->kill_ob(victim[n]);
  }
      return 1;
 }
 }
}
