// ��ҩʦ��é�����С�㳡
#include <mudlib.h>
#include "wang.h"
inherit ROOM;
inherit DOORS;

void create()
{
 	::create();
        set_short("�յ�");
	set_long(@C_LONG
����ԭ�����Ӳݴ����ĵط��������Ѿ������һƬ�յ��ˡ���������Щ
��ɹǬ�Ĳ�ҩ, �յص���һ�߶���һЩ��, ����һ��������ǰ���и�Сé�ݡ�
C_LONG
);
	set("light", 1);
	set("exits",([
		"north" : WANG"room1",
		"south" : WANG"room3", 
		"enter" : WANG"room6",
	]));

	create_door("enter","out",([
		"keyword" : ({"iron door","door"}),
		"name" : "iron door",
		"c_name" : "����",
		"c_desc" : "����һ�Ⱥ��ص�����, �����и���С��С����",
		"status" : "locked",
		"lock"	: "WANG",
	]) );
		
	reset();
}


