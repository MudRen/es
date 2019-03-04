#include <mudlib.h>
inherit MONSTER;

void create()
{
	
	::create();
	set_level(1);
	set_name( "Assistant Rabecca","蕾贝卡" );
	add ("id", ({ "lizardman", "assistant", "rabecca", }) );
	set_short( "领事助理 蕾贝卡" );
	set_long(@LONG
她是蜥蜴人领事馆中聘请的小姐，负责处理该族领域的签证作业。
她发现你正色咪咪的瞧著她看，使了个眼色又继续雕刻(carve)她手
中的小木刀去了！
LONG
	);

        set( "gender", "female" );
        set( "race", "lizardman" );
        set( "unit","位" );
	set_perm_stat( "dex", 1 );
	set_perm_stat( "str", 1 );
	set_perm_stat( "int", 1 );
	set_perm_stat( "con", 1 );
	set_perm_stat( "pie", 1 );
	set_perm_stat( "kar", 1 );
	set("no_attack",1);
	set("no_steal",1);
        set ("weight", 300);
        set( "inquiry", ([
         "carve" : "@@ask_carve" ,
//         "drill" : "@@ask_drill"
           ]) );
}

void ask_carve(object who)
{ 
  if( !who->query_temp("lizard_quest/get_saw"))
  {
      tell_room( environment(),@LONG
蕾贝卡瞪著你说：本大小姐今天不高兴，刻了把木刀要杀人，有意见吗？
LONG
      );
  }else{
  tell_room( environment(),@LONG
蕾贝卡含情脉脉的看著你说：嗨！我能为你做什麽呢？我除了会做秘书工作外
最拿手的就是雕刻木具了，不过要自备木具，我才肯为你刻哦！
LONG
      );
  }
  return;
}

int accept_item(object who, object ob)
{
    object obj;
    string *name;
    name=ob->query("id");
    
 if(name[0] == "mahogany branch")
  {
     if( who->query_temp("lizard_quest/get_saw") )
     {
       ob->remove();
       tell_room( environment(),@LONG
蕾贝卡对著你递给她的桃木说:
    哇！纹路这麽美的桃木，一定能刻出精美的小木刀的，您稍等一下哦！
话刚说完，立刻把小木刀递给你！
LONG
        );
        obj = new("/d/island/hole/obj/kirs");
        obj->move(this_object());
        command("give kirs to "+(string)who->query("name"));
     }else{
       tell_room( environment(),@LONG
蕾贝卡突然发出狰狞的笑声:来的正好，让我一消心头之恨！

－－－－我削－－－－我割－－－－我砍－－－－我锯死你这死没良心的东西－－－－

哇～～～你辛苦锯来的桃木都变成碎木屑了....
LONG
        );
        ob->remove();
     }
      return 1;
  }else{ 
      tell_room( environment(),@LONG
蕾贝卡奸笑道:你给我这东西练刀法吗？谢谢罗！
说著说著，东东给她割碎了....
LONG
        );
     ob->remove();
     return 1;
  }
}
