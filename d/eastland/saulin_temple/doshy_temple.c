//File: doshy_temple.c 兜率大士院

#include "saulin_temple.h"

inherit ROOM;

void create()
{

       ::create();
	   set("kissed",0);
       set_short("Doshy temple","兜率大士院" );
       set_long( @LONG_DESC
empty
LONG_DESC
                 ,@C_LONG_DESC
这里是供奉普渡众生的观音大士的地方，不同於少林寺其他地方的是： 
不知道为什麽除了每日服事僧会来洒扫之外，这里几乎是人迹罕至。院内供
奉的一尊白玉观音(statue)，执瓶挥柳似欲遍撒甘霖，宝像十分庄严中却带
了七分俏丽。门外是一片寂寂的树林。
C_LONG_DESC
               );
       set( "light", 1 );
       set("exits",([
		"north" : SAULIN"forest1",
       ]) );
       reset();
       set("c_item_desc",([ "statue" : @C_LONG
你走上前去仔细端详尊白玉观音，突然眼睛一花，眼前竟然出现了一位
美貌少妇(woman),她对你妖媚的笑著，不停的用她那对勾魂慑魄的凤眼
看著你，你感到一阵前所未有的心跳，忍不住想上前亲亲(kiss)她。
C_LONG
       ]));
}

void init()
{
	add_action( "kiss_woman", "kiss" );
}

int kiss_woman(string arg)
{
	if( !arg || arg !="woman" )
      return notify_fail(can_read_chinese() ?
    	"你变态啊 ! 亲墙壁吗？\n" :
		"kiss what ? You stupid nut ?\n" );
    if( this_object()->query("kissed") )
      tell_object(this_player(), can_read_chinese()?
        "那少妇大叫一声转身就逃：色狼啊! 色狼啊! 来人啊! 有人非礼啊 ～～\n"+
        "你顿时慌了手脚，转身就跑，没想到一头撞在墙上，原来只是幻想。\n" :
        "The woman run away and scream : Help !! Colorwolf !\n"
      );
	else {
      tell_object(this_player(), can_read_chinese()? @SHADOW_OUT
你露出了色狼的嘴脸，冲上前去抱著那位少妇猛亲。咦？怎麽毛毛的？难道这女
人长胡子吗？哇 ! 你定睛一看，怀里抱的怎麽是一只眯眯眼的狐狸？

狐狸嘻嘻一笑：哈哈 ! 我等你好久了 ! 狼先生 !! 让我吸吸你的阳气吧 !

SHADOW_OUT
   : "The fox shout to you : Oh ! come on baby ! I need your blood !!\n"
      );
      new( SAULIN_MONSTER"fox" )->move( this_object() );
      this_object()->set("kissed",1);
    }
    return 1;
}

void reset()
{
    ::reset();
    set("kissed",0);
}
