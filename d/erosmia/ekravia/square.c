#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("���Ĺ㳡");
	set_long(@Long
����������������ά���������ش�, ������Ĺ���С������������
�ķ�������ڴ˽���, �γ�һ����㳡����\���С�����������������ｻ
��������Ʒ��ʳ������������˻���ħ��ʦ�ڴ�����, ��ʱ���������
��Ц����
    �㳡�ı������򳤵Ĺ���, Ҳ����������������ĵ�һ��������
Long
);
	set("exits", ([
		"south"		: HERE"maple_street4",
		"east"		: HERE"tinker_way3",
		"west"		: HERE"tinker_way4",
		]));
	set( "objects", ([
		"magician"	: MOB"magician",
		"vendor"	: "/obj/vendor",
		]) );
	reset();
}
