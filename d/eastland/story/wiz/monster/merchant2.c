#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(11);
	set_name( "merchant", "·�����׷۸���" );
	add( "id", ({ "merchant" }) );
	set_short( "·�����׷۸���" );
	set_long(@C_LONG
һλ���׷۸���·��С����������ͷ�󺹵��������ˡ�
C_LONG
        );
	set( "gender", "male" );
        set( "wealth/silver",100);
        set_natural_armor(55,2);
        set_natural_weapon( 19,10,20 );
        set("chat_chance",3);
        set("chat_output",({
            "��Ӵ������������úóԵ��׷۸�Ӵ��\n"
        }) );
        set( "inquiry", ([
             "entrance_palace":"@@ask_enter",
        ]) );
}
void ask_enter(object asker)
{
tell_room(environment(),@LONG

���׷۸���˵����ร�����Ҫ��ȥ�ʹ��㣿���ǲ�̫������������������ȥ
������������������̴�ٿ������Ȳ�Ҫ���������Ҫ��Ҫ��һ���׷۸�����

���׷۸�������"��Ӵ������������úóԵ��׷۸�Ӵ��\n"

LONG
   );
}
