#include "/d/eastland/beggar/dony.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "��н���塻������" );
	set_long(@C_LONG
���ǡ�н���塻��Ψһ��һ��������, ����½����ƽʱ��ϲ��Ϊ����������
������ϸһ��, ����������һ�����ϸ��м, ��Щ��м���Ǵ���ʱ����Ļ�
������������¯����������!����һ�������,���治����ͨ�����õ���������
��
C_LONG
               	);
	set( "light", 1 );
	set( "exits", ([
		"east" : DBEGGAR"north2"
	]) );

	set( "objects", ([
		"fun" : DMONSTER"blackmaster"
	]) );
        set_reset(this_object(),21600);
}
void reset()
{
    set_reset(this_object(),21600);
    ::reset();
}

