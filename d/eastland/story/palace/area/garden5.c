#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("�Ứ԰");
	set_long( @LONG
�������Ứ԰���Ứ԰�ڡ��컨������֦��Ҷ����׺��ɫ������������������
����⵴�����˴ӻ����߹���մ�������������ǻ��㾹Ҳ��𴦲�ͬ��������ܰϸ
ϸ��������Ƣ����ζ����ʮ��Ũ�ң���������΢������Ȼ�ġ����Ա�һ����ͤ����
�ⱦ��������Χ����һ�ģ����Ƹ�����еĽ����������һ�ӡ�

LONG
	);
        set("light",1);
        set("exits" , ([
               "west" : SPALACE"garden4",
               "east" : SPALACE"garden6"
        ]) );
        set("pre_exit_func",([
            "east":"can_pass"]));
        set("objects", ([
            "gardener1" : SPMOB"gardener1",
        ]) );
	reset();
}
int can_pass()
{
    object gardener;
    if ( !gardener=present("gardener",this_object()) ) return 0;
    if ( this_player()->query_attacker() ) {
      write(sprintf("\n%s������������˵��������С�ӣ�Ҫ���µ���ĵط�ȥ����\n\n",
      gardener->query("c_name")));
      return 1;  
    }
    return 0;
}