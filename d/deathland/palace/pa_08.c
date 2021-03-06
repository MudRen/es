
#include "../echobomber.h"
#define QUEEN_SMILE Deathland+"/adm/queen_smile"

inherit ROOM;
inherit DOORS;
void create()
{
	::create();
set("light",1);
set_short("皇后莉莉丝的起居室");
  set_long(@Long
Long
,@CLong
这里是皇后莉莉丝的寝宫.有一张床,一座化妆台被放置在角落里.除此以外,
并没有任何多馀的物品.
CLong
);
set("echo_special_place",1);
set("exits",([
             "west":Deathland"/palace/pa_05",
             ]));
create_door("west","east",([
             "name":"gold door",
             "c_name":"金色的门",
             "keyword":({"gold door","door",}),
             "c_desc":"金色的门",
             "status":"locked",
             "desc":"a gold door",
             "lock":"ECHO_DWARF_CITY_1",
                     ]) );

set("objects",([
    "queen":Monster"/queen",
     ]) );
reset();
}

void init()
{
	this_player()->set_explore( "deathland#12" );
}

void release(object player,object box)
{
     int i;
     object *monster,falady;
     
     if ( (string)box->query("bottle_lock")=="leit" ) {
       tell_object(player,
      "莱特的灵魂被释放後, 一下子就消失的无影无踪了.\n");    
       box->delete("quest_action/bottle_lock");
       return; 
       }
     monster=all_inventory(this_object());
     for(i=0;i<sizeof(monster);i++) 
        if ( monster[i]->id("queen") && monster[i]->query("npc") ) {
          tell_object(player,
          "你释放出法拉第的灵魂.\n"
          "法拉第慢慢地出现在你的面前.\n"
          );
          box->delete("quest_action/bottle_lock");
          falady=new(Monster"/falady");
          falady->move(this_object());
          tell_room(this_object(),
          "当皇后见到他儿子的时候, 高兴地流下了眼泪.\n"
          "法拉第也是很高兴,两人於是聊了很久.\n",
          ({falady,monster[i],}) ); 
          call_out("quest_info",10,player,falady,box);
          return;
          } 
     box->delete("quest_action/bottle_lock");
     tell_object(player,
      "法拉第的灵魂被释放後, 一下子就消失的无影无踪了.\n");
     return; 
}

void quest_info(object player,object falady,object box)
{
     tell_room(this_object(),
     "过了很久, 法拉第向她母亲挥挥手, 然後就消失了.\n"
     );
     falady->remove();
     tell_object(player,
     "皇后这时对你说: 谢谢你, 我已经知道我儿子在另一个世界里活的很好.\n"
     "我也应该忘掉悲伤, 不要让其他人为我担心了.\n"
     "皇后愉快地微笑著.\n" 
     "**********************************\n"
     "你完成了这个艰难的任务.\n"
     "**********************************\n"
     );
     tell_room(this_object(),"皇后愉快地微笑著.\n",player);
     if ( (int)player->query_quest_level("queen_smile")< 5 )
       player->finish_quest("queen_smile",5);
     return;
}
