#include <mudlib.h>
#include <conditions.h>

inherit MEDICINE;

void create()
{
	medicine::create();
	set_name("spirit pill","������" );
	add( "id", ({"pill"}) );
	set_short("������");
	set_long(
		"����һ����ҽ��������������裬��(eat)�������Խ�����ҵ�\n"
		"״̬��\n"
	);
	set( "can_eat", 1 );
	set( "unit", "��" );
	set( "weight", 10 );
	set( "value", ({ 30, "silver" }) );
        set( "medication", 50 );
}

void eat(object player)
{
	if( !player->query("conditions/confused") ) return;
//      tell_object( player,
//             "���������������Ѷ��� !\n");
	CONFUSED->remove_effect(player);
}
