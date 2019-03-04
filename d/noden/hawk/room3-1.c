#include "hawk.h" 

inherit ROOM;
inherit DOORS;

void create()
{
        ::create();
        set_short("����������¥");
        set("light",1);
        set_long( @LONG_DESCRIPTION
���������֮���������ģ�װ諵ĸ����ûʣ��ɱ��ֳ����������һ�ȵĽ�
��������ǽ�Ϲ��������������������Ф��(photos)����������ͨ�����ϵİ칫
�ң����ϣ���������������칫�ĵط���
LONG_DESCRIPTION
        );
        set( "exits", ([
                "north" : HAWK"room3-2",
                "west" : HAWK"room3-3",
                "down" : HAWK"room2-14",
                "south" : HAWK"room3-6",
                "east" : HAWK"room3-7",
                        ]) );
        set( "objects",([
                "prayer" : MOB"god2",
                        ]) );
        create_door("west","east",([
                "keyword":({"black door","door"}),
                "status":"closed",
                "c_desc":"һ����ɫ����",
                "c_name":"������",
                "name":"black jade door",
                "desc":"a black jade door",
                        ]) );

        create_door("east","west",([
                "keyword":({"white door","door"}),
                "status":"closed",
                "c_desc":"һ����ɫ����",
                "c_name":"������",
                "name":"white jade door",
                "desc":"a white jade door",
                        ]) );
        set("c_item_desc",([
		"photos":" �㿴��һ��������������Ӣ�۵�Ф��һ�����������ݡ�\n",
                        ]) );
    reset();
}//end of creat


int clean_up()
{

      return 0;
}

