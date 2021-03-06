#include "saulin_temple.h" 

inherit ROOM;
inherit DAEMON;

void create()
{
	::create();
    set_short("dragon-claw room","少林大力金刚指习练房");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
这是一个很宽敞明亮的房间，整个房间弥漫一股檀香味。由於长久不断的使用，你发
现地上的石板都被磨成黑色的了。    
这个房间居然没有人在，只在墙上贴了一张纸(paper) 。  
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "paper":@BOOK
                         
                           大力金刚指修习资格

       1. 有七十二绝技僧以上之资格。
       2. 力量至少18。  
       3. 基本内功\技能至少72。 

       本室之空无大师出寺查案，需多日才可回此。                       
       达到以上资格者，可自行在此习练大力金刚指(practice power-finger) 

       注: 如果你想改练别的绝技，可以散功\ (sangon power-finger)，
           你的本绝技经验点仍会被保留，只是不能用。  
BOOK
]));         
	set( "light", 1 );
	set( "exits", ([ 
		"down" : SAULIN"72" ]) );
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
	if( !arg || arg != "power-finger" ) return 0;
	me = this_player();
	if( undefinedp( me->query("monk_gonfu/power-finger") ) )
	     { write(" 你跟本不曾学过大力金刚指! \n");
               return 1;
             }
        else {
        write("你的金刚指力暂时消失了!!! \n"); 
 		me->delete("monk_gonfu/power-finger");
 		me->set("monk_learn/72",0);
                return 1;  
         }
} 

int to_study(string arg)
{
	object me;

	if( !arg || arg != "power-finger" ) return 0;

	me = this_player();
	if( !wizardp(me) && (string)me->query("class") != "monk" )
		write("你不是本公会的人所以不能学此功\夫。\n");
	else if( (int)me->query_level() < 15 )
		write("『 你的职级太低，没资格学。\n");
	else if( (int)me->query_perm_skill("inner-force") < 72 )
		write("『 你的基本内功\(inner-force)技巧太差，没资格学。\n");
	else if( ((int)me->query_perm_stat("str") < 17) 
			  )
		write(" 你的力量不够，还没资格学大力金刚指。\n");
	else if( !undefinedp(me->query("monk_gonfu/power-finger")) )
		write("你已经学会大力金刚指了，快去练习吧!\n");
    else if( me->query("monk_learn/72") )
		write("你已经学过一项绝技了!\n");
    else {
		write(@LONG
	
     你翻开 大力金刚指 密笈，开始细细读了起来... 

     首先先背好内功\之要诀... 

     『一切有为法，如梦幻泡影，如雾亦如电，应做如是观... 金刚波罗密心经 』  
     
     『能刚之力本空，所缘之气亦寂...』
 
     『外但寻尘，内亦住定，二途俱茫，一性怡然，此乃大力金刚指内功\之要也。』

     『意与气合，气与力合，起指如风，以勇统之...』 
     
     『虚势中有玄而若虚，实势中无力而若实...』 
      ...........................................
      
     『金刚破魔力，乃本指力之终式... 形蕴而力含......』...
      ..................................
      
      你终於学到了 大力金刚指...
 
LONG
 		);  
 		me->set("monk_gonfu/power-finger", 0);
 		me->set("monk_learn/72",1);
 	}  
    return 1;  
} 
