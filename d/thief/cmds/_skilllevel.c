#include <mudlib.h>
inherit DAEMON;
int cmd_skilllevel()
{
	object owner;
	owner = this_player();
tell_object(owner,
"���� : "+owner->query("c_name")+"\n"
"\t����\t\t�ȼ�\t\t����\n"
"\t����\t\t"+owner->query("thief_level/backstab")+"\t\t"+owner->query("thief_exp/backstab")+"\n"
"\t��ɵ�\t\t"+owner->query("thief_level/throw-dagger")+"\t\t"+owner->query("thief_exp/throw-dagger")+"\n" );
// "\t͵��\t\t"+owner->query("thief_level/steal")+"\t\t"+owner->query("thief_exp/steal")+"\n" );
	return 1;
}

int help()
{
	write(@HELP
ָ���ʽ : skilllevel
    ���ָ������֪��Ŀǰ����ּ��ܵĵȼ���
HELP
	);
}

