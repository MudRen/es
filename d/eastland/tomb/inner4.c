#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("��Ĺ����");
	set_long( 
@C_LONG_DESCRIPTION
�������Ĺ�Ľ��䣬������������ǿ����¡��㿴��һЩ�����ӷ���ǽ�ߣ�Ȼ��������
�����������ˣ������ľ����ա�����֮�⻹��\��\��߱���ٸ\��\����������ǵ���̬��������
��һ�������۹��ݷ���ע�����㣬���뻹�ǸϿ��뿪����ĺá�
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"south" : TOMB"/inner3",
		"west"  : TOMB"/inner5"  ]) );
	reset();	
}

void init()
{
	tell_object( this_player(), 
		"�����������ʱ����Щ����ٸ������ͻȻ�����������к� !!\n"
		);
	this_player()->receive_damage(100);
}
