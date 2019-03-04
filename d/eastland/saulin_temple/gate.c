#include "saulin_temple.h"

inherit ROOM;

void create()
{
	::create();
	set_short("�����´���");
	set_long( @C_LONG_DESCRIPTION
�������ǰ��һ����ΰ��ɽ�ţ����������ɷ���ıʼ���д���������¡�
���֣���˵���Ƕ����ʵ۵��漣���Ա��������¶Զ��������Ĺ��ף��������
��������һƬ���ʵ�Χǽ���������������»���������ʹ�������¸������أ�
��ǰ����һ����ʯ���ݣ����������¶�����Ҫ��·�� 
C_LONG_DESCRIPTION
	);
        set_outside("eastland");
	set("no_monster", 1);
	set("objects",([
	    "monk1" : SAULIN_MONSTER"greet_monk",
	    "monk2" : SAULIN_MONSTER"greet_monk",
	    "monk3" : SAULIN_MONSTER"greet_monk",
	    "monk4" : SAULIN_MONSTER"greet_monk",
	]) );
	set( "pre_exit_func", ([
		 "enter" : "check_weapon",
	]) );
	set( "exits", ([
		 "enter" : SAULIN"front_square2",
		 "down"  : SAULIN"road4",
	]) );
	reset();
}

int is_a_weapon(object item)
{
	if( item->query("weapon_class") && !item->query("prevent_drop")) 
		return 1;
	return 0;
}

int check_weapon()
{
	object *weapons;
	weapons = filter_array( all_inventory( this_player() ),
			"is_a_weapon", this_object() );
	if( wizardp(this_player()) || !weapons || !sizeof(weapons) || 
		!present("monk") ) return 0;
	tell_object( this_player(), 
		"֪��ɮ˵��: ʩ��, �Բ���, �������ڽ�ɱ, ���������������\n" 
	);
	return 1;
}
