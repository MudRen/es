#include "/d/eastland/beggar/dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "hospital1", "ҩ�̶�¥" );
	set_long(@C_LONG
������ҩ�̵Ķ�¥, �ǡ�һ����ҽ Сѩ�ӡ�����ҽ�β����ĵط����������
������Ŀ�ľ��Ƿ��ڷ�������, ��Сѩ����ϰ��ĵ�ͭ��ģ��,�����ʾ��һ���
�ľ��������������ұ���һ��СС������, ��Ȼ�������Ҳ���,�������Ķ���
�����õ�ҽ�顣
C_LONG
	);
	set("light",1);
	set( "exits", ([
                      "down":DBEGGAR"hospital.c"
	]) );
     
        set( "objects", ([
                         "uki" : DMONSTER"uki.c",
                         "ahtu": DMONSTER"ahtu.c" 
                         ]) );
     reset();
}
void init()
{
    if ( this_player()->query("class") != "thief" )
        return ;
    if ( !this_player()->query_temp("hidding"))
        return ;
    if ( random(20) > 18 ) 
        return ;
    this_player()->delete_temp("hidding");
    call_out("recover",1,this_player());
}
void recover(object obj)
{
    obj->block_attack(6);
    obj->set_temp("msg_stop_attack",
        "( ��Ǳ��ʧ�ܣ�������ͻϮ��һ����æ���ң� )\n" );
}
