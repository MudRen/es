#include "saulin_temple.h" 

inherit ROOM;
inherit DAEMON;

void create()
{
	::create();
    set_short("少林拈花指功\习练房");
	set_long( @LONG_DESCRIPTION
佛祖拈花微笑，以此为名创此指法，讲究的是王道平和慈悲，制敌而不杀人。   
这是一间比较小但很温暖的房间，整个房间弥漫一股宁静祥和的味道。角落坐著一
位胖胖的和尚，他满脸的笑容宛如一尊弥勒佛。木墙上有许\多的小洞，看来似乎是  
被某种暗器刺穿的痕迹，难道这就是久闻的拈花指力?   在向这位传功\师父请教前
你可以先看看一边的白纸(paper) 。南方可回去七十二绝技房。    
LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "paper":@BOOK
                         
                           拈花指修习资格

       1. 有七十二绝技僧以上之资格。
       2. 心地平和，不好勇斗狠者。      
       3. 力量至少须达到20。      
         
       达到以上资格者，可在此习练拈花指(practice keep-flower)之少林绝技 

       注: 如果你想改练别的绝技，可以用散功\ (sangon keep-flower)，
           你的本绝技经验点仍会被保留，只是不能用。  
BOOK
]));         
	set( "light", 1 );
	set( "exits", ([ 
		"south" : SAULIN"72" ]) );
	set( "objects", ([
		"Monk" : SAULIN_MONSTER"kon-fan" ]) );
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
	if( !arg || arg != "keep-flower" ) return 0;
	me = this_player();
	if( undefinedp( me->query("monk_gonfu/keep-flower") ) )
	     { write(" 你跟本不曾学过捻花指! \n");
               return 1;
             }
        else {
        write("你的捻花指力暂时消失了!!! \n"); 
        write("但如重练时旧经验值仍然不变 \n\n"); 
 		me->delete("monk_gonfu/keep-flower");
 		me->set("monk_learn/72",0);
                return 1;  
         }
} 
int to_study(string arg)
{
	object me;

	if( !arg || arg != "keep-flower") return 0;
	me = this_player();
	if( !wizardp(me) && (string)me->query("class") != "monk" )
		write("你不是本公会的人所以不能学此功\夫\n");
    else if( (int)me->query_level() < 15 )
		write("『空凡笑道: 你的职级太低，还不该学拈花指』\n\n");
    else if( (int)me->query_perm_stat("str") < 20 )
		write("『空凡笑道: 你的力量仍稍有不足』\n\n");
	else if( !undefinedp(me->query("monk_gonfu/keep-flower")) ) {
		if((int)me->query("monk_gonfu/keep-flower")==35) {
			write("空凡笑道: 你已经完全了解拈花指的奥义了，可以再去练习另一种绝技。\n\n");
			me->set("monk_learn/72",0); }	
		else write(" 空凡笑道:\n"
			"『你已经学过拈花指了，我已不能多教你什麽，快去多练习吧!』\n\n" ); }
	else if( me->query("monk_learn/72") )
		write("空凡摇一摇头笑著说\n"
			"『你已经学过一项绝技了!武学在精不在多啊!』\n\n" );
	else {
		write(@LONG

  『好! 那我现在就教你拈花指的口诀和招式吧』空凡满意的点点头道...

      首先先背好内功\之要诀... 
      
     『力源於心，惟取极静，由静力固，永断烦恼... 』  
     
     『人生之遇本空，所缘之境亦如虚无之境...』  
     
     『以寂灭力，资於至静，寂静思惟，修行如是，此乃拈花指内功\之要也。』

     『身法八要... 起落进退反侧收纵...』         
     
     『意与气合，气与力合，起指如风，以仁统之...』 
     
     『虚势中有玄而若虚，实势中无玄而若实...』 
      ........................................... 
      
      空凡大师右手食中二指轻轻搭住，做拈花之状。温和的向你说明武功\细节... 
      .................................. 
      
      你终於学完了捻花指法...心中一片祥和宁静 
      
LONG
		);  
        me->set("monk_gonfu/keep-flower", 0);
        me->set("monk_learn/72",1);
	}  
	return 1;  
}

int clean_up() { return 1 ;}
