#include "../../story.h"

inherit SPALACE"RR";
inherit DOORS;
void create()
{
        ::create();
	set_short("�춼����");
	set_long( @LONG
������֮�����춼�Ĵ��ſڣ����ſ�˳߸����ɣ�ͨ���������Ƴɣ���������
·�仯��ǧ���������£��Ѵ˵س��еĸ�������ׯ�ϡ��Ա�һ������ף����ӵ���
һ������С·���������춼�Ĵ�
LONG
	);
	set("light",1);
        set( "exits", ([
            "down" : SPALACE"plain3",
            "east" : SPALACE"w1"
        ]) );
        set( "objects", ([
           "soldier1" : SPMOB"soldier1",
           "soldier2" : SPMOB"soldier1",
           "soldier3" : SPMOB"soldier1",
            "general" : SPMOB"soldier2",
        ]) );
        create_door( "east","west" ,([
             "keyword" : ({ "jade door", "door" }),
             "name" : "jade door",
             "c_name" : "����",
             "c_desc" : "һ���������Ĵ��ţ����������������ȸ����\n",
             "status" : "closed"
        ]) );
	reset();
}
