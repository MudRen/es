#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("��������ͷ");
        set_long( @C_LONG_DESCRIPTION
��������վ�ں��������ͷ�ϣ���ʮ�һ���С���洬ɢ���ڸۿ��ڡ��㿴��
��\����������(net)������ͷ�ԱߵĿյأ����ϲ�Զ����һ�����г�(market)��
����ż����������������ŵ�ٶ���ͣ����������ľ������Щ��������ƽ�������
İ��������˾�ռ��ߣ���ĳ��ֲ�û������̫���˵�ע�⡣
C_LONG_DESCRIPTION
        );

        set_outside( "haiwei" );
        set( "light", 1 );
        set( "c_item_desc", ([ 
                "net" : @LONG_TEXT
��Щ������Ϊ����ʹ�ã��������涼��Ϊ��ˮ�Ľ�ʴ����������\��С�ף��ɴ�
Ҳ���Կ�������ľ�������ǳ��ڼ�
LONG_TEXT
, 
                "market" : @LONG_TEXT
���г������ϱ߲�Զ���������ǳ�����������ͻ��һ¨һ¨���ʵ�����˵�
�г�ȥ����
LONG_TEXT
 ]) );
    set("objects",([
        "mew1":"/d/eastland/haiwei/monster/mew",
        "mew2":"/d/eastland/haiwei/monster/mew"]));  
        set( "exits", ([ 
                "south" : "/d/eastland/haiwei/road_jetty" ]) );
        reset();
#include <replace_room.h>
}

void init()
{
        if( !find_object("/d/std/ocean/ship_iriah") )
                "/d/std/ocean/ship_iriah"->frog();
        if( !find_object("/d/std/ocean/ship_ta_tong") )
                "/d/std/ocean/ship_ta_tong"->frog();
}
