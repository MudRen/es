#include "../ekravia.h"

inherit MONSTER;

void create()
{
	object	staff;

	::create();
	set_level(5);
	set_name( "The old Shilator", "��ϯ����" );
	add( "id", ({ "man", "shilator" }) );
	set_short( "��ϯ����" );
	set_long(@LONG
�㿴��һ���������ȵ�����, ������ؿ����㡣���ƺ����úܶ�����, ��
��\������������������е����ѡ�
LONG
	);
	set( "gender", "male" );
	set( "alignment", 200 );
	set( "wealth/silver", 100 );
	
	wield_weapon( OBJ"staff" );
}
