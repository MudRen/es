#include <almuhara.h>

inherit ROOM;
inherit DOORS;
void create()
{
	::create();
	set_short("����С��");
	set_long( 
@C_LONG_DESCRIPTION
��������һ�����µ�С����ǰ��С�����������˸�ʽ�������滨��ܣ�����м�ֻ����
�����д�����衣С������һ�ھ�(well)��������һƬ�յأ�����ϡϡɢɢ�ز���ʮ��֧��
ͨ����ͣ�ȴ����ԼԼ�й����������ڿյ��ϣ����뻹�ǲ�Ҫ��ȥ�ĺá����ŵ���������ֻ
����������ʯʨ�ӡ������и��Ҷ�д�� ---- �� ��ң�� ����
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"west"  : TOMB"/lin5",
		"enter"  : TOMB"/house2"  ]) );
	create_door( "enter","out",
		(["keyword" : ({"door"}),
		  "name"    : "red door",
		  "c_name"  : "����",
		  "c_desc"  : "һ�Ⱥ�ɫ���š�",
		  "status"  : "closed",
		  ]) );
	add( "c_item_desc", ([
		"well" :@WELL_DESC
һ������׵ľ����ƺ���ʲ��������������
WELL_DESC
	]) );
	reset();	
}

