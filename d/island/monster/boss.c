#include "../island.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(5);
    set_name( "Boss", "店老板" );
    set_short( "店老板");
    set_long(@LONG
这是龙门客栈的店老板，你可别小看他哦，他可是厨艺(cooking)一流哦！
LONG
            );
    set("unit","位");
    set("race","lizardman");      
    set("age",50);
    set("gender","male" );
    set("alignment",200);
    set("weight",300);
    set("wealth/copper",150);
    set_perm_stat("str",5);
    set_perm_stat("dex",5);
    set_perm_stat("kar",5);
    set_perm_stat("int",5);
    set_perm_stat("pie",5);
    set("hit_points",100);
    set("max_hp",100);
    set_natural_armor(25,7);
    set_natural_weapon(15,0,5);
    set("inquiry",([
        "cooking":"@@ask_cooking"]) );
    set("exp_reward",200);
}

int accept_item(object player,object ob)
{
      string *name;
      object obj;
      name = ob->query("id");
      
      if( name[0] != ("shark's fin") ){
      tell_room(environment(),@LONG
店老板很生气的说:拿这种五四三二一的东西叫我煮，未免太侮辱我的厨艺了吧！！
LONG
      );
      command("drop " + name[0] );
      return 1;
      }  
      tell_room( environment(),@LONG
店老板很高兴的说:哇！这样好的鱼翅还是第一次看到，你放心，看我的！
紧接著拿著开水冲泡了一下，一碗鲜美的鱼翅汤就呈现在你面前了！！
LONG
      );
      ob->remove();
      obj = new(IOBJ"soup");
      obj->move(environment(player));
      return 1;
}
 
 
void ask_cooking()
{
    write(@ALONG
店老板遥望著远方，说道:不是我臭屁啊，任何东西交到我手中，都会变成
美味的佳肴哦！！

*******你隐隐看见他身後涌起了无数的浪花，哦！太阳出来了！！*******
ALONG
        );
	return;
}
