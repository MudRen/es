#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("��ʯС��");
	set_long( @LONG
��֪�������Ѿ��ߵ�����ʯС���ľ�ͷ��С��ͨ������̳ɣ���������������
���ǲ��컨������Ϊ����֦�������滨֦��������һƬ��һ����ȥ��ֱ����������
���ǣ����ѷ��衣С�����߾����Ứ԰�ˡ�

LONG
	);
        set("light",1);
        set("exits" , ([
           "northwest" : SPALACE"garden3",
                "east" : SPALACE"garden5",
        ]) );
        set("pre_exit_func",([
           "east":"can_pass"]));
        reset();
}
int can_pass()
{
    if ( this_player()->query("palace_war") ) return 1;
    return 0;
}