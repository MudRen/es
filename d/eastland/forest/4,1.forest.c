#include "forest.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("ɭ�ֵ��");
        set_long( @C_LONG_DESCRIPTION
����������ɭ�ֵ������ľ�ǳ���ïʢ�������ⶼ�޷����룬���Ҳ
�Եø������ɭ������������Χ��ȥ���㷢�ֺڰ���������˫�̡���˸����
����а���ע�����㣬Ҫ����Ϊ��Ѱ�Ҵ�˵�е����ޣ�˭Ҳ����Ը�⵽����
��ط����ġ�
C_LONG_DESCRIPTION
 );

        set( "exits", ([
                 "north"       : Forest"4,2.forest",
                 "east"        : Forest"5,1.forest",       
                 "west"        : Forest"3,1.forest",
            ]) );
                      
        set("objects", ([ 
                  "tiger#0" : FORMOB"tiger",
                  "tiger#1" : FORMOB"tiger",
            ]) );
            
        reset();    
}

void init()
{
        if (this_player()) this_player()->set_explore("eastland#8");
}
