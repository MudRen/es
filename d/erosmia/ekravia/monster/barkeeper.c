#include "../ekravia.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "barkeeper", "�Ʊ�" );
	add( "id", ({ "barkeeper" }) );
	set_short( "�Ʊ�" );
	set_long(@LONG
����ϴ������, �����¸��˿������, ż����ǰ��Ĺ˿͵�����̸��
�ưɵľƱ����Ǹ�����Ϣ����ͨ���ˡ�
LONG
	);
	set( "gender", "male" );
	set( "alignment", 50 );
	set( "no_attack", 1);

	set( "chat_chance", 15 );
	set( "chat_output", ({
		"�Ʊ�ĬĬ�ز�ϴ�����ӡ�\n",
		"һ��ǰ��Ŀ�����Ʊ�Ҫ�˱���, �Ʊ����˵�ͷ, ��ʼ���������\n",
	}) );
	
	set( "inquiry", ([
		"rumor" :	
		"���ûʲ����Ϣ, ֻ��˵����������������ֵ�����(phantom)��û��",
		"phantom" :	
		"���Ҳ��Ǻ����, �����ƹ�ɳ��˹������������������, ˭������һ����\n"
		"�������������?",
	]) );
}
