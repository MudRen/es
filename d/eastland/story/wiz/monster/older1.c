#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name( "older", "��ͷ��" );
	set_short( "��ͷ��" );
	set_long(@C_LONG
һλ�׷��Բ����ƺ᲼���ˣ�������������������һ������һ�߿���С������Ϸ��
C_LONG
        );
	set( "gender", "male" );
        set_natural_armor(30,0); 
        set_natural_weapon( 9,3,8 );
        set("chat_chance",10);
        set("chat_output",({
           "��ͷ���������������ȥ�춼(fly_building)���Ӵ��\n"
        }) );
}
