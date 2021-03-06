#include "../mad.h"

inherit TEACHER;
inherit MONSTER;

void create()
{
	::create();
   set_level(17);
   set_name( "hunter Jang", "张猎户" );
   add( "id", ({ "jang", "hunter" }) );
   set_short( "张猎户" );
	set_long(@C_LONG
这个猎人生得浓眉大眼，一身虬结的肌肉和结实的肩膀，显示他身怀武艺。
如果你没事的话, 还是离他远一点。
C_LONG
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 800 );
   set_perm_stat( "str", 25 );
   set_perm_stat( "dex", 25 );
   set_perm_stat( "kar", 15 );
   set_skill( "longblade", 100 );
   set_skill( "parry", 100 );
   set_skill( "block", 100 );
	set_skill( "dodge", 60 );
   set_skill( "anatomlogy", 80 );
	set( "aiming_loc", "ganglion" );
   set( "hit_points", 600 );
   set( "max_hp", 600 );
	set( "wealth/gold", 55 );
	set( "special_defense", (["all": 25 ]) );
   set_natural_weapon( 12, 12, 12 );
   set_natural_armor( 86, 55 );

   wield_weapon( IANOBJ"coral_blade" );
   equip_armor( IANOBJ"shield" );

   set_lessons( ([
                  "anatomlogy" : ({ 250, 50 })
   ]) );
    set( "inquiry", ([
        "skill" : "噢！小弟略通解剖学(anatomlogy)。\n",
        "wife" : "唉.......\n",
        "cut" : "大侠您要借刀啊? 我的家传宝刀不外借噢!\n"
                "但是前天梁伯母曾向我借了另一把刀, 我还特地帮她藏在\n"
                "床底。\n",
       "trace" : @REPLY
大侠, 是郭长老要您找我的吧? ........

张猎户续道: 是的, 为了报杀妻之仇, 这半年内我和长老
分头找寻淫贼之下落。但遗憾的是, 没有得到任何蛛丝马
迹; 虽然近几天来, 我也日夜不休地搜找村庄四周, 但..
..唉..................

曾听岳父说, 他在我们的新婚之夜, 看过此贼。我实在无
脸去见他, 故请大侠您去问问他老人家。不过, 由於思念
女儿过深, 除了内人的名子, 岳父是不会有反应的!
REPLY
     ]) );
}

void init()
{
   teacher::init();
   npc::init();
}

int check_trainee(object who)
{
   if( (int)who->query_quest_level("iywolf")<1 )
   return notify_fail(
        "张猎户叹道: 抱歉！小弟我正要出门搜寻淫贼的行踪。\n" );
   if( (string)who->query("class")=="adventurer"
     && (int)who->query_level()> 4 )
   return 1;
   else return notify_fail(
   "张猎户说道: 抱歉！郭长老吩咐说只能教「高级冒险者」。\n" );
}
