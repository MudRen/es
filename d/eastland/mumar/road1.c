#include <mumar.h>
inherit ROOM;
 
void create()
{
        ::create();
        set_short("����ͨ��");
        set_long( @C_LONG_DESCRIPTION
���߽�����������ŵ�ͨ�������ߵı���������������ȼ�����Ļ�棬�յ���Ӱ
�ڵ����һΡ��Թ�������������һֱ�Ƕ�����½�ϱ���ͨ��Ψһ�׵���Ҳ�Ƕ�����
���Կ����е���Ҫ�ݵ㣻��ˣ��������εĳ��ű���Ƴɿ���ͬʱ������ʮ������
���������֮ͨ�㡣���������ң������һƬ���Ľ̳��ľ�ͷ����һ��ͬ����ģ
�ĳ��ţ������ǽ�����е�ʯ�š�
C_LONG_DESCRIPTION
        );
 
        set( "light", 1 );
        set( "exits", ([
                "south" : MUMAR"gate",
                "north" : MUMAR"square02",
                "west" : MUMAR"ladder01"
             ]));
        set( "objects", ([
                "guard#1" : MOB"gate_guard",
                "guard#2" : MOB"gate_guard" ]) );
        reset();
}
