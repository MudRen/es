#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("����·");
        set_long( 
@LONG
�����������ĵ�·�ϣ�ӭ����������һ��ŨŨ���ȳ�ζ���ڵ��ϣ��ݺύ��
��Ѫˮ��Ǭ��С�ӣ�һ���Ų�Ӭ��������춸��õ������ϣ���ʱ�������˵�������
�ް���������գ������Ŵغ���һֻֻ����������צ��Ұ�ޣ�Ұ������ݺݵص���
�㣬���������˵���������ɣ������ɣ��ҵ�ʳ��������м�é�ݣ����Ͷ�����
���г���
LONG);
    set( "exits", ([
         "south":LAKE"village17"
    ]) );
    set("objects", ([
       "merchant#1":LMONSTER"merchant",
       "merchant#2":LMONSTER"merchant",
       "merchant#3":LMONSTER"merchant",
    ]) );
    ::reset();
}
void init()
{
   add_action("do_enter","enter");
}
int do_enter(string arg)
{
   if ( !arg || arg!="house" )
       return notify_fail("��Ҫ��������?\n");
   this_player()->move_player(LAKE"house18",({
       "%s������һ��Сé�ݡ�\n",
       "%s���������˽���.\n"}),"");
   return 1;
}