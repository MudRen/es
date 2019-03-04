
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    set_short("The road of the dwarf village","���˴����С·");
    set_long(@Long
Long
,@CLong
��Ŀǰλ춰��˵Ĵ�ׯ�Ļ�ׯ��·��,���������ǳ���ƽ���������,�з���һ����
����Դ.�����Ѿ�����û��ս����,�����ǵ�ͯ�꼸���ڴ˶ɹ�. ���ߵĽ��������ڰ���
���￴�����,�������Ľ���,�����ƺ��й�ħ���赲�����.
CLong
    );
    set("exits",([
                "west":Deathland"/village/vr7",
                "north":Deathland"/village/v15",
                "south":Deathland"/village/v13",
             ]));
    set("pre_exit_func",([
                "west":"to_pass",
                ]) );
    set("objects",([
        "bard":Monster"/bard02",
         ]) );
    ::reset();
}

int to_pass()
{
   if ( !(this_player()->query_temp("deathland_magicwall")) ) {
     write("һ��ħ��ǽ�赲ס���ȥ��.\n");
     return 1;
     }
   else {
     write("��������������һ�����������,�����׵�ͨ��ħ��ǽ.\n");
     return 0;
     }   
}
