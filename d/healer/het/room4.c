#include <mudlib.h>
#include "wang.h"
inherit ROOM;

void create()
{
 	::create();
        set_short("�鷿");
	set_long(@C_LONG
�ⷿ������˵���鷿������˵������ҡ�����Ĵ󲿷ֱ�һ��ľ��ռȥ�ˡ�
��ͷ�и�С���ӣ������ķ��ı���ī����ûǬ����ߵ�����Ϸ���һЩ��ҽҩ��
����顣һ�ߵ�ǽ�Ϲ���һ������
C_LONG
);
	set("light", 1);
	set("exits",([
		"west" : WANG"room3",
	]));

	set("objects", ([
		"doctor" : WANG"mob/medic.c",
	]) );

	set("c_item_desc" , ([
		"painting" : "@@look_painting",
		"��" : "@@look_painting",
	]));

        set("search_desc",([
        	"painting":"@@search_painting",
        	"��" :"@@search_painting",
	]) );

	reset();
}
string look_painting()
{
	if ( (string) this_player()->query("class") == "healer" ) {
	return 
"�⻭�ı�Ե��Щĥ����, �������˳������������͡������и��ŵ���Ů, \n"
"������Ц�ĺܿ��ġ�������ϸһ�� ��, ���ĸ��̴��ﻹ������\n" ;
	} else {
	return 
"�⻭�ı�Ե��Щĥ����, �������˳������������͡������и��ŵ���Ů, \n"
"������Ц�ĺܿ��ġ���֪����λ��Ů�Ǻη����ˡ�\n" ;
	}
}
string search_painting()
{
	write(
	"�㷢��������������Ȼ�и�ͨ��, �������߹�ȥ����������ʲ�ᶫ����\n");	
	this_player()->move_player(WANG"room5","SNEAK",);
	return "";
}

