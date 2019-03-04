#include <mudlib.h>
#define VALID_LOC ({ "vascular", "ganglion", "weakest", "critical" })

inherit DAEMON;

int help();

int cmd_aim(string str)
{
	string loc;

	if( !str || str=="" ) {
		if( (loc= this_player()->query( "aiming_loc" )) ) {
			write( "�������趨ս��ʱ��׼: " + loc + " ( " + to_chinese(loc) + " )\n");
			return 1;
		}
		return help();
	}
	if( !this_player()->query_skill("anatomlogy") )
		return notify_fail("�㲢û��ѧ������ѧ ....��\n");
	if( member_array(str, VALID_LOC)==-1 ) return help();
	this_player()->set("aiming_loc", str);
	write( "Ok.\n" );
	return 1;
}

int help()
{
	write( can_read_chinese()? @C_HELP
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
               �ɹ�\���᲻��

C_HELP
	:@HELP
Syntax: aim <location/point>

This command enables you to try to hit some special location of your 
opponent. Once these locations are hit, it may cuase some conditions
to the victim such as critical damage, paralyze, blind .... etc. The
chance to hit depend on your anatomlogy skill, the location you are
aiming, your weapon and the opponent's ability.

You can aim the following locations:

ganglion -     Can make the victim feel great pain and fails to perform
               attacks for several rounds.
vascular -     Can make the victim bleeds.
weakest -      Can inflict maximum damage you can make on the victim's 
               weakest point.
critical -     Can inflict critical damage, make victim's hit points reduced
               to 1/3 immediately.
HELP
	);
	return 1;
}
