#include "../oldcat.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "The young lady", "矮灵族美少女" );
	add( "id", ({ "lady" }) );
	set_short( "矮灵族美少女" );
	set_long(@LONG
    一个矮灵族的美少女，一袭垂肩的长发，玉颊上泛著淡淡的红晕，樱桃小口，
眼珠灵动，一双纤手皓肤如玉，满脸都是温柔，满身尽是秀气，似还有一股动人气
韵，端庄中带有稚气。
LONG
	);
	set( "race", "dwarf" );
	set( "gender", "female" );
	set( "alignment", 0 );
	set_perm_stat( "str", 15 );
        set_perm_stat( "dex", 15 );
	set( "wealth/gold", 1 );
        set( "hit_points", 100);
        set( "max_hp", 100);
        set( "inquiry",([
             "marry" : "@@ask_marry",
             "rose" : "@@ask_rose",
             ]) );
        set("natural_armor_class",35);
        set("natural_defense_bonus",10);
        set_natural_weapon(9,7,10);
        set("chat_chance",5);
        set("chat_output",({
            "美人说：你也是那些自以为长的很帅的男人吗，要我嫁给你，少作梦了。\n"
             }) );
        set("att_chat_output", ({
          "\n美人说：你...你...像我这麽美丽的人你怎麽还出的了手。\n"
         }) );
        set("c_death_msg","%s 娇喘了一声...你这辈子别想讨老婆了。\n");
        set_c_verbs( ({
        "%s 向你频抛媚眼，趁你意乱情迷时，向%s打去",
        "%s 挥动她的绣花拳向 %s 打去",
        "%s 撩起裙子，趁你正色眯眯的看她的腿时，往%s打去",
        }) );
}

void ask_marry(object who)
{
  tell_object(who,
    "美人说：你这只癞蛤蟆也想吃天鹅肉吗 ?\n"
  );
}

void ask_rose(object who)
{
  tell_object(who,
    "美人说：假如你能找到蓝玫瑰，我就嫁给你。\n"
  );
}

int accept_item(object me,object item)
{
  string name;
  object ob;

  name=(string)item->query("name");
  if (!name || name!="blue rose") {
    return 0;
  }

  if (this_player()->query_temp("blue_rose")) {
    write("美女说：非常谢谢你，让我嫁给一位英俊的少年郎。\n");
    write("        谢谢你又送我一朵蓝色玫瑰花，实在不好意思。\n");
    write("        这样吧，我出价十个金币买下你这朵玫瑰花，算是对你的补偿。\n");
    this_object()->set("wealth",(["gold":11]) );
    command("give 10 gold to "+lower_case((string)this_player()->query("name")));
    item->remove();
    return 1;
  }

  if (item->query(me->query("name"))) {
    write("美女说：啊 ! 这真的是那蓝玫瑰，非常谢谢你，不过．．．．．．。\n");
    write("        你实在不是我喜欢的类型，很抱歉，姻缘是不能勉强的．．。\n");
    write("        这样吧，我出价十个金币买下你这朵玫瑰花，算是对你的补偿。\n");
    this_object()->set("wealth",(["gold":11]) );
    command("give 10 gold to "+lower_case((string)this_player()->query("name")));
    item->remove();
    return 1;
  }

  write("美女看了你给他的玫瑰一眼，唉、这是人造的吧。\n");
  write("我需要的是真正的玫瑰，谢谢。\n");
  item->move(me);
  return 1;

}
