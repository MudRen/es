#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("��Ѩ");
	set_long(@LONG
����һ��͸��Щ��΢���ߵ�������Ѩ�������洵�����ķ��ڵ��Ϸ�����������
�����������ڿ��У������������ڶ����㳰Ц���ҷ��������Ц�����������ĸо�
����������ë���Ȼ�亹ֱ������Ȼ����֪�����ߵ�ʲ�ᶫ������ͷһ������Ȼ��
һ�Ѱ׹ǣ������ⲻ�Ǹ����Ƶĵط����㻹�ǿ��뿪����Ϊ��ף�����ŵ��¡�
���ģ��ţ�ԭ���Ǵ���ߵ�ǽ�ڵ�������Щ��Ѫˮ���������淢�Եÿֲ���
LONG
	);
	set("exits", ([
           "east" : SAREA"vhole1"
        ]) );
        set("objects", ([
          "bat#1" : SMOB"bat1",
          "bat#2" : SMOB"bat1",
          "bat#3" : SMOB"bat2",
          "bat#4" : SMOB"bat1",
          "bat#5" : SMOB"bat2",
        ]) );
        set( "c_item_desc", ([
          "crack" : "һ��ʮ�����ѷ죬�ƺ����Լ�(squeeze)��ȥ��\n"
        ]) );
	reset();
}
void init()
{
    add_action("do_auction","auction");
    add_action("do_search","search");
    add_action("do_squeeze","squeeze");
}
int do_squeeze(string arg)
{
    if ( !arg || arg!="crack" )
       return notify_fail("��������Ӽ�������ȥ��\n");
    write("������Ӽ������ǽ�ڵ�һ���ѷ��С�\n");
    this_player()->move_player(SAREA"waterfall1",({
       "%s�����Ӽ�������һ���ѷ��С�\n",
       "%s���ѷ��������˽���.\n"}),"");
    return 1;
}
int do_search(string arg)
{
    write("�㷢������м����ѷ�(crack)��ԭ�����ϵ�Ѫˮ�Ǵ��������ģ�\n");
    return 1;
}    
int do_auction(string arg)
{
    if ( !query("have_vampire") ) return 0;
        write("��������������ʹ�����޷�������������\n");
    return 1;
}
int clean_up()
{
    return 0;
}