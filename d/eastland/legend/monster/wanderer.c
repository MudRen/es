#include <mudlib.h>

inherit MONSTER;

void create()
{
  ::create();
  set_level(15);
  set_name("wanderer","流浪者");
  add( "id", ({ "wanderer" }) );
  set_short("流浪者");
  set_long(@C_LONG
一个孤苦无依到处流浪的人。据说，他本出身於一个显赫的家族，但是，朝代更替
，一时杀伐四起，不但使得他的家园饱受摧残，更是和亲人失散，这使得当时年纪
很小的他不知所措，至今，他却还沈浸在幼时的记忆，以为身处在幸福的环境中。
现在，他不知道何处可去，何处是他的家，更不知道渡过了今天，明天又是什麽样
的情况，你从他身的身上处处可见战乱带来的影响，古有云：「明知兵者是凶器，
圣人不得己而用之。」希望所有在位者都能存有悲天悯人的胸怀，了解权力并不是
手中杀人的籍口。
C_LONG  
    );
  set( "race", "human" );
  set( "unit", "个" );
  set( "gender", "male");
  set_natural_weapon(30,18,33);
  set_natural_armor( 70, 18 );
  set( "max_hp", 400 );
  set( "hit_points", 400 );
  set_perm_stat( "int", 17 );
  set_perm_stat( "str", 20 );
  set_perm_stat( "dex", 22 );
  set_perm_stat( "pie", 18 );
  set("chat_chance",5);
  set("chat_output",({
     "流浪者说道：......\n",
     "流浪者说道：我的家....唉..\n"
  }) );
  set( "att_chat_output", ({
     "流浪者哭丧著脸道：我这麽可怜，你还在打我？\n"
  }) );
}
