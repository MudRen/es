#include <mumar.h>
inherit ROOM;
 
void create()
{
 
        ::create();
        set_short("�����");
        set_long( @C_LONG_DESCRIPTION
����������صı��ţ���ΰ�Ľ����ṹ�ٴγ����������ǰ���򱱳��˹������
һƬ����ɳ����ɳ�Ļ�ɫ���硣������̽�ռҺ����˻����˼������ʱ�������Ƭã
ã�ĺ���֮�н�����˿��֮·��Ȼ��ȴ�и���ðʧ��ð�ռ����Ƕ����������������
�����Ϳ��Գ��أ����ϲ�Զ���ǽ̳���
C_LONG_DESCRIPTION
        );
        set( "light" ,1 );
        set( "exits", ([
                "south" : MUMAR "square05",
                "north" : MUMAR "north_gate"]) );
        set( "objects", ([
                "guard#1" : MOB "gate_guard",
                "guard#2" : MOB "gate_guard",
                 ]) );
 
        set("pre_exit_func",(["north":"go_north"]));
        reset();
}
 
int go_north()
{
        write("����ͼ���߳����ţ���һ��ɳĮ�籩���㴵�˻���\n��");
        return 0;
}
