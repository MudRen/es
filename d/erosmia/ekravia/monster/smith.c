#include "../ekravia.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "smith", "����" );
	add( "id", ({ "smith" }) );
	set_short( "����" );
	set_long(@LONG
һ����Ŀ���Ĵ�, ������������, ����󺹵��ڹķ�¯�Թ�������
LONG
	);
	set( "gender", "male" );
	set( "alignment", 100 );
	set( "wealth/silver", 300 );
	set( "no_attack", 1 );
	set( "chat_chance", 15 );
	set( "chat_output", ({
		"����ʹ���ذѿ����ͽ�¯����, һʱ��¯���ʢ, �������䶼����������\n",
		"������¯��ȡ���պ����ˮ, ���䵹��ģ������Ρ�\n",
		"�������ر�����һ�һ鳵��ô����ȵĵ���, �����ŵ����ʴ������\n",
	}) );
}
