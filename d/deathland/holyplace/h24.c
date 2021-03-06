
#include "../echobomber.h"
#include <move.h>
inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("mystic fire","妖火");
  set_long(@Long
Long
,@CLong
你已经清楚地看到那团妖火了, 只见一种邪恶的气氛由火团里散出, 令人不寒
而栗. 
CLong
);
set("item_func",([
    "fire":"to_look_fire",
    ]) );
set("search_desc",([
    "fire":"一团可怕的火, 你最好别太靠近它.\n",
    ]) );    
set("exits",([
             "east":Deathland"/holyplace/h23",
             ]));
reset();
}

int to_look_fire()
{
    object player;
    player=this_player();
    write("当你看著那团火的时候, 你的人觉得昏昏沉沉的, 只觉得有个模模"
          "糊糊的人影慢慢地出现在你的眼中.\n");
    player->set_temp("block_command",1);          
    say("当"+player->query("c_short")+"注视著火团的时候, 你觉得他好像失了魂似的.\n");
    call_out("quest",3,player);
    return 1;
}

void quest(object player)
{
     tell_object(player,
     "一道清晰的声音传入你的脑海.\n"
     "我, 暗黑巫妖 , 邪恶之神 YANG 的弟子 , 艾思(ICE) , 现在召唤你.\n"
     "你很荣幸地可以为我效劳. 我须要一个人帮我解除禁锢於我身上的诅咒\n"
     ", 你只须要找到我的骇骨, 撕掉附在它身上的那道符咒, 然後回到这里\n"
     "你将得到你的报偿.\n"
     );  
     if ( present("paper",player) ) { 
       tell_object(player,
       "想不到你带回了这个该死的符咒, 我想我将可以恢复我的魔力了.\n"
       "哈哈哈.....\n\n\n\n"
       "此时你看到妖火慢慢地由明变暗........\n"
       );
       call_out("quest_2",4,player);
       }
     else
       player->set_temp("block_command",0);
     return;
}


void quest_2(object player)
{
     object item;
     int moveflg;
     
     tell_object(player,
     "\n\n\n\n\n\n火再度地亮了起来.\n\n"
     "妖火说到: 那符咒已经被下了极可怕的咒语, 凡人将无法解除它.\n"
     "想不到哈德瑞得屈里的魔力变得如此强大. 这个可恶的家伙, 我\n"
     "想到如今他的法力也应该和我当年一样了吧! \n"
     "我能寄望你能为我打败他吗? 不过我也没有选择了. 送你一个月\n"
     "之钻. 这是唯一你能够击败他的物品, 但是经过了这几个世纪,\n"
     "不知还有没有效. \n"
     );
     item=new(Object"/diamond01");
     moveflg=item->move(player);
     if ( moveflg !=MOVE_OK ) { 
       tell_object(player,
       "**你无法拿的动这月之钻**.\n"
       );
       item->remove();
       }
     player->set_temp("block_command",0);
     return ;  
}
