#include "../ekravia.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "old alchemist", "������ʦ" );
	add( "id", ({ "alchemist" }) );
	set_short( "��������ʦ" );
	set_long(@LONG
�㿴��һ��������ɫ���۵�����, ��������������һ����ƿ����������æ
��ĳ��ʵ�顣��Լ�Ƿ�����ĵ�����? ��ͣ���ֱߵĹ���, �ع���������
��΢Ц��
LONG
	);
	set( "gender", "male" );
	set( "alignment", 500 );
	set( "wealth/silver", 1000 );
	set( "no_attack", 1 );
	set( "chat_chance", 15 );
	set( "chat_output", ({
		"��������ʦ���е��ʵ�:����Ҫʲ����? �����ˡ�\n",
		"��������ʦ��ͷ���������ʵ�顣\n",
		"��������ʦ˵��:�������в����Ϻõ�ҩ��, �Լ��ο�һ���嵥��!��\n",
	}) );
}
