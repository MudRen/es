#include <mumar.h>
inherit ROOM;
 
int daoist = 1;
void create()
{
        ::create();
        set_short("������ϳ���");
        set_long( @C_LONG_DESCRIPTION
����������һ����ΰ�Ĺ��ſڣ������Ͽ���������ΰ�Ĵ��֡�����ء�������
�Ƕ���������ر�������Ҫ�ݵ㣬�����פ���ر����أ��������Թ�����ÿͶ�Ҫ
����������̲����ͨ�������ſ�����޴����������������ݵ��ػ����������
��������Ļ�Ұ���������ٹ�ʱ��ս���Ŀݹǣ���˵�����ϳ�����������ɱ������
ս������
C_LONG_DESCRIPTION
        );
 
        set_outside( "eastland" );
        set( "exits", ([
                "north" : MUMAR"road1",
                "south" : "/d/eastland/12,1.east" ]) );
set( "search_desc", ([ "here" : "@@search_here" ]) );
        reset();
}
string search_here()
{
        object obj;
        if( !daoist || present("daoist", this_object()) ) return
                "�㼸��������ĵظ��������ˣ���û�з����κζ�����\n";
        obj = new( MOB"daoist" );
        obj->move( this_object() );
        daoist = 0;
        return "�������ܵĲݴ���������������Ȼ��һֻ�Ű���һ��...\n"; }
