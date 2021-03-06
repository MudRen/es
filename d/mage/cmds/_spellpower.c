//#pragma save_binary
// create by Kyoko.
#include <mudlib.h>

inherit DAEMON;

int help();
void write_power_message(int spell_power);

int cmd_spellpower(string str)
{
    int sub;
    string type;
    
	if( !str ) {
		write_power_message(sub);
		return 1;
	} 
	else if( sscanf( str, "%s", type )==1 ) {
		if (!sub = atoi(type))
			switch(type) {
				case "0"	   :
				case "max"     : sub = 0; break;
				case "regular" : sub = -1; break;
				case "normal"  : sub = -2; break;
				case "minor"   : sub = -3; break;
				case "mini"    : sub = -4; break;
				default : return help();
			}
		this_player()->set("spell_power",sub);
		write_power_message(sub);
		return 1;
	} else
		return help();
}


void write_power_message(int spell_power)
{
	string *sp_msg = ({ "最大", "稍高", "一般", "略低", "最小" });
	
		spell_power = (int)this_player()->query("spell_power");
		if ((spell_power <=0) && (spell_power>-5))
			write( "你正打算以"+sp_msg[-spell_power]+"的能力施展法术。\n");
		else if (spell_power>0)
			write( "你将固定施展"+chinese_number(spell_power)+"级的法术。\n");
		else if (spell_power<=-5)
			write( "你将以非常小的法力来施展法术。\n");
	return;
}

int help()
{
		write( @C_HELP
指令格式: spellpower [出力]

这个指令让你用来控制法术出力，可设定为 max, regular, normal, minor, mini
分别代表施法级数为最大法术等级, 最大法术等级减一, 最大法术等级减二... 等等
小於零则以零级计算。
出力的部份也可以使用数字代替, 0 表示最大出力, -1, -2, -3, -4 与上述的 
regular, normal, minor, mini 同。
正数表示强制限定施展某级的法术, 如 spellpower 3 表示将施展第三级的法术。
当然, 超过你的所施法术的最大等级时还是照最大等级计算。
C_HELP
		);
    return 1;
}
