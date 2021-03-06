//#pragma save_binary

#include <mudlib.h>
#define TACTIC_D(x) ("/d/martial/tactic/" + x)
#define VALID_TACTIC ({ "none", "berserk", "melee", "flank", "assault" })
#define TACTIC_NUM ([ "none": 0, "berserk": 30, "melee": 50, "assault": 50,\
	"flank": 10, ])
    
inherit DAEMON;

int help();

int cmd_tactic(string str)
{
	string loc;
	
	if( !str || str=="" ) {
		if( (loc= this_player()->query( "tactic" )) ) {
			write( 
				"你现在所使用的战术是 : " + loc + " (" + to_chinese(loc+"_tactic") + ")\n");
			return 1;
		}
		return help();
	}

	if( member_array(str, VALID_TACTIC)==-1 ) return help();

	if( (int) TACTIC_NUM[str] > (int)this_player()->query_skill("tactic") ) {
	  write(
	        "你的必须要有"+(string)TACTIC_NUM[str]+"点以上的战术运用技能才能使用这种战术。\n");
	  return 1;
	}

	if( str == "none" ) {
		this_player()->delete("tactic");
		write( "Ok.\n" );
		return 1;
	}

	if( !TACTIC_D(str)->can_use_tactic(this_player()) )
		return notify_fail("你现在还不会运用这种战术。\n");

	this_player()->set("tactic", str);
	write( "Ok.\n" );
	return 1;
}

int help()
{
	write( @C_HELP
指令格式: tactic <方法>

这个指令用来设定在战斗所要使用的战术，你所能用的战术种类受你的战术技能
限制，若是不使用战术，则设为 none。
你所能使用的战术如下:

berserk:	狂暴攻击，增加破坏力而难以抵挡的攻击战术。
melee:		近身肉搏，兼顾攻击与防御，骑士的一贯战术。
flank:		侧面攻击，面对强大敌人时用以自保的最佳战略。
assault:	伺机突击，杀手型人物的战斗方式。

你可以用 help xxx_tactic 到各种战术进一步的说明。
如:
    help berserk_tactic

此外，某些战术需要某些装备才能使用。
C_HELP
	);
	return 1;
}
