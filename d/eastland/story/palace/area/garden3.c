#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("��ʯС��");
	set_long( @LONG
��ʯС����������ʮ�ﳤ��ͨ������̳ɣ��������������Ծ��ǲ��컨������
Ϊ����֦�������滨֦��������һƬ��һ����ȥ��ֱ�������������ǣ����ѷ��衣
���������棬���������֦������Ҷ�������̺죬����ٳ�ף�����綷�����·�
�ơ�����������������ȡ�

LONG
	);
        set("light",1);
        set("exits" , ([
                "north" : SPALACE"garden1",
           "southeast" : SPALACE"garden4",
        ]) );
	reset();
}
