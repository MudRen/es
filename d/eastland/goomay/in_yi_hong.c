#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set_short( "�ض�" );
        set_long(
@LONG
�����һ����ֵĵض������������ĵص��պý����͵����ף���ֻ
�е���Щͷ�裬ȴû�����ˣ����������һ��Ĵ��������ʹ�ǵ���
���Ҳ��ģ��һƬ���ȵ� ...������һ��������΢΢�����⣬�ͺ�����
Ұ�޵��۾�һ���������С��һ�㡣
LONG
        );
        
        set( "exits", ([ 
		"out" : Goomay"yi_hong",
        ]) );
        
        set( "objects", ([
                "roger" : Mob"roger",
        ]) );
        reset();
}
void init()
{
        if(this_player()) this_player()->set_explore("eastland#14");
}
