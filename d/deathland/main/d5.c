
#include "../echobomber.h"

inherit "/std/room/waterroom";

void create()
{
	::create();
	set_short("���׷���");
	set_long( @LONG_DESCRIPTION
����Ǳ�뺣�׵����ʱ,�㷢��һ���ǳ��ƾɵķ���(ruin),���ݵ�ʯ
�����ķϵķ����Ѿ�����ˮ��ʴ�Ĳ�������.һ�����(board)�����ڷ����
���,������Ȼ�൱������,��δ�ܵ���ˮ����ʴ.
LONG_DESCRIPTION
	);
set("item_desc",([
    "board":@BOARD
----------------------------------------------------------------
�޴�������,��Ҫ�������ҵ����� Firer ����,������Ⱥ���ں��׵���
�����㼤ŭ����ΰ�������,���ǽ�����İ���.
                  ------Archmage Romus-----
----------------------------------------------------------------
BOARD
   ,"ruin":@RUINS
һ���ǳ��ƾɵķ���.
RUINS
    ]) );
	set( "light", 0 );
set("exits",(["up":Deathland"/main/d4"]));
}
void init()
{
   add_action("to_enter_ruin","enter");
}

int to_enter_ruin(string str)
{

   if (!str||str!="ruin") {
    write("Enter what?\n"); return 1;
     }
  write("Not open yet,please wait a monent\n");    
  // this_player()->move_player(Ruins"/r1",
  // "SNEAK","");
   return 1;
}
