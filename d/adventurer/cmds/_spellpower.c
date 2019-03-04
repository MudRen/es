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
	string *sp_msg = ({ "���", "�Ը�", "һ��", "�Ե�", "��С" });
	
		spell_power = (int)this_player()->query("spell_power");
		if ((spell_power <=0) && (spell_power>-5))
			write( "����������"+sp_msg[-spell_power]+"������ʩչ������\n");
		else if (spell_power>0)
			write( "�㽫�̶�ʩչ"+chinese_number(spell_power)+"���ķ�����\n");
		else if (spell_power<=-5)
			write( "�㽫�Էǳ�С�ķ�����ʩչ������\n");
	return;
}

int help()
{
		write( @C_HELP
ָ���ʽ: spellpower [����]

���ָ�������������Ʒ������������趨Ϊ max, regular, normal, minor, mini
�ֱ����ʩ������Ϊ������ȼ�, ������ȼ���һ, ������ȼ�����... �ȵ�
С��������㼶���㡣
�����Ĳ���Ҳ����ʹ�����ִ���, 0 ��ʾ������, -1, -2, -3, -4 �������� 
regular, normal, minor, mini ͬ��
������ʾǿ���޶�ʩչĳ���ķ���, �� spellpower 3 ��ʾ��ʩչ�������ķ�����
��Ȼ, ���������ʩ���������ȼ�ʱ���������ȼ����㡣
C_HELP
		);
    return 1;
}
