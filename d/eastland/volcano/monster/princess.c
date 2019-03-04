#include <../oldcat.h>

inherit MONSTER;

void create()
{

	::create();
	set_level(12);
	set_name( "princess", "小龙女" );
	set_short( "小龙女" );
	set_long(
		 "@@query_long"
		 );
	set( "gender", "female" );
	set( "race", "dragon" );
        set( "likefish",1);
	set( "no_attack",1);
}

string query_long()
{
 if ((int)this_player()->query_quest_level("Dragon_box"))
 {
    set("hit_points",this_object()->query("max_hp"));
    return "你看到一个面带笑容的公主，身著白色的丝质衣服，在窗口观赏景色。\n";
  }
 else
  {
   set("hit_points",1);
   return "你看到一个卧病在床的公主，原本红润的脸现在只是一片苍白，\n"+
      "如果再没有人为公主找到续命灵药，恐怕她撑不了多久。\n";
  }
}

int accept_item(object me,object item)
{
     if ((string)item->query("name")!="living pill" || (int)me->query_quest_level("Dragon_box")) {
       tell_object(me,
          "小龙女微微的摇著头：「谢谢 !! 但我不需要这东西 !!」\n");
       command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
       return 1;
     }
     if (!item->query(me->query("name"))) {
        printf("公主说：我就算是死也不吃来源不正当的东西。\n");
        item->move(me);
        return 1;
     }
     tell_object(me,
"你把公主的嘴稍微拨开，将续命药丸让公主吃下去，吃了药丸以後，公主果然精神\n"+
"好多了，公主向你说：「我知道你的心事，谢谢你救了我，那朵蓝色玫瑰花你就拿去吧。\n"+"看到她好多了，你觉得付出没有白费 !!\n\n"
      );
     if ((string)me->query("class")=="scholar") {
        this_player()->set("demand/water",1);
        write("龙王说：为了感谢你为了我女儿这样奔波，我决定将一只水精灵供你召唤，当作是我给你的礼物。\n");
     }
     tell_object(me,set_color("龙王用心灵感应对你说道：谢谢你! [你获得 5000 点经验]\n","HIY"));
     item->remove();
     me->finish_quest("Dragon_box",1);
     me->gain_experience(5000);
     return 1;
}
