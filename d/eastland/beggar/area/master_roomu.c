#include "/d/eastland/beggar/dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "master_room", "�����Ʒ�������" );
	set_long(@C_LONG
�����ǡ����Ʒ��������Ķ�¥, ��������ϲ��õ������µ�;���ұߵ�ǽ����
��һ����ī��ɽˮ��, �������ǽ����һ��������ͷ���ϻ�Ƥ;�������������һ
�����ĺ�ɫ��̺,��̺���������������û�ľ���ɵ�����; ��̺�ľ�ͷ��һ��̫ʦ
��,������������һ�Ŵ����Ƥ;̫ʦ�������ǽ�Ϲ���������ʥ���ع���Ф��,��
�����Ը��ǹ�ƽ���ֳ��������µ����ܲ֡��Ա���һ��¥�ݿ���ͨ�����档
C_LONG
	);
	set("light",1);
	set( "exits", ([
                      "down":DBEGGAR"master_room.c"
	]) );
        set( "objects", ([
                      "master of beggar":DMONSTER"master.c",
                             "master Wu":DMONSTER"wu_master.c",         
                               "servant1":DMONSTER"servant.c",
                               "servant2":DMONSTER"servant.c" 
        ]) );
        set_reset(this_object(),21600);
}
void reset()
{
   set_reset(this_object(),21600);
   ::reset();
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