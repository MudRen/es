#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "�г�" );
        set_long(
@LONG
����һ���г�������������������䣬���ֵ��˳�������Ϣ���γ�
һƬ���ַǷ��ľ���ͬʱ����Ҳ�ǹ�÷��Ů����Ҫ��Ϣ��Դ��ֻҪ
����·�Դ���һʱ���̣���֤����������������ֵֹĴ�С���£�����
�ж��䳤���Σ�գ��Ϸ���һ����ʯ���������ı���һ����ȥ������
�Ұ����ƶ��ߣ��Ӳ�Ұ�������ܵķ�������������Ӧ���Ǳ���ľ���
ַ��
LONG
        );
        
        set( "exits", ([ 
                "south" : Goomay"row21",
		"north" : Goomay"ruin1",
        ]) );
        
        set( "objects", ([
                "woman1" : Mob"woman",
                "woman2" : Mob"woman",
                "merchant" : Mob"merchant",
        ]) );
        set("exit_suppress", ({ "north" }) );
set("pre_exit_func",([
    "north":"to_north",
    ]) );
        reset();
}
int to_north()
{
    write("�㴩��ӵ������Ⱥ�������˻������ݵķ���.\n");
    return 0;
}

