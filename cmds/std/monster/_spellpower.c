//#pragma save_binary
// create by Kyoko.
#include <mudlib.h>

inherit DAEMON;

int help();

int cmd_spellpower(string str)
{
    int sub;
    string c_sub, type;

	if( !str ) {
		sub = (int)this_player()->query("spell_power");
		write( "你法术的出力目前设成降低"+chinese_number(sub)+"级。\n" );
		return 1;
	} else if( sscanf( str, "%s", type )==1 ) {
		switch(type) {
			case "max"     : sub = 0; break;
			case "regular" : sub = 1; break;
			case "normal"  : sub = 2; break;
			case "minor"   : sub = 3; break;
			case "mini"    : sub = 4; break;
			default : return help();
		}
		this_player()->set("spell_power",sub);
		write( "你法术的出力现在重设成降低"+chinese_number(sub)+"级。\n" );
		return 1;
	} else
		return help();
}

int help()
{
	if( can_read_chinese() )
		write( @C_HELP
指令格式: spellpower [出力]

这个指令让你用来控制法术出力，可设定为 max, regular, normal, minor, mini
分别代表施法级数为Max, Max-1, Max-2 ... 小於零则以零级计算。
C_HELP
		);
	else write ( @HELP
Usage:	power [type] || power <on|off>

This command let you set the power of spells. You can set 
"max", "regular", "normal", "minor", "mini" 
meaning the level of you casting is Max, Max-1, Max-2 ... smallest is 0.
HELP
    );
    return 1;
}
