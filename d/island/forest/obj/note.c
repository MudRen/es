#include <mudlib.h>

inherit OBJECT;

void create()
{
    set_name("Explored Note","̽�ձʼǱ�");
    add("id",({"note"}) );
    set_short("̽�ձʼǱ�");
    set_long(@C_LONG
    ������˹�ĸ��ס��Ϻ�����˹����һ���о�����¼��������ɵ��ʼǣ�
������ϸ�ļ�¼�˸�����̽���ĵã�ƽ��һ������Я��������������衣 
C_LONG
            );
    set("unit","��");
    set("weight",5);
    set("useless",1);
	set("value",({ 1,"silver" }) );
}
 
void init()
{   
    add_action("do_read","read");
} 

int do_read(string str)
{
    if( !str || !id(str) ) 
    return notify_fail("��Ҫ��ʲ�᣿\n");
    this_player()->more("/d/island/forest/daemons/contents");
    this_player()->set_explore("island#1");
    return 1;
} 
