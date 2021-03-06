
#include "saulin_temple.h" 

inherit ROOM;
inherit DAEMON;

void create()
{
	::create();
    set_short("少林龙爪手习练房");
	set_long( @LONG_DESCRIPTION
这是一个宽阔的大房间，墙上龙飞凤舞的写著一个『龙』字，你发现墙壁和梁柱上有
许\多被强劲指力划过的痕迹。
角落坐著一个高大的僧人，地上放著几块破旧的蒲团，老僧似乎完全没有注意到你的存在
 ，仍然在闭目打坐运功\。你发现墙边贴了一张泛黄的纸片(paper)，上面似乎写了一些字
。老僧打坐的蒲团边放著一本书，你隐约看到有个龙字。西边回到七十二绝技房。 
LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "paper":@BOOK
                         
                           龙爪手修习资格

       1. 有七十二绝技僧以上之资格。
       2. 敏捷超过16，力量至少16。  
       3. 基本内功\技能至少72。 
                       
       达到以上资格者，可在此习练龙爪手(practice dragon-claw)之少林绝技 

       注: 如果你想改练别的绝技，可以用散功\ (sangon dragon-claw)，
           你的本绝技经验点仍会被保留，只是不能用。  
BOOK
]));         
	set( "light", 1 );
	set( "exits", ([ 
		"west" : SAULIN"72" ]) );
	set( "objects", ([
		"Monk" : SAULIN_MONSTER"kon-shin" ]) );
	reset();
}

void init()
{
	add_action("to_study","practice");
	add_action("to_delete","sangon");
}

int to_delete(string arg)
{
	object me;
	if( !arg || arg != "dragon-claw" ) return 0;
	me = this_player();
	if( undefinedp( me->query("monk_gonfu/dragon-claw") ) )
	     { write(" 你跟本不曾学过龙爪手! \n");
               return 1;
             }
        else {
        write("你的龙爪手功\力暂时消失了!!! \n"); 
        write("但如重练时旧经验值仍然不变 \n\n"); 
 		me->delete("monk_gonfu/dragon-claw");
 		me->set("monk_learn/72",0);
                return 1;  
         }
} 
int to_study(string arg)
{
	object me;

	if( !arg || arg!="dragon-claw") return 0;

	me = this_player();
	if( !wizardp(me) && (string)me->query("class") != "monk" )
		write("你不是本公会的人所以不能学此功\夫\n");
    else if( (int)me->query_level() < 15 )
		write("『空性说: 你的等级太低，没资格学龙爪手』\n\n");
    else if( (int)me->query_perm_skill("inner-force") < 72 )
		write("『空性说: 你的基本内功\(inner-force)技巧太差，没资格学龙爪手』\n\n");
    else if( ((int)me->query_perm_stat("str") < 16) ||
    		 ((int)me->query_perm_stat("dex") < 16) )
		write("『空性说: 你的力量或敏捷不够，没资格学龙爪手』\n\n");
	else if( !undefinedp(me->query("monk_gonfu/dragon-claw")) ) {
		if((int)me->query("monk_gonfu/dragon-claw")==35) {
			write("空性说道: 嗯，你学的还不错。好吧，让你再去练别种绝技。\n\n");
			me->set("monk_learn/72",0); }	
		else write(" 空性从圃团上看看你，大骂一声:\n"
			"『你真白痴啊! 你已经学过龙爪手了，要专精就快去练习啊!』\n\n" ); }
	else if( me->query("monk_learn/72") )
		write(" 空性从圃团上看看你，大骂一声:\n"
			"『你真贪心啊! 你已经学过一项绝技了，快去练习啊!』\n\n" );
	else { 
		write( @LONG

  『好! 那我现在就教你龙爪手的口诀和招式吧』空性站起来笑道...
 
     『身法八要... 起落进退反侧收纵...』
              
     『足法... 起落翻挣，忌踢宜踩.....』
     
     『意与气合，气与力合，起爪如风，以勇统之...』 
      ........................................... 
 
     『虚势中有玄而若虚，实势中无玄而若实...』 
      ........................................... 
      
     『飞龙抢珠下返上』，『神龙捞月环圈探』... 
     
     『补风捉影势如风』....                
      .................................. 
      
      你终於学完了三十六式龙爪手了...
      
LONG
		);  
        me->set("monk_gonfu/dragon-claw", 0);
        me->set("monk_learn/72",1);
	}
	return 1;  
} 

int clean_up() { return 1 ;}
