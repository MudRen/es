#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "shopkeeper", "�̵�����" );
	add( "id", ({ "keeper", "shop keeper" }) );
   set_short( "�̵�����" );
	set_long(
		"��λ�ϰ��Ǹ���ʹ�Լ�塢��ʮ���ŵ���ˣ�����������ʱ��\n"
		"�����������ط���������˻�˵�������ԡ�\n"
	);
	set( "no_attack", 1 );
#include <replace_mob.h>
}
