#include <mudlib.h>
#include "wang.h"
inherit ROOM;
inherit DOORS;
create()
{
	::create();
	set_short("����");
	set_long(@C_LONG
����һ������������, ���ϵ�������Ѫ����һЩ��ȱ��ʬ��,
������ŨŨ��Ѫ��ζ, �������ƺ���˫�۾�������, �㲻������������
C_LONG
	);
	set("exits",([
		"out" : WANG"room2",
	]));
        create_door("out","enter",([
                "keyword" : ({"iron door","door"}),
                "name" : "iron door",
                "c_name" : "����",
                "c_desc" : "����һ�Ⱥ��ص�����, �����и���С��С����",
                "status" : "locked",
		"lock"	: "WANG"
        ]) );
	reset();
}
