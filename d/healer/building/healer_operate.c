#include <mudlib.h>

inherit "/d/healer/building/study" ;
inherit ROOM;

void create()
{
	::create();
    set_short("������");
	set_long(@C_LONG_DESCRIPTION
��������ҽ�߹������Ժ��ĵط�, ��Ϊ�������ҽ�߾�������, ��������
�Ҵӹ��Ź����˻���, �������￴�������Ƚ�������̨, ��Ӱ��, �ԱߵĹ���
������ķ�����������ֹѪǯ�������ر����߼�Ӧ��ҩƷ, ����������ﶯ��
��,���ųɹ��Ļ���һ������Ұ��Ҫ�ߵĶ��ˡ�
C_LONG_DESCRIPTION
	);

	set( "light", 1 );

	set( "exits", ([ 
		"north" : "/d/healer/building/healer_guild" 
		]) );
	set( "op_room",1);	
	reset();
}

void init()
{
    add_action("do_search", "search");
    add_action("do_sneak", "sneak");
}

int do_search()
{
    write("ǽ���ƺ��и������������� (sneak) ��ȥ��\n");
    return 1;
}

int do_sneak()
{
    if (this_player()->query("class") != "healer" || this_player()->query("alignment") > 0)
        return notify_fail("ͻȻ�и�������߻��������ò������Ĵ�С����\n");

    write("�����������������ҽ���鷿��\n");
    this_player()->move("/d/healer/building/healer_troom");
    return 1;
}
