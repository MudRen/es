#include <mudlib.h>

inherit "/d/healer/poison.c";
void create()
{
	seteuid(getuid());
	set_name("Drunk Wind","������");
	add("id",({"wind"}));
	set_short("������");
        set_long(
                "���Ƕ���ɱ����֯���õ�һ��������ɫ��ҩ��"
                "��Ȼû��ǿ��Ķ���,\n����ʹ��ȫ������,"
                "���������ָ���,����Ҳ��һյ����ܸ�Ԫ��\n"
        	"������� poison <someone> ��ĳ���¶�;�� check ���ʣ�ŵķ�����\n"
	);
	set( "unit", "ƿ" );
	set_duration(20);
	set_effect(10);
	set_type("slow");
	set_times(5);
	set_difficulty(40);
	set("poison_msg","%s�ƺ��޷�˳�����ƶ�..\n");
	set("poison_method","%s��һƿ$P, �������%s��");
}

