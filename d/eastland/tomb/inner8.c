#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("��Ĺ����");
	set_long( 
@C_LONG_DESCRIPTION
�������Ĺ�Ľ��䣬������������ǿ����¡��㿴��\��\��\���Ĵ����ӷ���ǽ�ߣ�Ȼ��
�����ƺ����������ˣ������ľ����ա���������һ��ߴ��ͭ����һ�����Ŀ��������ͭ��
�з������յ���ͷ��Ŀѣ�����뻹�ǸϿ��뿪����ĺá�
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"north" : TOMB"/inner7",
		"east"  : TOMB"/inner1"  ]) );
	reset();	
}

void init()
{
	tell_object( this_player(), 
		"�����������ʱ��ͭ����ͻȻ����һ��ǿ�⴩��������� !!\n"
		);
	this_player()->receive_special_damage("electric",100);
}
