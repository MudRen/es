// File: /d/eastland/haiwei/mroad1.c
// Generated by Roommaker Sat Jan 22 06:54:16 1994

#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("��������");
        set_long( @C_LONG_DESCRIPTION
�����������ں�����Ĵ���ϣ������Ǻ��������ĵ�·�ڣ��ϱ������г�������
������û��·��ȥ�����߲�Զ�����Ǻ�����һЩש����ɢ����·�ԣ�Ϊ�˵ֵ����磬
��Щ���Ӷ�����������һ���ŵ���ľ��������Ĵ�������������ȥ��
C_LONG_DESCRIPTION
        );

        set_outside( "haiwei" );
        set( "light", 1 );
        set( "exits", ([ 
                "west" : "/d/eastland/haiwei/mroad2", 
                "east" : "/d/eastland/haiwei/road_cross" ]) );
        set( "objects", ([ 
                "beggar" : "/d/eastland/haiwei/monster/beggar" ]) );
        reset();
#include <replace_room.h>
}