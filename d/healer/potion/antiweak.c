#include <mudlib.h>
#include <conditions.h>

inherit MEDICINE;

void create()
{
	medicine::create();
	set_name("strong pill", "������" );
	add( "id", ({"pill"}) );
	set_short("������");
	set_long(
		"���������ϵ��з������Ĳ�ҩ,���������������кܺõ���Ч��\n"
		"����������������,��(eat)������֤������ʮ�껹��һβ����!\n"
	);
	set( "can_eat", 1 );
	set( "unit", "��" );
	set( "weight", 15 );
	set( "value", ({ 50, "silver" }) );
        set( "medication", 50 );
}

void eat(object player)
{
    int stat;
    
	if( !player->query("conditions/weak") ) return;
	tell_object( player, can_read_chinese(player)?
		"�����ȫ���ֳ���������\n": "You recover from poison!\n" );
	stat = (int) player->query("weak");
	player->modify_stat("str",stat);	
	"/std/conditions/weak"->remove_effect(player);
}
