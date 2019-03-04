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
				"��������ʹ�õ�ս���� : " + loc + " (" + to_chinese(loc+"_tactic") + ")\n");
			return 1;
		}
		return help();
	}

	if( member_array(str, VALID_TACTIC)==-1 ) return help();

	if( (int) TACTIC_NUM[str] > (int)this_player()->query_skill("tactic") ) {
	  write(
	        "��ı���Ҫ��"+(string)TACTIC_NUM[str]+"�����ϵ�ս�����ü��ܲ���ʹ������ս����\n");
	  return 1;
	}

	if( str == "none" ) {
		this_player()->delete("tactic");
		write( "Ok.\n" );
		return 1;
	}

	if( !TACTIC_D(str)->can_use_tactic(this_player()) )
		return notify_fail("�����ڻ�������������ս����\n");

	this_player()->set("tactic", str);
	write( "Ok.\n" );
	return 1;
}

int help()
{
	write( @C_HELP
ָ���ʽ: tactic <����>

���ָ�������趨��ս����Ҫʹ�õ�ս�����������õ�ս�����������ս������
���ƣ����ǲ�ʹ��ս��������Ϊ none��
������ʹ�õ�ս������:

berserk:	�񱩹����������ƻ��������Եֵ��Ĺ���ս����
melee:		�����ⲫ����˹������������ʿ��һ��ս����
flank:		���湥�������ǿ�����ʱ�����Ա������ս�ԡ�
assault:	�Ż�ͻ����ɱ���������ս����ʽ��

������� help xxx_tactic ������ս����һ����˵����
��:
    help berserk_tactic

���⣬ĳЩս����ҪĳЩװ������ʹ�á�
C_HELP
	);
	return 1;
}
