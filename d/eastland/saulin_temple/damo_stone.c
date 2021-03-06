#include "saulin_temple.h"

inherit ROOM;

void create()
{
	::create();
	set("broken",0);
	set_short("达摩面壁处");
	set_long( @C_LONG_DESCRIPTION
这里是达摩祖师面壁十年的地方，虽然狭小阴暗，但是却是少林寺的
圣地，对面的石壁还留有一片黑影(shadow)，相传是达摩祖师的影子在十
年面壁期间所化，现在院内仍有许\多僧人静静面壁，希望也能得证涅盘。
C_LONG_DESCRIPTION
	);
    set("item_desc",([ "shadow" : @C_LONG
你仔细的查看那面黑影，影子忽然活动起来，同时，在你的耳畔想起一阵嗡嗡的话
语 ： 哈哈 !! 我是达摩 .... 的影子，达摩那个死家伙以前在这里面壁，就是为
了要把我从他身上赶出去，他做到了，却把我孤零零的留在这面石壁(wall)上，我
努力修炼了千百年，还是出不了这面墙，如果你肯帮我打破(break) 这面墙，放我
出去看看这个大千世界，我就告诉你一些有关达摩的秘密。
C_LONG
    ]));
        set_outside("eastland");
	set( "exits", ([
		"west" : SAULIN"stone_path3",
	]) );
	reset();	
}

void init()
{
    add_action("break_wall", "break");
}

int break_wall(string arg)
{
	if( !arg || arg !="wall" )
	  if( !this_object()->query("broken") )
        return notify_fail( "影子哈哈大笑：打破什麽？你的笨脑袋吗？\n" );
      else
        return notify_fail("打破什麽？\n");
	if( !this_object()->query("broken") ) {
      tell_object(this_player(),@SHADOW_OUT
  你举起一块大石头往石壁砸去，轰隆一声巨响，石壁完好无损，影子却藉著这一击
  从石壁冲了出来，飞到半空中。它高兴的大喊大叫：我出来了 ! 我出来了!死达摩 
  ! 说什麽要成佛就要禁制恶念，我这不是出来了吗？到底是你强还是我强？哈哈哈
  !! 它又指著你大笑：你这个白痴凡人，我什麽也不会告诉你 !!!
  你觉得你好像闯了大祸了 !! 
SHADOW_OUT
      );
      new( SAULIN_MONSTER"damo" )->move( this_object() );
      this_object()->set("broken",1);   
      this_player()->set_explore("eastland#33");
    } else
      tell_object(this_player(),@NOTHING
你举起一块大石头往石壁砸去，轰隆一声巨响，石壁完好无损，
但影子似乎已无力逃出来。
NOTHING
      );
    return 1;
}

void reset()
{
    ::reset();
    set("broken",0);
}
