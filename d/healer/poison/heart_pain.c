#include <mudlib.h>

inherit "/d/healer/poison.c";

void create()
{
	seteuid(getuid());
	set_name("Heart Pain","��ʩ����");
	add("id",({"heart","pain"}));
	set_short("��ʩ����");
        set_long(
	"����һ����ɫ��ζ��ҩ��, ��˵�ж����˻���ʹ��ֹ,\n"
	"����ʱ,֢״����Ŵ���Ů��ʩ������ü״,����֮��\n"
	"������� poison <someone> ��ĳ���¶�;�� check ���ʣ�ŵķ�����\n"
	);
	set( "unit", "��" );
	set_duration(10);
	set_effect(10);
	set_type("simple_poison");
	set_times(3);
	set_difficulty(65);
	set("poison_msg","%s�����ؿ�, ������ѹ�������..\n");
	set("poison_method","%s�Ӻ�����մ��һЩ$P, ����%s");
}

