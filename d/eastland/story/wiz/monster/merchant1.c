#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(11);
	set_name( "merchant", "·�������м��" );
	add( "id", ({ "merchant" }) );
	set_short( "·�������м��" );
	set_long(@C_LONG
һλ�����м��·��С����������ͷ�󺹵��������ˡ�
C_LONG
        );
	set( "gender", "male" );
        set( "wealth/silver",100);
        set_natural_armor(55,2);
        set_natural_weapon( 19,10,20 );
        set("chat_chance",3);
        set("chat_output",({
            "��Ӵ���Ͻ����ԺúóԵ����м�Ӵ��\n"
        }) );
        set( "inquiry", ([
            "fly_building":"@@ask_building",
        ]) );
}
void ask_building(object asker)
{
tell_room(environment(),@LONG

�����м��˵�����춼������ǰ�����п���ร������ˣ�������·��������
�����������������ߵ�ɽ���Ͽ���һ��Ư���ڿ��еĽ�����������ǲ���
��������������������˵���춼�������������ȥ��̽���һ�Ҳ�«������
���������������������С���ʯ���ˡ�(golden_older)������˵������ʱ��
		���춼����Ӵ���Ȳ�Ҫ���������Ҫ��Ҫ�������м尡������
����
LONG
   );
}
