#include <../takeda.h>
#include <conditions.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "ˮ����" );
	set_long(@C_LONG
������һ��С���ӵĵײ����ص��Ǽ�Ӳ��ʯ�ڣ����泤���˺���ˮ��ֲ��
�ڲ�Զ��ǰ����������һ������ƽ���(ladder)����ʯ���ƺ�����ͨ������
��һ������϶��һЩ΢����Ǹ���϶��͸��������Ҳ�����ͨ������ȥม�
C_LONG	
	);
        set( "exits", ([
                "out" : TROOM"lair/lair2"
        ]) );
        
        set( "objects", ([
                "sco1" : TMONSTER"scopio",
        ]) );
                set("c_item_desc",(["ladder":
                "һ�������ӵĴ�ʯͷ�������⻬ƽ���ı����������ƺ����� \n"
                "��Ȼ����Ʒ��Ҳ��\�������(climb)������ȥ����....\n"
                                                   ]));
        
        set("underwater",1);
        reset();
}
void init()
{
  UNDERWATER->apply_effect(this_player(),4,1);
  add_action("do_climb","climb");
}
int do_climb()
{
    if ( present("scorpion",this_object()) ) {
    write("��æ����ɱ��Ы���ٹ�ȥ��....\n");
    return 1;
    }
    write("���ε��ǿ���ʯǰ������������ȥ..........\n");
    this_player()->move_player(TROOM"lair/lair5","�㿴��"+this_player()->query("c_name")+"��ʯ�����˳�ȥ...\n");
    return 1;
}
int clean_up() { return 0; }
