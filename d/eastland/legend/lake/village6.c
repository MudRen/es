#include "../legend.h"

inherit ROOM;

void create()
{
object kun;    
        ::create();
    set_short("�µ�����ͤ");
        set_long( 
@LONG
һ����ɫ���������ͤ��б�����ܣ��ṹ�����Ϊ���µ�������ͤ��������
ȡ�������ǽ������죬�ں��ڿ��ƶ�������ͤ��һ���ʯ������һ�����۶��ġ���
����ӳӳ��������ɫ��
LONG
    );
    set( "light",1);
    set("exits",([
          "out":LAKE"village4",
    ]) );
    kun = new(LMONSTER"pao_kun");
    kun->move(this_object());
                
    reset();
}
int clean_up()
{
    return 0;
}