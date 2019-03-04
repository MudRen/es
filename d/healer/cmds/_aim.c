////#pragma save_binary
#include <mudlib.h>
#define VALID_LOC ({ "vascular", "ganglion", "weakest", "critical" })

inherit DAEMON;

int help();

int cmd_aim(string str)
{
	string loc;

	if( !str || str=="" ) {
		if( (loc= this_player()->query( "aiming_loc" )) ) {
			write( "�������趨ս��ʱ��׼: " + loc + " ( " + to_chinese(loc) + " )\n" );
			return 1;
		}
		return help();
	}
	if( !this_player()->query_skill("anatomlogy") )
		return notify_fail( "�㲢û��ѧ������ѧ ....��\n" );
	if( member_array(str, VALID_LOC)==-1 ) return help();
	this_player()->set("aiming_loc", str);
	write( "Ok.\n" );
	return 1;
}

int help()
{
	write(@C_HELP
ָ���ʽ: aim <��λ>

���ָ��������ս���г���ȥ���е��˵�ĳЩ���ⲿλ����Щ��λһ�����У��п�
����ɵ��˸������˻��������Ľ��ͣ��������ӵ��˵Ĳ�ͬ����׼�Ĳ�λ����Ľ�
��ѧ��������ʹ�õ�����������

��������׼�Ĳ�λ��:

ganglion -     �񾭾ۼ��ĵط������������������ڼ��غ����޷�������
vascular -     Ѫ�ܾۼ��ĵط������������ʹ����Ѫ����ֹ��
weakest -      ���˷����������Ĳ�λ�����������ʹ�����ܵ���Ŀǰ�������
               ������˺���
critical -     ���˵��������㣬������ʹ���˵������������� 1/3 ���£�����
               �ɹ����᲻��

C_HELP
	);
	return 1;
}
