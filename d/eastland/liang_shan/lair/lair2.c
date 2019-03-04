#include <../takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "��խͨ��" );
	set_long(@C_LONG
�������ɽ���е���խͨ������ʪ����������������������һ��˵������
�Ķ�����ζ������ϸ�ķ���������ùζ�������š������ζ���������С��帯
�ܵ�ζ��������һ��޴����赵�ס�����ͨ����������һ����ˮ�ĳ���(pool)��
���ӵ����������һЩ���죬Ҳ�����Ǳ��ȥ����?
C_LONG	
	);
         set("c_item_desc",(["pool":
         "һ����ֵ�С���ӣ�����Ķ���������ˮ������һ����İ� \n"
         "��ɫҺ�壬�ò�����Ѫ��??\n"
         ,"wall":
         "���ǽ�������ֵֹģ��������ڲ�ͣ������ζ���...\n"
             ]));
        
        
        
        set( "exits", ([
                "north" : TROOM"lair/lair3",
                "south" : TROOM"lair/lair1"
        ]) );
        set( "exit_suppress", ({
                 "north" }) );
                 
        set("pre_exit_func",(["north":"check_wall"]));
        set( "objects", ([
                "sco1" : TMONSTER"scopio",
                "sco2" : TMONSTER"scopio"
        ]) );
        reset();
}
void init()
{
add_action("suicide","dive");
}
int check_wall()
{
   write("���������������߿����ţ�ԭ������ǽ�ǻ�Ӱ��....\n");
   return 0;
}   
int suicide()
{
    if ( this_player()->query_skill("swimming") < 30 ) {
    write("����Ľ����������ˮ�أ���ͻȻ��ʼ���������Ӿ����....\n");
    return 1;
    }
    if ( present("scorpion",this_object()) ) {
    write("��æ����ɱ��Ы���ٹ�ȥ��....\n");
    return 1;
    }
    write("�����������ĳ������������ȥ.......\n");
    this_player()->move_player(TROOM"lair/lair4","ͨ.......һ����ͻȻ���˽���\n");
    return 1;
}
int clean_up() { return 0; }
