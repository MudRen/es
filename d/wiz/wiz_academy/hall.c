#include <mudlib.h>
#include "academy.h"

inherit ROOM;

void create()
{
	::create();
	set( "light", 1);
	set( "max_laod", 100000 );	
	set_short( "The Hall", "��ڴ���" );
	set_long( @LONG
It needs work here.	
LONG
, @C_LONG
��������ʦѧԺ�Ĵ���, �ɴ˿���ǰ��ѧԺ�еļ�����ͬ�Ĳ��š���
����������Ҫ�Ĳ���, ��ʼѧϰ������ʦ�ǿ�����ǰ�����ߵĿ��Ʋ���,
�����������ѧ����ʽ����ʦ����ӵ�еĸ�������, �����ʹ����Щ����
�����׵�ѧ���������ǰ�����ߵ����Բ���, ѧϰ����������������--
LPC ���ķ�����������ڱ��ߵ�ʵ�鲿��ѧϰ��ο�ʼ������Ʒ������
���뽨�췿���, ��ѧϰ��ν��δ֪�����⡣

    ����ѧ�����еĿγ�֮��, ���ߵ�ʵ�鲿�Ž������һ������Ŀ���
��ͨ���������, �����ȡ�ó�Ϊ��ʽ��ʦ�ı�Ҫ�ʸ�
C_LONG
	);
	set( "light", 1 );
	set( "exits", ([
		"south"  : HERE"entry",
		"west"	: HERE"command_hall",
		"east"	: HERE"lpc_hall",
		"north" : HERE"work_hall"
	]) );
}
