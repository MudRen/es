#include <mudlib.h>
#include "wang.h"
inherit ROOM;

void create()
{
 	::create();
        set_short("é��");
	set_long(@C_LONG
һ�߽������ӣ����ŵ�һ��ŨŨ��ҩζ���е���ġ������и�����ҩ�õ�
���ߣ�ʲ������¯��ҩ����ҩ�ƣ�Ӧ�о��С�ǽ�Ϲ���һЩ����ֵֹĶ�����
����������ɹ����ҩ�ġ�������һ���и����ӣ�������ЩСС���ߡ�
C_LONG
);
	set("light", 1);
	set("exits",([
		"north" : WANG"room2.c",
		"east" :  WANG"room4" // �鷿
	]));

	set("objects", ([
		"boy"  : WANG_MOB"boy02.c",
	]) );

	set( "c_item_desc" , ([
		"table" : "���ϰ���Щ�״�����ҩ�����в����̵Ĺ���������ʹ�ù�һ��ʱ���ˡ�\n",
		"oven"  : "һ��С�ɵ�����¯��¯�������ģ�������������ɶ��ҩ\n"
			  "˵������̫���Ͼ���ɶ����ҩ���㲻���е���档\n",
	]));

	set( "search_desc", ([
		"oven" :    "@@search_oven",
		"����¯" :  "@@search_oven",
		"¯" :      "@@search_oven",
	]));
	reset();
}

string search_oven()
{
		return "��¯��̫���ˣ��㲻�Ҵ�������\n";
}


