#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("����");
	set_long( @LONG
�����ǡ������������  ��󡹾�ס��С�ݡ�������ľ�Ƴɵ����ӡ����Ӻ�һ
�Ŵ����Լ�һ¨¨װ�����ղ�������ɹǬ�����ѵĴ������ӡ�ľ�����з���������
���ǡ���󡹱���ѧϰħ�����ĵá�С������ʰ��һ����Ⱦ��ֻ�����Ǽ򵥵İ���
��
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	      "west" : SAREA"village2" 
        ]) );
        set("no_embattle",1);
        set("objects", ([
             "elder" : SMOB"elder1"
        ]) );
	reset();
}
void init()
{
    if ( this_player()->query("class") != "thief" )
        return ;
    if ( !this_player()->query_temp("hidding"))
        return ;
    if ( (int)random(3) > 1 )
        return ;
    this_player()->delete_temp("hidding");
        call_out("back",1,this_player());
}
void back(object obj)
{
    obj->block_attack(6);
    obj->set_temp("msg_stop_attack",
          "( ��Ǳ��ʧ�ܣ�������ͻϮ��һ����æ���ң� )\n" );
}