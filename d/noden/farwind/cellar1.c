//#pragma save_binary
 
#include "farwind.h"
 
inherit ROOM;
 
void create()
{
        ::create();
        set_short( "�ƽ�" );
        set_long(@C_LONG
������һ��ƽѣ���ʹ����һƬ������ֲ�����ָ����Ҳ���Ժ���
����ȷ����㣬��ΪŨ���ľ�ζ���������������������һ�������
������(ladder)���ƺ����뿪����Ψһ��·��
C_LONG
        );
        set( "item_desc", ([
        "ladder" : "��������������������⣬�ƺ����������Ҳ��������\n"
                   "����ƽѡ����ӵ��Ա���һ����(hole)����֪��������\n"
                                        "ʲ�᣿\n",
        "hole" : "�������Ȼ���󣬵�������ǿ�������ȥ(enter)��\n"
        ]) );
        set( "exits", ([
                "up" : FARWIND"smithy"
        ]) );
        set( "pre_exit_func", ([
                "up" : "check_ladder"
        ]) );
        set( "objects", ([
                "rat 2" : FARWIND"monster/rat"
        ]) );
        reset();
}
 
void init()
{
        if( this_player()) this_player()->set_explore("noden#1");
        add_action( "enter_hole", "enter" );
}
 
int check_ladder()
{
        object smithy;
 
        smithy = find_object( FARWIND"smithy" );
        if( !smithy || !smithy->query("item_desc/ladder") ) {
                write(
                "���������Ӷ��ˣ����������ƺ���ʲ������ѹס�ˣ����޷���ȥ��\n"
                );
                return 1;
        }
        return 0;
}
 
 
int enter_hole(string arg)
{
        string name;
        if( !arg || arg!="hole" )
                return notify_fail("����ʲ�᣿\n");
        name=(string)this_player()->query("c_name");
        this_player()->move_player(FARWIND"cellar2",
                name+"���������Ե�һ��С����\n",
                name+"��һ�������������˳�����\n"
         );
        return 1;
}
 
