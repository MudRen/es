#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "�����Ӫ" );
	set_long(
	"������ɽ���ϵ�һƬ�տ�ƽ�أ����������ɽ�������������Ӫ���ɺ�����\n"
	"����ָ�ӡ���ɽ��֮�����ܹ��İܹٱ��������½�������֮�⣬�����ӪҲ����\n"
	"��һ����Ҫ�����ء���Щ����(cannon)�������������±ߣ���̺���\�˴Ӵ�ʯ��\n"
	"���Ĺ��ǵĹ�����ء�\n"  
	);
	set_outside("eastland");
        set("c_item_desc",(["cannon":
"�������Ϻõ���ͭ���ɵľ��ͻ��ڣ�������Ĭ��˹�������ֵ����汬ը��������\n"
"�ڵ��ģ������пգ����������������᳤�����������\����ֵķ��š�\n"
            ]));        
        set( "exits", ([
                "down" : TROOM"yard1",
                "north" : TROOM"gate3" 
        ]) );
        set( "objects",([
                "ling":TMONSTER"lingchen",
                ]));
        reset();
}
int clean_up() { return 0; }