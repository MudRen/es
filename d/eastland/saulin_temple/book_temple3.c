//File: book_temple3.c �ؾ�¥���ܸ� 

#include "saulin_temple.h"

inherit ROOM;

void create()
{
       ::create();
       set_short( "�ؾ�¥�ܸ�" );
       set_long( @C_LONG_DESC
����ľ�ݣ�������һ��С��¥������������ܵ�С��Ҳ��\�����飬��������
��С���㶼���Կ����������ٲ������ķ��⣬������������������������
�书\���ţ��㿴����Щ�޼۱���(books)������С¹��ײ�������Ѿ������ȵ��ˣ�
���������ɻ�Ŀ����㡣
C_LONG_DESC
       );
       set("light",1);
       set("objects",([ "fire_monk":SAULIN_MONSTER"fire_monk" ]));
       set("exits",([
         "down" : SAULIN"book_temple2"
       ]));
       reset();
#include <replace_room.h>
}
void init()
{
        if (this_player()) this_player()->set_explore("eastland#31");
}
