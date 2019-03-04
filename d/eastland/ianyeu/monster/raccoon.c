#include "../mad.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
   set_name( "raccoon dog", "野□" );
   add( "id", ({ "dog", "raccoon" }) );
   set_short( "野□" );
   set_long( "这是东方大陆北方特产的动物, 传说它会施咒及变身。\n" );
   set( "race", "beast" );
   set( "gender", "male" );
	set("unit","只");
	set_perm_stat( "dex", 10 );
   set( "alt_corpse", IANMOB"satyr" );
	set_c_verbs( ({ "%s，用嘴咬向%s", "%s用前爪往%s抓下" }) );
	set_c_limbs( ({ "头部", "身体", "脚部","尾巴" }) );
}

void die()
{
        tell_room( environment(this_object()), 
          "\n野□身受重伤, 不支倒地........\n\n"
          "就在你想离去时............\n\n"
          "突然野□从地上捉起一片树叶放在头上..........\n\n"
          "在一个後空翻之後......野□竟变成一魁武强悍的色狼!!\n\n"
          , this_object() );
        ::die(1);
}
