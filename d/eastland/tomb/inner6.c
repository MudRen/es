#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("��Ĺ����");
	set_long( 
@C_LONG_DESCRIPTION
�������Ĺ�Ľ��䣬������������ǿ����¡��㿴��\��\��\���Ĵ���ӷ���ǽ�ߣ�Ȼ��
�����ƺ����������ˣ�������շǳ����ӽŵ��´��������ˮ���Լ�˿˿�ĺ��⣬���뻹��
�Ͽ��뿪����ĺá�
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"south" : TOMB"/inner7",
		"east"  : TOMB"/inner5"  ]) );
	reset();	
}

void init()
{
	tell_object( this_player(), 
		"�����������ʱ��һ��Ắ��ˮ��ͻȻ�������ð�� !!\n"
		);
	this_player()->receive_special_damage("cold",100);
}
