#include "../zeus.h"

inherit OBJECT;

void create()
{
	set_name("magic magnetite", "ħ��������" );
	add("id",({"magnetite"}));
	set_short( "...","ħ��������" );
	set_long("..",
	"����һ��ǧ���ѷ���Ϻ����ʣ��������Ƴ������������޼᲻�ݣ�\n"
	"�޵в��ˣ���ͬ�ģ����޾����Ĵ��������д˿�������Ȼ��\n"
	);
	set("unit","��");
	set("weight", 50 );
}