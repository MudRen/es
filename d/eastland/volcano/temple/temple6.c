#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("矮灵族神殿");
	set_long(
@LONG_DESCRIPTION
一间迷漫著神秘气氛的矮灵族神殿正殿，正殿的顶端雕有火神的图案，一根
有龙纹的巨大柱子(post)竖在脚落，墙壁上雕满了许\多奇怪的花纹，地板是用一
块块的火山岩拼成的。
LONG_DESCRIPTION
	);
set( "exits", ([
     "northeast": OTEMP"temple10",
     "west": OTEMP"temple4",
     "south": OTEMP"temple3",
     ]) );
set("item_desc",([
    "post" : @POST
一条死气沉沉的黑龙，全身是亮黑色的，一层层的黑色鳞片闪闪发亮，两眼
无神的看著你。
POST
       ]));
set( "search_desc", ([
     "post":"@@search_post",
 ]) );
set("light",1);
reset();
}

string search_post()
{
  string str;

  if ((this_player()->query_quest_level("Dragon_box"))>1) 
    return "\n黑龙道：希望你也能早日修成正果，早登仙界。\n\n";

  if (this_player()->query_temp("dragon_box")) {
    if (present("dragon_box",this_player())) {
      return "\n在这段日子里，我每天在这里和长老感应，听了他的感化，我已决心定下心\n"+"来在这里继续修行，那个宝盒我不需要了，你拿给长老吧。\n\n";
     this_player()->set_temp("dragon_box",2);
    }
    return "\n我的宝盒呢? 找到了吗? \n\n";
  }
   
  if (this_player()->query_temp("gogo")) {
    str="\n黑龙用心电感应告诉你：快去找吧，在这里磨蹭磨蹭什麽。\n";
    return str;
  }
  
  if (this_player()->query_temp("dragon_help2")) {
    str="\n黑龙又一次的窜出来，\n"+
        "\n黑龙说：你耳聋吗? 讲这麽多次都不知道，明天再来吧!\n";
    return str;
  }

  if (this_player()->query_temp("dragon_help1")) {
    str="\n那黑龙又窜了出来，黑龙说道:又有啥事?\n"+
        "\n你说：到底是找什麽东东呢?\n"+
        "\n黑龙说：我刚刚不是告诉你了吗，找我掉的宝盒(box)啊！\n"+
        "\n你说：喔．我明白了。\n"+
        "\n黑龙说：不要再忘了喔，我不会说第三次。\n"+
        "\n黑龙说完，又回到柱子上了。\n";
    this_player()->delete_temp("dragon_help1");
    this_player()->set_temp("dragon_help2",1);
    return str;
  }
  
  str="\n一条黑龙从柱子上窜了出来，你正准备攻击它时，发现它飞舞在你的前面，\n"
     +"且眼睛眨呀眨的，看起来它对你是毫无敌意。\n"
     +"\n当你不知道该怎麽办的时後，\n\n"
     +"黑龙突然开口对你说：可以帮我一个忙吗 ?\n\n"
     +"你说：当然可以，只要我能力所及。\n\n"
     +"黑龙说：在很久很久以前，东方大陆曾发生巨变，我的一个东西因此失落\n"
     +"        了，你可以帮我把它找回来吗？\n\n"
     +"你说：喔 ! 小事一件，看我的吧 !\n\n";
  this_player()->set_temp("dragon_help1",1);
  this_player()->set_temp("gogo",1);
  call_out("forget",60,this_player());
  return str;
}

int forget(object who)
{
 this_player()->delete_temp("gogo");
 write("\n\n过了一会儿，你才想到，你根本就不知道黑龙到底要你找啥。\n\n");
  return 1;
}
