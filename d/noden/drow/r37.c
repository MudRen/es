#include "iigima.h"

inherit ROOM;

void create()
{

        ::create();
        set_short( "tunnel","����ͨ��");
        set_long(

@C_LONG
ͨ������֮�ţ�����һƬ���ߣ����ܽ�������֩���������ϵ�����
�ҳ����ƺ��ܾ�û���������ˣ��ף����Ϻ����м�ƬǬ�����Ƥ(skin)��
�������ע�⡣
C_LONG
        );
        set( "exits", ([                     
                     "northwest": DROW"r36",
                     "southwest": DROW"r01",
        ]) );
       set("c_item_desc",(["skin":
@C_LONG
��ЩǬ�ݵ���Ƥ�Ѿ��ѻ��˺���һ���ˣ�������������ֳ�˲���
���ߣ��е���Ƥ������ģ����������߸��ɹ�Ƥ�ɡ�
C_LONG
]));
}
