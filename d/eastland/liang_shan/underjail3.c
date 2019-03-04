#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "��������϶" );
	set_long(
	"������ɽ����Ȼ���ɵ���϶�����Խ��ȵ�ɽ�ʹ����һ��͸�������ĸо���\n"
	"һ��������������ͷ�����£���Ȼ��һ������̾����Ȼ�Ĺ��񹤣���һ\n"
	"������ȴ�ְ�����������ʹ���ͨ�и������ѡ��ټ��ϵ���ʪ�����ģ����\n"
	"���С�ĵ�ǰ�����⻬������϶�ľ�ͷ�и�С������������뿪�˴���\n"
	);
        set("c_item_desc",(["hole":
        "һ��С��������ͨ������ȥ����ʹ�㲻̫�ֵĻ���Ӧ�ÿ��Լ�(squeeze)\n"
        "�ĳ�ȥ����������������ģ�������޷���֪����Ļ�����Ρ� \n"
                ]));
        set( "exits", ([
                   "squeeze" : TROOM"underjail4",
                   "northwest" : TROOM"underjail2"
                   ]));
        set("exit_suppress", ({ "squeeze" }) );                 
        set("pre_exit_func",([
            "squeeze":"pass_hole",
                ]) );
        reset();
}
int pass_hole()
{
    write("���ͷ���С������ѽ��ѽ����춸��㼷��ȥ��....\n");
    write("����һ��....�����ص�ˤ�ڵ���\n");
    this_player()->receive_damage(10);
    return 0;
}
int clean_up() { return 0; }