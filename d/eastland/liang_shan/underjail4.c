#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "�����ϵ�ƽ̨" );
	set_long(
	"������վ�ڸ߸ߵ�������ͻ����һ��Сƽ̨�ϣ������Ĵ����ب����Ľ��£���ˮ\n"
	"���򶫷����ϱ�����ȥ����׳�۵ľ�������ĸж���������飬ʹ����������Ŀǰ\n"
	"��������������ϡ�\n"
	);
        set("c_item_desc",(["up":
                "�Ϸ�������߸ߣ�������������Ǹ�����������赺ܹ⻬����Ӧ����������ȥ��\n"
                "����ȥ��ʮ�ߣ���������¶���\n",
                            "lake":
                "�����Ĵ��������ϼε����һ�����ʵ�����...\n",            
                            "down":
                "�㵽�±�̽ͷ��������....�øߣ��������ǲ�������������ȥ��\n"
                "����ĺ�����һ������������ɫ��ʹ����һ�ֻ�ѣ�ĸо������\n"
                "�����˻�ȥ��\n"            
                ]));
        set_outside("eastland");
        reset();
}
void init()
{
add_action("suicide","jump");
}
int suicide(string arg)
{
    if ( !arg || arg != "down") return 0;
    write("���ߵ��±ߣ�����������ȥ....������ǿ�紵��������ԣ�ǿ��ķ�ѹ\n");
    write("ʹ����ݵ�ʧȥ��ʶ��ֱ����о�......\n");
    this_player()->receive_damage(15);
    this_player()->move_player(TROOM"lake/underwater1","ͨ.......һ����ͻȻ�������\n");
    return 1;
}
int clean_up() { return 0; }