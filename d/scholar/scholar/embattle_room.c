#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	seteuid( getuid() );
	set_short("青松轩");
	set_long(
@LONG
这是舞墨轩的阵法研究室, 名曰「青松」。墙上刻画著各种阵法的排列、要诀、
步法以及布阵攻击的方法。你可以看到几位书生一起走著奇特的步法，正在试著模拟
这些阵法，几个书生正低头沉思要如何运用这些阵法。或许你也可以试著去看看墙壁
上(wall)的那些阵法精要。
LONG
	);
        set("item_desc", ([
             "wall": @LONG
墙上刻著：舞墨轩不传之秘，书生阵法精要。
┌——————————————————┐
│   须习得一定基本技能之後方能学习   │
│   否则於修行时对自己有莫大的危险   │
│   现在你可以试著去研习(study)。    │
│   ==============================   │
│                                    │
│      1.  两仪微尘阵 (two)          │
│      2.  天地人三才阵 (three)      │
│      3.  四象璇玑阵 (four)         │
│      4.  八卦游龙阵 (eight)        │
│                                    │
└——————————————————┘
     请使用(help_require)查询学习阵
     法所需要的基本技能。
LONG
            ]) );
	set( "light", 1 );
	set( "exits", ([ 
                "up" : "/d/scholar/scholar/storage",
		"down" : "/d/scholar/scholar/hall" ]) );
	reset();
}

void init()
{
        add_action("do_help_require","help_require");
	add_action("do_study", "study");
}

int do_help_require()
{
  tell_object(this_player(),@LONG
┌———————————————————————┐
│==============================================│ 
│        阵法                  技能需求        │ 
│  1.  两仪微尘阵         阵法(embattle) >= 31 │
│  2.  天地人三才阵       阵法(embattle) >= 51 │  
│  3.  四象璇玑阵         阵法(embattle) >= 71 │ 
│  4.  八卦游龙阵         阵法(embattle) >= 91 │ 
│==============================================│  
└———————————————————————┘
LONG);
  return 1;
}

int do_study(string str)
{
  int emb,ok,ok2=0,is_member=-1,flag;
  string *embat,msg;
  mapping known;

  if (!str)
    return notify_fail("你要研习什麽 ?\n");
  emb=this_player()->query_skill("embattle");
  if (!emb || emb<=30)
    return notify_fail("对不起，你的阵法技能不足以研习这些阵法。\n");
  known=(mapping)this_player()->query("embattle");
  if (known && sizeof(known)!=0) {
    embat=keys(known);
    ok2=1;
  }
  switch (str) {
    case "two":
       if (emb>30) {
         ok=1;
         this_player()->set("embattle/two",1);
       }
       msg="两仪微尘";
       break;
    case "three":
       if (emb>50) {
         ok=1;
         this_player()->set("embattle/three",1);
       }
       msg="天地人三才";
       break;
    case "four":
       if (emb>70) {
         ok=1;
         this_player()->set("embattle/four",1);
       }
       msg="四象璇玑";
       break;
    case "eight":
       if(emb>90) {
         ok=1;
         this_player()->set("embattle/eight",1); 
       }
       msg="八卦游龙";
       break;
    default: return notify_fail("Syntax: study <阵法名>\n");
  }; 
  if (ok2)
    is_member=member_array(str,embat,flag);
  if ((ok==1)&&(is_member>=0))
    ok=2;
  switch (ok) {
    case 1: write("经过一番思考、练习之後，你成功\的学会了"+msg+"阵。\n");
            break;
    case 2: write("你已经会"+msg+"阵了。\n");
            break;
    default: write("你的阵法技能还不够修行"+msg+"阵。\n");
  };
  return 1;
}
