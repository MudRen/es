#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
        set_short("��ɽ��");
	set_long( 
@LONG_DESCRIPTION
�����ɽ����ˣ��ڻ�ɽ�ҵĵر�֮�ϣ��������ǻ�ɽ�Һ͸�ʯ��ʯ�飬��վ��
��ɽ�ڣ����¿�ȥ����ɽ����������Ũ��ð������֪��ʱ�����ٱ�����������Ҳ���һ
���޴�ĵ���(statue)������ǰ���и�С��̳(altar)����̳���ƺ�������һ��Ѫ������
����һ�������ǰ����彫��Ʒ�׸���ɽ֮��ļ�̨��
LONG_DESCRIPTION
	);

set("item_desc",([
    "statue" : "����һ���޴�Ļ������ס�ڻ�ɽ�����İ���������ֻ�з�����Ѫ����ƽϢ����֮ŭ��\n",
    "altar" : "���̳�ϵ�������Ѫ������̨������һ��������ͼ��(symbol)���ڼ�̳���·���һ����ʾ��(board)��\n",
    "symbol" : "һ��������צ�Ļ������������������\n",
    "board" : "���ҷ��ף���ͻ�õ�������Ҫ�ġ�\n",
    ]));
set( "exits", ([
     "down" : ONEW"varea3"
     ]) );
set( "objects", ([
     "wwizard":OMONSTER"wwizard"
     ]) );
set_outside("eastland");
reset();
}

void init()
{
    add_action("do_touch","touch");
/*    add_action("do_jump","jump"); */
}

int do_touch(string arg)
{  
    if(!arg || arg!="symbol") return 0;

    write("�㿴��һ��Ũ�̽����Χ����Ũ��ɢȥ���㷢���Լ��ѵ�����һ���ط��ˡ�\n");
    this_player()->move_player(ONEW"wcave1","SNEAK");
    tell_room(this_object(),"�㿴��һ��Ũ�̽�"+this_player()->query("c_name")+"��Χ��������Ũ��ɢȥ�����ѿ�����"+this_player()->query("c_name")+"����Ӱ\n",this_player());
    return 1;
}

int do_jump()
{
    write(
          "������岻�����µ�����Ķ���ֻ����������������Ϊһ��������\n"+
          "˵�ɲ��ɣ��պ�ײ����һ͹������֦�ϣ�ž��һ������֦���˵�\n"+
          "Ҳ�����׹������һ�裬����ں��Ļ�ɽ���ϡ�\n");
    this_player()->move_player( ONEW"icave1.c","SNEAK" );
    tell_room(this_object(),"�㿴��"+this_player()->query("c_name")+ "���Լ����ɼ�Ʒ������ȥ.\n",this_player());
    return 1;
}
