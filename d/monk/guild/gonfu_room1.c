#include <mudlib.h>
inherit "/d/monk/guild/train_gonfu.c";
inherit ROOM;

void create()
{
        room::create();
        set_short("������\����\��");
        set_long( @LONG_DESCRIPTION
������������ר�Ž̵����ֲ�ͬ�˹�\������ѧ������\�����󲿷ݻ���������
�书\���Ŷ��������һЩʹ��ע��˵���뿴������(board)��
������ǰ��һ�ŷ��Ƶ���Ƥֽ (paper)������Ը����Լ�����ѧ����ѡ�����ܹ�
ѧϰ���书\��Ȼ���ڴ˴�ѵ��(train)���������Իص��޺��á� 
LONG_DESCRIPTION
        );
   
    set("c_item_desc",([
         "board":@BOOK
������\�������ָ�����ս���������˺��Ĺ�\��
ʹ�÷����� eungon [��\������]

1. ��ָ��Ѩ: ��ѨֹѪ
2. �˹�\�ƶ�: �����Ѩ��ѧ֪ʶ��������С���˹�\�����ڶ��رƳ�
3. ����: ��Ϊ�����ã�Ҳ��\������Ч��  

BOOK
        ]));         
        set( "no_monster", 1);
        set( "light", 1 );
        set( "exits", ([ 
                "west" : "/d/monk/guild/monk_guild",
				"east" : "/d/monk/guild/monk_hoard_room" ]) );
        set( "item_func", ([
                "paper": "view_catalog" ]) );

        // setup type of gonfus & name of gonfus.
        set_gonfu_type("heal");
        set_gonfus( ([
//              "gi-chi"  : ({ "heal-cycle",  5,   200 }),
                "bi-du"   : ({ "heal-cycle", 65,  7500 }),
                "lun-chi" : ({ "heal-cycle", 25,  2000 }),
                "pu-ty"   : ({ "heal-cycle", 50,  5000 }),
                "gun-in"  : ({ "heal-cycle", 85, 20000 }),
        ]) );
        reset();
}
