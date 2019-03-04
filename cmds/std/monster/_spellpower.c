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
		write( "�㷨���ĳ���Ŀǰ��ɽ���"+chinese_number(sub)+"����\n" );
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
		write( "�㷨���ĳ�����������ɽ���"+chinese_number(sub)+"����\n" );
		return 1;
	} else
		return help();
}

int help()
{
	if( can_read_chinese() )
		write( @C_HELP
ָ���ʽ: spellpower [����]

���ָ�������������Ʒ������������趨Ϊ max, regular, normal, minor, mini
�ֱ����ʩ������ΪMax, Max-1, Max-2 ... С��������㼶���㡣
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
