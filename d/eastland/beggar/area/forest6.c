#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "forest1", "����" );
	set_long(@C_LONG
������һƬ�����͵�������,����ܰ���,��������ĺõط�����ɭ��һ������
һ���ƺ����ھ����ĺۼ���
C_LONG
	);
        set_outside("noden");
	set( "exits", ([
	        "southeast":DBEGGAR"forest5"
        ]) );
     reset();
}
void init()
{
    add_action("do_search","search");
}
int do_search(string arg)
{
    object obj;
    if ( !arg || arg != "hole" ){
        tell_object(this_player(),"������ʲ�ᶫ����\n");
        return 1;      
    }
    if ( !present("a white dog",this_object()) ){
        tell_object(this_player(),"������ʲ�ᶫ����\n");
        return 1;
    }      
    if ( this_object()->query_temp("be_searched") ){
        tell_object(this_player(),"�����ƺ��������ҹ��ˡ�\n");
        return 1;
    }
    this_object()->set_temp("be_searched",1);
    obj=new(DITEM"toad");
    obj->move(this_player());
    tell_object(this_player(),"��!���ҵ�һֻ������!!\n");    
    return 1;
}