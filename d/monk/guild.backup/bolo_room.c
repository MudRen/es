#include "saulin_temple.h" 

inherit ROOM;
inherit DAEMON;

void create()
{
	::create();
    set_short("dragon-claw room","少林般若掌习练房");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
这是一个很宽敞明亮的房间，整个房间弥漫一股檀香味。由於长久不断的使用，你发
现地上都是一个个的脚印。    
般若掌是少林七十二绝技中最常被使用和学习的武技，虚合大师修练般若掌已有四十多年
的火候了，你可以放心向他请教。当然墙上的须知(paper) 你不妨先看看。  
C_LONG_DESCRIPTION
	);

    set("c_item_desc",([
         "paper":@BOOK
                         
                           般若掌修习资格

       1. 有七十二绝技僧以上之资格。
       2. 敏捷超过16，力量至少17。  
       3. 基本内功\技能至少70。 
                       
       达到以上资格者，可在此习练般若掌(practice bolo-fist)之少林绝技 

       注: 如果你想改练别的绝技，可以用散功\ (sangon bolo-fist)，
           你的本绝技经验点仍会被保留，只是不能用。  
BOOK
       ]));         
	set( "light", 1 );
	set( "exits", ([ 
		"east" : SAULIN"72" ]) );
	set( "objects", ([
		"Monk" : SAULIN_MONSTER"shi-hur" ]) );
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
	if( !arg || arg != "bolo-fist" ) return 0;
	me = this_player();
	if( undefinedp(me->query("monk_gonfu/bolo-fist")) )
        {	write("虚合摇了摇头说: 你跟本不曾学过般若掌!\n");
                return 1;
        }
        else {
               write("好吧那我就成全你!!!! \n\n");
               write("虚合大力往你背上一拍，你的般若掌力暂时消失了!!!\n\n");
               write("『放心吧! 下次再来练般若掌时你目前的经验值并不会失去!』\n\n");
 		me->delete("monk_gonfu/bolo-fist");
 		me->set("monk_learn/72",0);
                return 1;  
              }
} 

int to_study(string arg)
{
	object me;
	if( !arg || arg != "bolo-fist" ) return 0;
	me = this_player();
	if( !wizardp(me) && (string)me->query("class") != "monk" )
		write("你不是本公会的人所以不能学此功\夫。\n");
	else if( (int)me->query_level() < 15 )
		write("『虚合曰: 你的职级太低，没资格学般若掌。\n");
	else if( (int)me->query_perm_skill("inner-force") < 70 )
		write("『虚合曰: 你的基本内功\(inner-force)技巧太差，没资格学般若掌。\n");
	else if( ((int)me->query_perm_stat("str") < 17) ||
			 ((int)me->query_perm_stat("dex") < 16) )
		write("虚合笑道: 你的力量或敏捷不够，还没资格学般若掌。\n");
	else if( !undefinedp(me->query("monk_gonfu/bolo-fist")) )
		write("虚合摇了摇头说: 你已经学过般若掌了，快去多练习吧!\n");
    else if( me->query("monk_learn/72") )
		write("虚合摇一摇头说: 你已经学过一项绝技了!\n");
    else {
		write(@LONG
	
	『好! 那我现在就教你般若掌的口诀和招式吧』虚合满意的点点头道...

     首先先背好内功\之要诀... 

     『却将纷飞之心，以究纷飞之处，究之无处，则纷飞之念何存... 』  
     
     『能照之智本空，所缘之境亦及寂...』
 
     『外不寻尘，内不住定，二途俱茫，一性怡然，此乃般若掌内功\之要也。』

     『身法八要... 起落进退反侧收纵...』         
     
     『意与气合，气与力合，起掌如风，以勇统之...』 
     
     『虚势中有玄而若虚，实势中无玄而若实...』 
      ...........................................
      
     『天衣无缝 乃右掌力微而实，左掌力沉而虚...』...
      ..................................
      
      你终於学完了般若掌法...
 
LONG
 		);  
 		me->set("monk_gonfu/bolo-fist", 0);
 		me->set("monk_learn/72",1);
 	}  
    return 1;  
} 
